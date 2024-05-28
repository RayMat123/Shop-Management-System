#pragma once 
#include<string>
#include<vector>

class Customer {

private:
    std::string customerID;

    std::string generateCustomerID();

protected:
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::string address;

public:
    Customer();
    Customer(
        const std::string& _name, const std::string& _email, 
        const std::string& _phoneNumber, const std::string& _address
        );
    Customer(const Customer& other);
    ~Customer();

    const std::string& getCustomerID() const { return customerID; }

    void setName(const std::string& name) { this->name = name; }
    const std::string& getName() { return name; }

    void setEmail(const std::string& email) { this->email = email; }
    const std::string& getEmail() const { return email; }

    void setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
    const std::string& getPhoneNumber() const { return phoneNumber; }

    void setAddress(const std::string& address) { this->address = address; }
    const std::string& getAddress() const { return address; }

    void displayCustomer();
};

class RegularCustomer : public Customer {

private:
    std::vector<std::string> productsPurchased;
    double amountSpend;

public:
    RegularCustomer();
    RegularCustomer(
        const std::string& _name, const std::string& _email, 
        const std::string& phoneNumber, const std::string& _address, 
        const std::vector<std::string> products, double amount
        );
    RegularCustomer(const RegularCustomer& other);
    ~RegularCustomer();

    void setProductsPurchased(const std::vector<std::string> products) { productsPurchased.assign( products.begin(), products.end() ); }
    const std::vector<std::string>& getProductsPurchased() const { return productsPurchased; }

    void setAmountSpend(const double amount) { amountSpend = amount; }
    const double getAmountSpend() { return amountSpend; }

    void displayRegularCustomer();
};

class PremiumCustomer : public Customer {

private:
    std::vector<std::string> productsPurchased;
    double amountSpend;
    int loyaltyPoints;
    double subscriptionFee;

public:
    PremiumCustomer();
    PremiumCustomer(
        const std::string& _name, const std::string& _email, 
        const std::string& phoneNumber, const std::string& _address, 
        const std::vector<std::string> products, const double amount, 
        const int fee
        );
    PremiumCustomer(const PremiumCustomer& other);
    ~PremiumCustomer();

    void setProductsPurchased(const std::vector<std::string> products) { productsPurchased.assign( products.begin(), products.end() ); }
    const std::vector<std::string>& getProductsPurchased() const { return productsPurchased; }

    void setAmountSpend(const double amount) { amountSpend = amount; }
    const double getAmountSpend() { return amountSpend; }

    void setLoyaltyPoints(const int loyaltyPoints) { this->loyaltyPoints = loyaltyPoints; }
    const int getLoyaltyPoints() { return loyaltyPoints; }

    void setSubscriptionFee(const double subscriptionFee) { this->subscriptionFee = subscriptionFee; }
    const int getSubscriptionFee() { return subscriptionFee; }

    void displayPremiumCustomer();
};