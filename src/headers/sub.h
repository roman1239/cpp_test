/*
 * sub.h
 *
 *  Created on: Feb 6, 2024
 *      Author: cman
 */

#ifndef SRC_HEADERS_SUB_H_
#define SRC_HEADERS_SUB_H_

#include "base.h"

class sub: public base
{


public:
    float m_length;
    sub();
    sub(float length);
    sub(const sub& other);

    ~sub();

    void PrintMsg();
    void PrintMsg(int num);

    void PureVirtualFcn();

    sub operator+(const sub& other);
};

#endif /* SRC_HEADERS_SUB_H_ */
