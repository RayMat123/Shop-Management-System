#include<iostream>
#include"Product.h"

class ShoppingCart {
private:
    Product* products[100];
    int productCount;

public:
    ShoppingCart();

    void addProduct(Product* product);

    void removeProduct(int index);

    double calculateTotal() const;

    void displayCart() const;

    void generateOrderSummary() const;
};