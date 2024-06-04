#include "Product.h"
#include <iostream>

int Product::idCounter = 0;

void Product::generateProductID()
{
    int currentID = idCounter;
    int numDigits = (currentID < 10) ? 2 : 2;
    int totalLength = 5 + numDigits;

    productID = new char[totalLength + 1];

    productID[0] = 'P';
    productID[1] = 'R';
    productID[2] = 'O';
    productID[3] = 'D';
    productID[4] = '-';

    if (currentID < 10)
    {
        productID[5] = '0';
        productID[6] = '0' + currentID;
    }
    else
    {
        productID[5] = (currentID / 10);
        productID[6] = '0' + (currentID % 10);
    }

    productID[7] = '\0';
}

Product::Product() : productID(nullptr), name(nullptr)
{
    idCounter++;

    const char *defStr{"Unknown"};

    generateProductID();
    copy_str(name, defStr);
    price = 0.00;
    quantity = 0;
}

Product::Product(const char *_name, double _price, int _quantity)
    : productID(nullptr), name(nullptr)
{
    idCounter++;

    generateProductID();
    copy_str(name, _name);
    price = _price;
    quantity = _quantity;
}

Product::Product(const Product &other) : name(nullptr)
{
    copy_str(name, other.name);
    price = other.price;
    quantity = other.quantity;
}

Product::~Product()
{
    idCounter--;

    delete[] productID;
    delete[] name;

    productID = nullptr;
    name = nullptr;
}

void Product::displayProduct()
{
    std::cout<< "Total Products: " << idCounter << std::endl;
    std::cout << "\nProduct Information:" << std::endl;
    std::cout << "Product ID: " << getProductID() << getCount() << std::endl;
    std::cout << "Name: " << getName() << std::endl;
    std::cout << "Price: $" << getPrice() << std::endl;
    std::cout << "Available Quantity: " << getQuantity() << std::endl;
}

Electronics::Electronics() : brand(nullptr), modelNumber(nullptr)
{
    const char *defStr{"Unknown"};
    copy_str(brand, defStr);
    warrantyYear = 0;
    warrantyMonth = 0;
    warrantyDay = 0;
    copy_str(modelNumber, defStr);
    powerConsumption = 0.00;
}

Electronics::Electronics(
    const char *_name, double _price, int _quantity,
    const char *prodBrand, int years, int months, int days,
    const char *prodModelNo, const double power)
    : Product(_name, _price, _quantity)
{

    copy_str(brand, prodBrand);

    warrantyYear = years;
    warrantyMonth = months;
    warrantyDay = days;

    copy_str(modelNumber, prodModelNo);

    powerConsumption = power;
}

Electronics::Electronics(const Electronics &other)
    : Product(other.name, other.price, other.quantity) {

    copy_str(brand, other.brand);

    warrantyYear = other.warrantyYear;
    warrantyMonth = other.warrantyMonth;
    warrantyDay = other.warrantyDay;

    copy_str(modelNumber, other.modelNumber);

    powerConsumption = other.powerConsumption;
}

Electronics::~Electronics()
{
    delete[] brand;
    delete[] modelNumber;

    brand = nullptr;
    modelNumber = nullptr;
}

void Electronics::setWarrantyPeriod(int years, int months, int days)
{
    warrantyYear = years;
    warrantyMonth = months;
    warrantyDay = days;
}

void Electronics::getWarrantyPeriod()
{
    std::cout << warrantyYear << " Year(s), " << warrantyMonth << " Month(s), " << warrantyDay << " Day(s).";
}

