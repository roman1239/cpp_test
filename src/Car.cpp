/*
 * Car.cpp
 *
 *  Created on: Feb 14, 2024
 *      Author: cman
 */

#include "Car.h"
#include "String.h"

Car::Car(const String& str) : m_name(str)
{
    std::cout << "Car::param ctor" << std::endl;
}


Car::Car(String&& str) :
//        m_name((String&&)str)
        m_name(std::move(str))
{
    std::cout << "Car::move ctor" << std::endl;
}


Car::~Car()
{
    std::cout << "Car::dtor" << std::endl;
}
