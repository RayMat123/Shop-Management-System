#pragma once
#include<string> 
#include<vector>

class Product {

private:
    std::string productID;

protected:
    std::string name;
    double price;
    int quantity;
    static int idCounter;

    std::string generateProductID();

public:
    Product();
    Product(const std::string& id, const std::string& _name, double _price, int _quantity);
    Product(const Product& other);
    ~Product();

    const std::string getProductID() { return productID; }

    void setName(const std::string n) { name = n; }
    const std::string getName() { return name; }

    void setPrice(double p) { price = p; }
    const double getPrice() { return price; }

    void setQuantity(int q) { quantity = q; }
    const int getQuantity() { return quantity; }

    void displayProduct();
};

class Electronics : public Product {

private:
    std::string brand;
    std::vector<int> warrantyPeriod;
    std::string modelNumber;
    double powerConsumption;

public:
    Electronics();
    Electronics(
        const std::string& _name, double _price, int _quantity, 
        const std::string& prodBrand, const std::vector<int>& periodValues, const std::string& prodModelNo, const double power
        );
    Electronics(const Electronics& other);
    ~Electronics();
    
    void setBrand(const std::string& prodBrand) { brand = prodBrand; }
    const std::string getBrand() { return brand; }

    void setBrand(const std::vector<int>& period) { warrantyPeriod.assign(period.begin(), period.end()); }
    const std::vector<int> getWarrantyPeriod() { return warrantyPeriod; }

    void setModelNumber(const std::string& modelNo) { modelNumber = modelNo; }
    const std::string getModelNumber() { return modelNumber; }

    void setPowerConsumption(const double power) { powerConsumption = power; }
    const double getPowerConsumption() { return powerConsumption; }

    const std::vector<int> calculateWarrantyCoverage();

    void displayElectronics();
};

class Clothing : public Product {

private:
    double size;
    std::string material;
    std::string color;
    char gender;

public:
    Clothing();
    Clothing(
        const std::string& _name, double _price, int _quantity, double _size, const std::string& _material, const std::string& _color, 
        const char _gender
        );
    Clothing(const Clothing& other);
    ~Clothing();

    void setSize(const double s) { size = s; }
    const double getSize() { return size; }

    void setMaterial(const std::string& m) { material = m; }
    const std::string getMaterial() { return material; }

    void setColor(const std::string _color) { color = _color; }
    const std::string getColor() { return color; }

    void setGender(const char g) { gender = g; }
    const char getGender() { return gender; }

    void displayClothing();
};

class Book : public Product {

private:
    std::string author;
    std::string isbn;
    std::string publisher;
    int pubYear;
    std::string genre;

public:
    Book();
    Book(
        const std::string& _name, double _price, int _quantity, 
        const std::string& _author, const std::string& _isbn, 
        const std::string _publisher, int year, const std::string& genre
        );
    Book(const Book& other);
    ~Book();

    void setAuthor(const std::string& a) { author = a; }
    const std::string getAuthor() { return author; }

    void setIsbn(const std::string& _isbn) { isbn = _isbn; }
    const std::string getIsbn() { return isbn; }

    void setPublisher(const std::string& pub) { publisher = pub; }
    const std::string getPublisher() { return publisher; }

    void setPubYear(const int year) { pubYear = year; }
    const int getPubYear() { return pubYear; }

    void setGenre(const std::string& _genre) { genre = _genre; }
    const std::string getGenre() { return genre; }

    void displayBook();
};