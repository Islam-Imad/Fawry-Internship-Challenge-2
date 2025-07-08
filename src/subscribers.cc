#include "subscribers.h"
#include <iostream>
#include <vector>

void EmailService::notify(const std::string &message)
{
    std::cout << "Email Service: " << message << std::endl;
}

void ShippingService::notify(const std::string &message)
{
    std::cout << "Shipping Service: " << message << std::endl;
}