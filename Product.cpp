#include "Product.h"
#include<iostream>
#include<iomanip>
#include<sstream>


int Product::idCounter = 0;

std::string Product::generateProductID() {
    std::ostringstream oss;
    if(idCounter < 10){
        oss << "PROD-0" << idCounter;
    } else{
        oss << "PROD-" << idCounter;
    }
    idCounter++;
    return oss.str();
}

