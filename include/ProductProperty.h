#include <string>
#include <memory>
#include <vector>
#ifndef PRODUCTPROPERTY_H
#define PRODUCTPROPERTY_H

enum Property
{
    Quantity,
    Weight,
    GlobalIdentifier,
    Date
};

class ProductProperty
{
public:
    virtual ~ProductProperty() = default;
    virtual Property getPropertyType() const = 0;
};

class QuantityProperty : public ProductProperty
{
    int quantity;

public:
    QuantityProperty(int quantity);
    int getQuantity() const;
    void setQuantity(int quantity);
    Property getPropertyType() const override;
};

class WeightProperty : public ProductProperty
{
    double weight;

public:
    WeightProperty(double weight);
    double getWeight() const;
    Property getPropertyType() const override;
};

class GlobalIdentifierProperty : public ProductProperty
{
    std::string globalIdentifier;

public:
    GlobalIdentifierProperty(const std::string &globalIdentifier);
    std::string getGlobalIdentifier() const;
    Property getPropertyType() const override;
};

class DateProperty : public ProductProperty
{
    std::string date;

public:
    DateProperty(const std::string &date);
    std::string getDate() const;
    Property getPropertyType() const override;
};

class ProductManager
{
public:
    std::shared_ptr<QuantityProperty> getQuantityProperty(const std::shared_ptr<ProductProperty> &property);
    std::shared_ptr<WeightProperty> getWeightProperty(const std::shared_ptr<ProductProperty> &property);
    std::shared_ptr<GlobalIdentifierProperty> getGlobalIdentifierProperty(const std::shared_ptr<ProductProperty> &property);
    std::shared_ptr<DateProperty> getDateProperty(const std::shared_ptr<ProductProperty> &property);
};

#endif // PRODUCTPROPERTY_H