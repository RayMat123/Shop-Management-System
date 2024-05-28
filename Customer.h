#pragma once 
#include<string>

class Customer {

private:
    std::string customerID;

protected:
    std::string name;
    std::string email;
    std::string phoneNumber;
    std::string address;

public:
    Customer();
    Customer(const std::string& _name, const std::string& _email, const std::string& _phoneNumber, const std::string& _address);
    Customer(const Customer& other);
    ~Customer();

    const std::string getCustomerID() { return customerID; }

    void setName(const std::string& name) { this->name = name; }
    const std::string getName() { return name; }

    void setEmail(const std::string& email) { this->email = email; }
    const std::string getEmail() { return email; }

    void setPhoneNumber(const std::string& phoneNumber) { this->phoneNumber = phoneNumber; }
    const std::string getPhoneNumber() { return phoneNumber; }

    void setAddress(const std::string& address) { this->address = address; }
    const std::string getAddress() { return address; }

    void displayCustomer();
};