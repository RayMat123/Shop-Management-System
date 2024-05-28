#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include "Product.h"

class ShoppingCart {

private:
    std::string shoppingCartID;
    std::vector<std::string> products;

public:
    ShoppingCart();
    ShoppingCart(const std::vector<std::string> _products);
    ShoppingCart(const ShoppingCart& other);
    ~ShoppingCart();

    const std::string& getShoppingCartID() const { return shoppingCartID; }

    void addProduct(Product& other) { products.push_back(other.getName()); }

    void removeProduct(const std::string& product){
        auto it = std::find( products.begin(), products.end(), products );
        if(it != products.end())
            products.erase(it);
        else
            std::cout << "Product \"" << product << "\" not found in the shopping cart." << std::endl;
    }
};