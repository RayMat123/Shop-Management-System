#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : productCount(0) {}

void ShoppingCart::addProduct(Product *product)
{
    if (productCount < 100)
    {
        products[productCount++] = product;
    }
}

void ShoppingCart::removeProduct(int index)
{
    if (index < 0 || index >= productCount)
    {
        std::cout << "Invalid index\n";
        return;
    }
    for (int i = index; i < productCount - 1; ++i)
    {
        products[i] = products[i + 1];
    }
    productCount--;
}

double ShoppingCart::calculateTotal() const
{
    double total = 0.0;
    for (int i = 0; i < productCount; ++i)
    {
        total += products[i]->getPrice() * products[i]->getQuantity();
    }
    return total;
}

void ShoppingCart::displayCart() const
{
    for (int i = 0; i < productCount; ++i)
    {
        products[i]->displayProduct();
        std::cout << "-----------------------\n";
    }
}

void ShoppingCart::generateOrderSummary() const
{
    std::cout << "Order Summary:\n";
    displayCart();
    std::cout << "Total Price: " << calculateTotal() << "\n";
}