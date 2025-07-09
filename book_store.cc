#include <iostream>
#include <memory>
#include "subscribers.h"
#include "EventType.h"
#include "Product.h"
#include "ProductProperty.h"
#include "ProductCategory.h"
#include "BookStore.h"

int main()
{
    ProductManager manager;
    Book book1(30, "C++ Programming", "1", "2023-10-01", 100, "ebook1_file.pdf");
    Book book2(39, "Python Programming", "2", "2023-10-02", 50, "ebook2_file.pdf");
    Book book3(80, "Java Programming", "3", "2023-10-03", 50, "ebook3_file.pdf");
    Book book4(200, "C Programming", "4", "2023-10-04", 200, "ebook4_file.pdf");
    std::shared_ptr<QuantityProperty> qp = manager.getQuantityProperty(book2.getProperty(Quantity));
    BookStore store;
    store.addBook(book1);
    store.addBook(book2);
    store.addBook(book3);
    store.addBook(book4);
    std::cout << qp->getQuantity() << '\n'; 
    store.buyBook("2","souka@sa.com","street2");
    std::cout << qp->getQuantity() << '\n'; 
    store.printBooks();

    store.removeOutDatedBooks("2023-10-03");
    std::cout << "------------------\n";
    store.printBooks();
    return 0;
}