#include "ProductCategory.h"
#include "ProductProperty.h"
#include <memory>
#include <vector>
#include <string>

#ifndef PRODUCT_H
#define PRODUCT_H

class Product;
class ProductVisitor;

class ProductVisitor
{
public:
    virtual void visit(const Product &product) = 0;
};

class Product
{
    double price;
    std::string name;
    ProductCategory category;
    std::vector<std::shared_ptr<ProductProperty>> properties;

public:
    Product(double price, const std::string &name, ProductCategory category);
    std::string getName() const;
    ProductCategory getCategory() const;
    double getPrice() const;
    std::shared_ptr<ProductProperty> getProperty(Property property) const;
    void addProperty(std::shared_ptr<ProductProperty> property);
    virtual void accept(ProductVisitor &visitor);
};

class Book : public Product
{
    std::string ebook_file;
public:
    Book(double price, const std::string &name, const std::string &ISBN, const std::string &Date, int quantity, const std::string &ebook_file);
};

#endif // PRODUCT_H