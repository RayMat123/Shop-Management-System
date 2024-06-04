#pragma once
#include "utils.h"

class Electronics;
class Clothing;
class Book;

class Product {

private:
    char* productID;
    static int idCounter;

    void generateProductID();


protected:
    char* name;
    double price;
    int quantity;
    

public:
    Product();
    Product(const char* _name, double _price, int _quantity);
    Product(const Product& other);
    ~Product();

    int getCount() { return idCounter; }

    const char* getProductID() { return productID; }

    void setName(const char* n) { copy_str(name, n); }
    const char* getName() { return name; }

    void setPrice(double p) { price = p; }
    const double getPrice() { return price; }

    void setQuantity(int q) { quantity = q; }
    const int getQuantity() { return quantity; }

    void displayProduct();
};

class Electronics : public Product {

private:
    char* brand;
    int warrantyYear;
    int warrantyMonth;
    int warrantyDay;
    char* modelNumber;
    double powerConsumption;

public:
    Electronics();
    Electronics(
        const char* _name, double _price, int quantity, 
        const char* prodBrand, int years, int months, int days,  
        const char* prodModelNo, const double power
        );
    Electronics(const Electronics& other);
    ~Electronics();
    
    void setBrand(const char* prodBrand) { copy_str(brand, prodBrand); }
    const char* getBrand() { return brand; }

    void setWarrantyPeriod(int years, int months, int days);
    void getWarrantyPeriod();

    void setModelNumber(const char* modelNo) { copy_str(modelNumber, modelNo); }
    const char* getModelNumber() { return modelNumber; }

    void setPowerConsumption(const double power) { powerConsumption = power; }
    const double getPowerConsumption() { return powerConsumption; }

    void calculateWarrantyCoverage();

    void displayElectronics();
};

class Clothing : public Product {

private:
    double size;
    char* material;
    char* color;
    char gender;

public:
    Clothing();
    Clothing(
        const char* _name, double _price, int _quantity, double _size, 
        const char* _material, const char* _color, 
        const char _gender
        );
    Clothing(const Clothing& other);
    ~Clothing();

    void setSize(const double s) { size = s; }
    const double getSize() { return size; }

    void setMaterial(const char* m) { copy_str(material, m); }
    const char* getMaterial() { return material; }

    void setColor(const char* _color) { copy_str(color, _color); }
    const char* getColor() { return color; }

    void setGender(const char g) { gender = g; }
    const char getGender() { return gender; }

    void displayClothing();
};

class Book : public Product {

private:
    char* author;
    char* isbn;
    char* publisher;
    int pubYear;
    char* genre;

public:
    Book();
    Book(
        const char* _name, double _price, int _quantity, 
        const char* _author, const char* _isbn, 
        const char* _publisher, int year, const char* _genre
        );
    Book(const Book& other);
    ~Book();

    void setAuthor(const char* a) { copy_str(author, a); }
    const char* getAuthor() { return author; }

    void setIsbn(const char* _isbn) { copy_str(isbn, _isbn); }
    const char* getIsbn() { return isbn; }

    void setPublisher(const char* pub) { copy_str(publisher, pub); }
    const char* getPublisher() { return publisher; }

    void setPubYear(const int year) { pubYear = year; }
    const int getPubYear() { return pubYear; }

    void setGenre(const char* _genre) { copy_str(genre, _genre); }
    const char* getGenre() { return genre; }

    void displayBook();
};