#include "ProductProperty.h"

QuantityProperty::QuantityProperty(int quantity) : quantity(quantity) {}

int QuantityProperty::getQuantity() const
{
    return quantity;
}

Property QuantityProperty::getPropertyType() const
{
    return Property::Quantity;
}

void QuantityProperty::setQuantity(int quantity)
{
    this->quantity = quantity;
}

WeightProperty::WeightProperty(double weight) : weight(weight) {}

double WeightProperty::getWeight() const
{
    return weight;
}

Property WeightProperty::getPropertyType() const
{
    return Property::Weight;
}

GlobalIdentifierProperty::GlobalIdentifierProperty(const std::string &globalIdentifier)
    : globalIdentifier(globalIdentifier) {}

std::string GlobalIdentifierProperty::getGlobalIdentifier() const
{
    return globalIdentifier;
}

Property GlobalIdentifierProperty::getPropertyType() const
{
    return Property::GlobalIdentifier;
}


DateProperty::DateProperty(const std::string &date) : date(date) {}
std::string DateProperty::getDate() const
{
    return date;
}

Property DateProperty::getPropertyType() const
{
    return Property::Date;
}

std::shared_ptr<QuantityProperty> ProductManager::getQuantityProperty(const std::shared_ptr<ProductProperty> &property)
{
    if (property->getPropertyType() == Property::Quantity)
    {
        return std::static_pointer_cast<QuantityProperty>(property);
    }
    return nullptr;
}

std::shared_ptr<WeightProperty> ProductManager::getWeightProperty(const std::shared_ptr<ProductProperty> &property)
{
    if (property->getPropertyType() == Property::Weight)
    {
        return std::static_pointer_cast<WeightProperty>(property);
    }
    return nullptr;
}

std::shared_ptr<GlobalIdentifierProperty> ProductManager::getGlobalIdentifierProperty(const std::shared_ptr<ProductProperty> &property)
{
    if (property->getPropertyType() == Property::GlobalIdentifier)
    {
        return std::static_pointer_cast<GlobalIdentifierProperty>(property);
    }
    return nullptr;
}

std::shared_ptr<DateProperty> ProductManager::getDateProperty(const std::shared_ptr<ProductProperty> &property)
{
    if (property->getPropertyType() == Property::Date)
    {
        return std::static_pointer_cast<DateProperty>(property);
    }
    return nullptr;
}