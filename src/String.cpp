/*
 * String.cpp
 *
 *  Created on: Feb 14, 2024
 *      Author: cman
 */

#include "String.h"
#include <cstring>

String::String()
{
    m_size = 0;
    m_str = nullptr;
}

String::String(const char* str)
{
    std::cout << "String::param ctor" << std::endl;
    m_size = strlen(str);
    m_str = new char[m_size + 1];
    memcpy(m_str, str, m_size);
    m_str[m_size] = '\0';
}

String::~String()
{
    std::cout << "String::dtor" << std::endl;
    delete[] m_str;
}


String::String(const String& other)
{
    std::cout << "String::copy ctor" << std::endl;
    m_size = other.m_size;
    m_str = new char[m_size+1];
    memcpy(m_str, other.m_str, m_size+1);
}

const char* String::GetStr() const
{
    return m_str;
}

uint32_t String::Size()
{
    return m_size;
}

char& String::operator[](uint32_t index)
{
    return m_str[index];
}

String String::operator=(const String& other)
{
    std::cout << "String::operator=" << std::endl;
    m_size = other.m_size;
    m_str = new char[m_size+1];
    memcpy(m_str, other.m_str, m_size+1);
    return *this;
}

String::String(String&& other) noexcept
{
    std::cout << "String::move ctor" << std::endl;
    m_size = other.m_size;
    m_str = other.m_str;

    //hollow object
    other.m_size = 0;
    other.m_str = nullptr;
}

String& String::operator=(String&& other) noexcept
{
    if(this != &other)
    {
        std::cout << "String::move assignment operator" << std::endl;

        delete[] m_str;

        m_size = other.m_size;
        m_str = other.m_str;

        other.m_size = 0;
        other.m_str = nullptr;
    }
    return *this;
}
