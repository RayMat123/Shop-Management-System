#include "Customer.h"
#include<iostream>

int Customer::idCounter = 0;

void Customer::generateCustomerID(){
    int currentID = idCounter;
    int numDigits = (currentID < 10) ? 2 : 2;
    int totalLength = 5 + numDigits;

    customerID = new char[totalLength + 1];

    customerID[0] = 'C';
    customerID[1] = 'S';
    customerID[2] = 'T';
    customerID[3] = 'O';
    customerID[4] = '-';

    if (currentID < 10)
    {
        customerID[5] = '0';
        customerID[6] = currentID;
    }
    else
    {
        customerID[5] = (currentID / 10);
        customerID[6] = '0' + (currentID % 10);
    }

    customerID[7] = '\0';
}

Customer::Customer() {
    idCounter++;
    generateCustomerID();

    const char* defStr { "Unknown" };

    copy_str(name, defStr);
    copy_str(email, defStr);
    copy_str(phoneNumber, defStr);
    copy_str(address, defStr);
}

Customer::Customer(
        const char* _name, const char* _email, 
        const char* _phoneNumber, const char* _address
        )
{
    idCounter++;
    generateCustomerID();

    copy_str(name, _name);
    copy_str(email, _email);
    copy_str(phoneNumber, _phoneNumber);
    copy_str(address, _address);
}

Customer::Customer(const Customer& other){
    idCounter++;
    generateCustomerID();

    copy_str(name, other.name);
    copy_str(email, other.email);
    copy_str(phoneNumber, other.phoneNumber);
    copy_str(address, other.address);
}

Customer::~Customer() {
    idCounter--;

    delete[] name;
    delete[] email;
    delete[] phoneNumber;
    delete[] address;
}

void Customer::displayCustomer(){
    std::cout << "Customer Information." << std::endl;
    std::cout << "\nCustomer ID: " << getCustomerID() << std::endl;
    std::cout << "Customer name: " << getName() << std::endl;
    std::cout << "Customer email: " << getEmail() << std::endl;
    std::cout << "Customer phone number: " << getPhoneNumber() << std::endl;
    std::cout << "Customer address: " << getAddress() << std::endl;
}

RegularCustomer::RegularCustomer(){} 

RegularCustomer::RegularCustomer(
    const char* _name, const char* _email, 
    const char* _phoneNumber, const char* _address)
    : Customer(_name, _email, _phoneNumber, _address) {}

RegularCustomer::RegularCustomer(const RegularCustomer& other){
    copy_str(name, other.name);
    copy_str(email, other.email);
    copy_str(phoneNumber, other.phoneNumber);
    copy_str(address, other.address);
}

RegularCustomer::~RegularCustomer(){}

void RegularCustomer::displayRegularCustomer(){
    Customer::displayCustomer();
}

PremiumCustomer::PremiumCustomer(){
    loyaltyPoints = 0;
    subscriptionFee = 0.00;
}

PremiumCustomer::PremiumCustomer(
        const char* _name, const char* _email, 
        const char* _phoneNumber, const char* _address, int points,
        const int fee
        ) : Customer(_name, _email, _phoneNumber, _address)
{
    loyaltyPoints = points;
    subscriptionFee = fee;
}

PremiumCustomer::PremiumCustomer(const PremiumCustomer& other)
: Customer(other.name, other.email, other.phoneNumber, other.address) {
    loyaltyPoints = other.loyaltyPoints;
    subscriptionFee = other.subscriptionFee;
}

PremiumCustomer::~PremiumCustomer(){}

void PremiumCustomer::displayPremiumCustomer(){
    std::cout << "Loyalty points: " << loyaltyPoints << std::endl;
    std::cout << "Subscription fee: " << subscriptionFee << std::endl;
}