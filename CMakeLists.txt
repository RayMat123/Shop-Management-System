cmake_minimum_required(VERSION 3.0)
project(OnlineShoppingSystem)

# Add source files
set(SOURCES
    ShoppingCart.h
    ShoppingCart.cpp
    Customer.h
    Customer.cpp
    utils.h
    utils.cpp
    Product.h
    Product.cpp
    main.cpp
)

# Add executable target
add_executable(main ${SOURCES})