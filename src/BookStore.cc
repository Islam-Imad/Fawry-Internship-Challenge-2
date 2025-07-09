#include "BookStore.h"
#include <iostream>

void BookStore::subscribe(EventType eventType, std::shared_ptr<Subscriber> subscriber)
{
    subscribers[eventType].push_back(subscriber);
}

void BookStore::unsubscribe(EventType eventType, std::shared_ptr<Subscriber> subscriber)
{
    auto &subs = subscribers[eventType];
    auto subscriberIt = std::find(subs.begin(), subs.end(), subscriber);
    if (subscriberIt != subs.end())
    {
        subs.erase(subscriberIt);
    }
}

void BookStore::notifySubscribers(EventType eventType, const std::string &message)
{
    auto it = subscribers.find(eventType);
    if (it != subscribers.end())
    {
        for (const auto &subscriber : it->second)
        {
            subscriber->notify(message);
        }
    }
}

void BookStore::sendPaperBook(const std::string &address, const std::string &ISBN)
{
    std::string message = "Sending paper book with ISBN: " + ISBN + " to address: " + address;
    notifySubscribers(SendingPaperBook, message);
}

void BookStore::sendEBook(const std::string &email, const std::string &ISBN)
{
    std::string message = "Sending eBook with ISBN: " + ISBN + " to email: " + email;
    notifySubscribers(SendingEBook, message);
}

void BookStore::addBook(const Book &book)
{
    books.push_back(book);
}

void BookStore::removeBook(const std::string &ISBN)
{
    int book_idx = -1;
    int current_idx = 0;
    std::shared_ptr<GlobalIdentifierProperty> gip;
    for (auto &current_book : books)
    {
        gip = pmanager.getGlobalIdentifierProperty(current_book.getProperty(Property::GlobalIdentifier));
        if (gip && gip->getGlobalIdentifier() == ISBN)
        {
            book_idx = current_idx;
            break;
        }
        current_idx++;
    }
    if (book_idx != -1)
    {
        removeBookByIndex(book_idx);
    }
}

void BookStore::removeOutDatedBooks(const std::string &date)
{
    std::vector<std::string> ISBNS;
    std::shared_ptr<DateProperty> date_property;
    std::shared_ptr<GlobalIdentifierProperty> gip;
    for (const auto &book : books)
    {
        date_property = pmanager.getDateProperty(book.getProperty(Property::Date));
        gip = pmanager.getGlobalIdentifierProperty(book.getProperty(Property::GlobalIdentifier));
        if (date_property->getDate() < date)
        {
            ISBNS.push_back(gip->getGlobalIdentifier());
        }
    }
    for (const auto &ISBN : ISBNS)
    {
        removeBook(ISBN);
    }
}

std::shared_ptr<Book> BookStore::getBook(const std::string &ISBN)
{
    for (const auto &book : books)
    {
        auto gip = pmanager.getGlobalIdentifierProperty(book.getProperty(Property::GlobalIdentifier));
        if (gip && gip->getGlobalIdentifier() == ISBN)
        {
            return std::make_shared<Book>(book);
        }
    }
    return nullptr; // Return nullptr if the book is not found
}

void BookStore::buyBook(const std::string &ISBN, const std::string &email, const std::string &address)
{
    auto book = getBook(ISBN);
    if (book)
    {
        auto quantity = pmanager.getQuantityProperty(book->getProperty(Property::Quantity));
        if (quantity && quantity->getQuantity() > 0)
        {
            quantity->setQuantity(quantity->getQuantity() - 1);
            std::cout << "Book is send successfuly :)\n";
            sendPaperBook(address, ISBN);
            sendEBook(email, ISBN);
        }
        else
        {
            std::cout << "Book is out of stock." << std::endl;
            return;
        }
    }
}

void BookStore::printBooks()
{
    std::shared_ptr<GlobalIdentifierProperty> gip; 
    std::shared_ptr<DateProperty> dp;
    for (auto const &book : books)
    {
        gip = pmanager.getGlobalIdentifierProperty(book.getProperty(GlobalIdentifier));
        dp = pmanager.getDateProperty(book.getProperty(Date));
        std::cout << book.getName() << ' ' << book.getPrice() << ' ' << gip->getGlobalIdentifier() << ' ' << dp->getDate() << '\n';
    }
}