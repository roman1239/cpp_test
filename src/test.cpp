/*
 * test.cpp
 *
 *  Created on: Feb 9, 2024
 *      Author: roman
 */

#include <iostream>

#include "test.h"

test::test() : m_str("zero"), m_num(0), m_flt(0.0f)
{
	std::cout << "test::constructor\n";
}

test::test(std::string str, int num, float flt) : m_str(str),
											      m_num(num),
										          m_flt(flt)
{
		std::cout << "test::param constructor\n";
}

test::test(const test& other): m_str(other.m_str),
                               m_num(other.m_num),
                               m_flt(other.m_flt)
{
    std::cout << "test::copy constructor\n";
}

test::~test()
{
	std::cout << "test::destructor\n";
}

bool test::operator==(const test& other) const
{
    return (m_str == other.m_str
                && m_num == other.m_num
                && m_flt == other.m_flt);
}

//for map, you either must specify copmarator fcn and pass it as 3rd template argument
//or operator < in class
/*
bool test::operator<(const test& other) const
{
    return m_str < other.m_str;
}
*/
