#include <memory>
#include <map>
#include <vector>
#include <algorithm>
#include "subscribers.h"
#include "EventType.h"
#include "Product.h"

#ifndef BOOKSTORE_H
#define BOOKSTORE_H

class BookStore
{
    std::map<EventType, std::vector<std::shared_ptr<Subscriber>>> subscribers;
    std::vector<Book> books;
    ProductManager pmanager;

    void removeBookByIndex(int index)
    {
        if (index >= 0 && index < books.size())
        {
            books.erase(books.begin() + index);
        }
    }

public:
    void addBook(const Book &book);
    void removeBook(const std::string &ISBN);
    void removeOutDatedBooks(const std::string &date);
    std::shared_ptr<Book> getBook(const std::string &ISBN);

    void subscribe(EventType eventType, std::shared_ptr<Subscriber> subscriber);

    void unsubscribe(EventType eventType, std::shared_ptr<Subscriber> subscriber);

    void notifySubscribers(EventType eventType, const std::string &message);

    void sendPaperBook(const std::string &address, const std::string &ISBN);

    void sendEBook(const std::string &email, const std::string &ISBN);

    void buyBook(const std::string &ISBN,const std::string &email, const std::string &address);
};

#endif // BOOKSTORE_H