#pragma once 
#include "utils.h"

class Customer {

private:
    char* customerID;

    char* generateCustomerID();

protected:
    char** productsPurchased;
    double amountSpend;
    char* name;
    char* email;
    char* phoneNumber;
    char* address;

public:
    Customer();
    Customer(
        const char* _name, const char* _email, 
        const char* _phoneNumber, const char* _address
        );
    Customer(const Customer& other);
    ~Customer();

    const char* getCustomerID() const { return customerID; }

    void setName(const char* _name) { copy_str(name, _name); }
    const char* getName() { return name; }

    void setEmail(const char* _email) { copy_str(email, _email); }
    const char* getEmail() const { return email; }

    void setPhoneNumber(const char* _phoneNumber) { copy_str(phoneNumber, _phoneNumber); }
    const char* getPhoneNumber() const { return phoneNumber; }

    void setAddress(const char* _address) { copy_str(address, _address); }
    const char* getAddress() const { return address; }

    void setProductsPurchased(const char** products);
    const char** getProductsPurchased() { return productsPurchased; }

    void setAmountSpend(const double amount) { amountSpend = amount; }
    const double getAmountSpend() { return amountSpend; }

    void displayCustomer();
};

class RegularCustomer : public Customer {

private:
    char** productsPurchased;
    double amountSpend;

public:
    RegularCustomer();
    RegularCustomer(
        const char* _name, const char* _email, 
        const char* phoneNumber, const char* _address, 
        const char** products, double amount
        );
    RegularCustomer(const RegularCustomer& other);
    ~RegularCustomer();

    void displayRegularCustomer();
};

class PremiumCustomer : public Customer {

private:
    int loyaltyPoints;
    double subscriptionFee;

public:
    PremiumCustomer();
    PremiumCustomer(
        const char* _name, const char* _email, 
        const char* phoneNumber, const char* _address, 
        const char** products, const double amount, 
        const int fee
        );
    PremiumCustomer(const PremiumCustomer& other);
    ~PremiumCustomer();

    void setLoyaltyPoints(const int loyaltyPoints) { this->loyaltyPoints = loyaltyPoints; }
    const int getLoyaltyPoints() { return loyaltyPoints; }

    void setSubscriptionFee(const double subscriptionFee) { this->subscriptionFee = subscriptionFee; }
    const int getSubscriptionFee() { return subscriptionFee; }

    void displayPremiumCustomer();
};