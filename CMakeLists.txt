cmake_minimum_required(VERSION 3.0)
project(OnlineShoppingSystem)

# Add source files
set(SOURCES
    Customer.h
    Customer.cpp
    Product.h
    Product.cpp
    ShoppingCart.h
    ShoppingCart.cpp
    main.cpp
)

# Add executable target
add_executable(main ${SOURCES})