/*
 * sub2.h
 *
 *  Created on: Feb 7, 2024
 *      Author: cman
 */
#include "base.h"

#ifndef SRC_SUB2_H_
#define SRC_SUB2_H_

class sub2 : public base
{
    void PureVirtualFcn();
    friend std::ostream& operator<<(std::ostream& stream, const sub2& obj);
};

#endif /* SRC_SUB2_H_ */
