/*
 * Car.h
 *
 *  Created on: Feb 14, 2024
 *      Author: cman
 */

#ifndef SRC_HEADERS_CAR_H_
#define SRC_HEADERS_CAR_H_

#include "String.h"

class Car
{
    String m_name;
public:
    Car(const String& str);
    Car(String&& str);
    ~Car();
};

#endif /* SRC_HEADERS_CAR_H_ */
