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
    Book book(30, "C++ Programming", "978-3-16-148410-0", "2023-10-01", 100, "ebook_file.pdf");
    ProductManager manager;
    std::shared_ptr<QuantityProperty> q1 = manager.getQuantityProperty(book.getProperty(Property::Quantity));
    if (q1)
    {
        std::cout << q1->getQuantity() << std::endl;
        q1->setQuantity(200);
    }
    std::shared_ptr<QuantityProperty> q2 = manager.getQuantityProperty(book.getProperty(Property::Quantity));
    if (q2)
    {
        std::cout << q2->getQuantity() << std::endl;
    }
    return 0;
}