void Electronics::calculateWarrantyCoverage()
{
    int cYear = 0, cMonth = 0, cDay = 0;
    int pYear = 0, pMonth = 0, pDay = 0;

    std::cout << "Enter current date(YY-MM-DD): ";
    std::cin >> cYear >> cMonth >> cDay;

    std::cout << "\nEnter the date product was purchased(YY-MM-DD): ";
    std::cin >> pYear >> pMonth >> pDay;

    pYear = pYear - cYear;
    pMonth = pMonth - cMonth;
    pDay = pDay - cDay;

    if (pYear <= 0 && pMonth <= 0 && pDay <= 0)
        std::cout << "\nThe product" << this->name << "has expired." << std::endl;
    else
        std::cout << "\nThe product" << this->name << "has " << warrantyYear << " Year(s), " << warrantyMonth << " Month(s), " << warrantyDay << " Day(s) remaining warranty period." << std::endl;
}

void Electronics::displayElectronics()
{
    Product::displayProduct();
    std::cout << "\nProduct type: Electronics" << std::endl;
    std::cout << "Brand: " << getBrand() << std::endl;
    std::cout << "Warranty Period: ";
    getWarrantyPeriod();
    std::cout << "\nModel Number: " << getModelNumber() << std::endl;
    std::cout << "Power Consumption: " << getPowerConsumption() << std::endl;
}

Clothing::Clothing(){
    const char* defStr { "Unknown" };

    size = 0;
    copy_str(material, defStr);
    copy_str(color, defStr);
    gender = '\0';
}

Clothing::Clothing(
    const char* _name, double _price, int _quantity, double _size, const char* _material, const char* _color, const char _gender
    )
{
    Product(_name, _price, _quantity);

    size = _size;
    copy_str(material, _material);
    copy_str(color, _color);
    gender = _gender;
}

Clothing::Clothing(const Clothing& other)
: Product(other.name, other.price, other.quantity) {

    size = other.size;
    copy_str(material, other.material);
    copy_str(color, other.color);
    gender = other.gender;
}

Clothing::~Clothing(){
    delete[] material;
    delete[] color;

    material = nullptr;
    color = nullptr;
}

void Clothing::displayClothing(){
    displayProduct();
    std::cout << "\nProduct type: Clothing" << std::endl;
    std::cout << "Size: " << getSize() << " cm" << std::endl;
    std::cout << "Material: " << getMaterial() << std::endl;
    std::cout << "Color: " << getColor() << std::endl;

    if(getGender() == 'M' || getGender() == 'm')
        std::cout << "Gender: Male" << std::endl;
    else if(getGender() == 'F' || getGender() == 'f')
        std::cout << "Gender: Female" << std::endl;
    else if(getGender() == 'U' || getGender() == 'u')
        std::cout << "Gender: Unisex" << std::endl;
    else std::cout << "Invalid input." << std::endl;
}

Book::Book() {
    const char* defStr { "Unknown" };

    copy_str(author, defStr);
    copy_str(isbn, defStr);
    copy_str(publisher, defStr);
    pubYear = 0;
    copy_str(genre, defStr);
}

Book::Book(
    const char* _name, double _price, int _quantity,
    const char* _author, const char* _isbn,
    const char* _publisher, int year, const char* _genre
    )
{
    Product(_name, _price, _quantity);

    copy_str(author, _author);
    copy_str(isbn, _isbn);
    copy_str(publisher, _publisher);
    pubYear = year;
    copy_str(genre, _genre);
}

Book::Book(const Book& other)
: Product(other.name, other.price, other.quantity) {

    copy_str(author, other.author);
    copy_str(isbn, other.isbn);
    copy_str(publisher, other.publisher);
    pubYear = other.pubYear;
    copy_str(genre, other.genre);
}

Book::~Book(){
    delete[] author;
    delete[] isbn;
    delete[] publisher;
    delete[] genre;
}

void Book::displayBook(){
    displayProduct();
    std::cout << "\nProduct type: Book" << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "ISBN: " << getIsbn() << std::endl;
    std::cout << "Author: " << getAuthor() << std::endl;
    std::cout << "Publisher: " << getPublisher() << std::endl;
    std::cout << "Publication year: " << getPubYear() << std::endl;
    std::cout << "Genre: " << getGenre() << std::endl;
}