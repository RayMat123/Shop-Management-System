#pragma once 
#include "utils.h"
class RegularCustomer;
class PremiumCustomer;

class Customer {

private:
    char* customerID;
    static int idCounter;

    void generateCustomerID();

protected:
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


    void displayCustomer();
};

class RegularCustomer : public Customer {

public:
    RegularCustomer();
    RegularCustomer(
        const char* _name, const char* _email, 
        const char* _phoneNumber, const char* _address
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
        const char* _phoneNumber, const char* _address, int points, 
        const int fee
        );
    PremiumCustomer(const PremiumCustomer& other);
    ~PremiumCustomer();

    void setLoyaltyPoints(const int loyaltyPoints) { this->loyaltyPoints = loyaltyPoints; }
    const int getLoyaltyPoints() { return loyaltyPoints; }

    void setSubscriptionFee(const double subscriptionFee) { this->subscriptionFee = subscriptionFee; }
    const int getSubscriptionFee() { return subscriptionFee; }

    double calculateDiscount() const { return loyaltyPoints * 0.1; }

    void displayPremiumCustomer();
};