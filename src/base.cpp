/*
 * base.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: cman
 */

#include "base.h"

#include <iostream>

base::base(int num, const char* str) : m_number(num),
                                       m_str(str)
{
    std::cout << "BASE: Parameterized constructor called ! " << m_number << std::endl;
}

base::base() : m_number(0),
               m_str("empty")
{
    std::cout << "BASE: Default constructor called !" << m_number  << std::endl;
}

base::base(const base& other) : m_number(other.m_number),
                                m_str(other.m_str)
{
    std::cout << "BASE: Copy constructor called !" << m_number  << std::endl;
}

base::~base()
{
    std::cout << "BASE: Destructor called !" << m_number  << std::endl;
}

void base::PrintMsg()
{
    std::cout << "BASE: PRINT FCN !" << std::endl;
}

void base::PrintMsg(std::string msg)
{
    std::cout << "BASE: PRINT FCN !" << msg << std::endl;
}

void base::PrintMsg(int num)
{
    std::cout << "BASE: PRINT FCN !" << num << std::endl;
}

//pure virtual means, that sub classes should implement this,
//so no reason to implement here
/*
void base::PureVirtualFcn()
{
    std::cout << "BASE: PURE VIRTUAL FCN !" << std::endl;
}
*/

