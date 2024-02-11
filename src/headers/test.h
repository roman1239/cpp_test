/*
 * test.h
 *
 *  Created on: Feb 9, 2024
 *      Author: roman
 */

#ifndef TEST_H_
#define TEST_H_

class test
{


public:
    std::string m_str;
    int m_num;
    float m_flt;
	test();
	test(std::string str, int num, float flt);
	test(const test& other);
	~test();

	bool operator==(const test& other) const;

	//bool operator<(const test& other) const;
};

#endif /* TEST_H_ */
