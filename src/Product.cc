#include "Product.h"

Product::Product(double price, const std::string &name, ProductCategory category)
    : price(price), name(name), category(category) {}

double Product::getPrice() const
{
    return price;
}

std::string Product::getName() const
{
    return name;
}

ProductCategory Product::getCategory() const
{
    return category;
}

void Product::addProperty(std::shared_ptr<ProductProperty> property)
{
    properties.push_back(property);
}

std::shared_ptr<ProductProperty> Product::getProperty(Property property) const
{
    for (const auto &prop : properties)
    {
        if (prop->getPropertyType() == property)
        {
            return prop;
        }
    }
    return nullptr; // or throw an exception if preferred
}

void Product::accept(ProductVisitor &visitor)
{
    visitor.visit(*this);
}

Book::Book(double price, const std::string &name, const std::string &ISBN, const std::string &Date, int quantity, const std::string &ebook_file)
    : Product(price, name, ProductCategory::Books)
{
    addProperty(std::make_shared<GlobalIdentifierProperty>(ISBN));
    addProperty(std::make_shared<DateProperty>(Date));
    addProperty(std::make_shared<QuantityProperty>(quantity));
    this->ebook_file = ebook_file;
}