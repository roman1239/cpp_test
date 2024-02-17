/*
 * Vector3.cpp
 *
 *  Created on: Feb 17, 2024
 *      Author: roman
 */

#include "Vector3.h"

#include <iostream>


    Vector3::Vector3() : m_x(0.0f), m_y(0.0f), m_z(0.0f)
    {
        std::cout << "Vector3: default ctor" << std::endl;
    }

    Vector3::Vector3(float x, float y, float z) : m_x(x), m_y(y), m_z(z)
    {
        std::cout << "Vector3: param ctor" << std::endl;
    }

    Vector3::Vector3(const Vector3& other) :
        m_x(other.m_x), m_y(other.m_y), m_z(other.m_z)
    {
        std::cout << "Vector3: copy ctor" << std::endl;
    }

    Vector3::Vector3(Vector3&& other)
    {
        //*this = std::move(other);
        *this = Vector3((Vector3&&)other);
        std::cout << "Vector3: move ctor" << std::endl;
    }

    Vector3::~Vector3()
    {
        std::cout << "Vector3: dtor" << std::endl;
    }

    Vector3& Vector3::operator=(const Vector3& other)
    {
        std::cout << "Vector3: copy operator=" << std::endl;
        m_x = other.m_x;
        m_y = other.m_y;
        m_z = other.m_z;
        return *this;
    }

    Vector3& Vector3::operator=(Vector3&& other)
    {
        std::cout << "Vector3: move operator=" << std::endl;
        //*this = std::move(other);
        m_x = other.m_x;
        m_y = other.m_y;
        m_z = other.m_z;
        return *this;
    }
