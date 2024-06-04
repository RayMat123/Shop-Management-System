#include<iostream>
#include"ShoppingCart.h"
#include "Product.h"
#include"Customer.h"
#include "utils.h"

int main(){

    Electronics laptop("Laptop", 1500.0, 10, "Dell", 2, 4, 12, "XHZ-0012", 120);
    Clothing shirt("Shirt", 50.0, 5, 175, "Cotton", "White", 'M');
    Book book("C++ Programming", 30.0, 3, "Bjarne Stroustrup", "978-0321958327", "Addison-Wesley Professional", 2013, "Not Specified");

    RegularCustomer regCustomer("John Doe", "john@example.com", "0378-1234567", "123 Main Fake Street, Fake House #13");
    PremiumCustomer premCustomer("Jane Smith", "jane@example.com", "0327-4848771", "456 Oak St", 100, 20);

    ShoppingCart cart;

    cart.addProduct(&laptop);
    cart.addProduct(&shirt);
    cart.addProduct(&book);

    regCustomer.displayRegularCustomer();
    std::cout << "\n";

    std::cout << "Shopping Cart:\n";
    cart.displayCart();

    std::cout << "\n";
    cart.generateOrderSummary();

    std::cout << "\nPremium Customer Information:\n";
    premCustomer.displayPremiumCustomer();
    double discount = premCustomer.calculateDiscount();
    std::cout << "Discount: " << discount << "\n";
    std::cout << "Total after discount: " << cart.calculateTotal() - discount << "\n";

    return 0;
}