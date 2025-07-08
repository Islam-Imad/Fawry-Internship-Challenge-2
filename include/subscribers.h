#ifndef SUBSCRIBERS_H
#define SUBSCRIBERS_H

#include "EventType.h"
#include <string>
#include <memory>

class Subscriber
{
public:
    virtual ~Subscriber() = default;
    virtual void notify(const std::string &message) = 0;
};

class EmailService : public Subscriber
{
public:
    void notify(const std::string &message);
};

class ShippingService : public Subscriber
{
public:
    void notify(const std::string &message);
};


#endif // SUBSCRIBERS_H