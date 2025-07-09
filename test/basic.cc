#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "subscribers.h"
#include "EventType.h"
#include "Product.h"
#include "ProductProperty.h"
#include "ProductCategory.h"
#include "BookStore.h"

TEST(BookStore, BuyBook)
{
    ProductManager manager;
    Book book1(30, "C++ Programming", "1", "2023-10-01", 100, "ebook1_file.pdf");
    Book book2(39, "Python Programming", "2", "2023-10-03", 50, "ebook2_file.pdf");
    Book book3(80, "Java Programming", "3", "2023-10-03", 50, "ebook2_file.pdf");
    std::shared_ptr<QuantityProperty> qp = manager.getQuantityProperty(book2.getProperty(Quantity));
    BookStore store;
    store.addBook(book1);
    store.addBook(book2);
    store.addBook(book3);
    ASSERT_EQ(qp->getQuantity(), 50);
    store.buyBook("2", "souka@sa.com", "street2");
    ASSERT_EQ(qp->getQuantity(), 49);
}

TEST(BookStore, RemoveBook)
{
    ProductManager manager;
    Book book1(30, "C++ Programming", "1", "2023-10-01", 100, "ebook1_file.pdf");
    BookStore store;
    store.addBook(book1);
    store.removeBook("1");
    std::shared_ptr<Product> b = store.getBook("1");
    ASSERT_EQ(b, nullptr);
}