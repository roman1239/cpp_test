/*
 * sub.cpp
 *
 *  Created on: Feb 6, 2024
 *      Author: cman
 */

#include "sub.h"

#include <iostream>

sub::sub(float length) : m_length(length)
{
    std::cout << "SUB: Parameterized constructor called ! " << m_length << ":" << m_number << std::endl;
}

sub::sub() : m_length(0.0)
{
    std::cout << "SUB: Default constructor called !" << m_length << ":" << m_number  << std::endl;
}

sub::sub(const sub& other) : m_length(other.m_length)
{
    std::cout << "SUB: Copy constructor called !" << m_length << ":" << m_number << std::endl;
}

sub::~sub()
{
    std::cout << "SUB: Destructor called !" << m_length << ":" << m_number  << std::endl;
}

void sub::PrintMsg()
{
    std::cout << "SUB: PRINT FCN !" << std::endl;
}

void sub::PrintMsg(int num)
{
    std::cout << "SUB: PRINT FCN !" << num << std::endl;
}

void sub::PureVirtualFcn()
{
    std::cout << "SUB: PURE VIRTUAL FCN !" << std::endl;
}

sub sub::operator+(const sub& other)
{
    return sub(m_length + other.m_length);
}
