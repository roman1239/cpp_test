/*
 * base.h
 *
 *  Created on: Feb 6, 2024
 *      Author: cman
 */

#ifndef SRC_HEADERS_BASE_H_
#define SRC_HEADERS_BASE_H_

#include <string>

class base
{
protected:
    int m_number;
    const char* m_str;

public:
    base();
    base(int num, const char* str);
    base(const base& other);

    //~base();
    virtual ~base();

    //only fcn with no parameters is virtual
    virtual void PrintMsg();

    void PrintMsg(std::string msg);
    void PrintMsg(int num);

    virtual void PureVirtualFcn() = 0;
};

#endif /* SRC_HEADERS_BASE_H_ */
