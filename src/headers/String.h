/*
 * String.h
 *
 *  Created on: Feb 14, 2024
 *      Author: cman
 */

#ifndef SRC_STRING_H_
#define SRC_STRING_H_

#include <iostream>

class String
{
private:
    char* m_str;
    uint32_t m_size;

public:
    //String() = default;
    String();
    String(const char* str);
    String(const String& other);

    String(String&& other) noexcept;

    ~String();

    String operator=(const String& other);

    String& operator=(String&& other)noexcept;

    char& operator[](uint32_t index);

    const char* GetStr() const;
    uint32_t Size();
};

#endif /* SRC_STRING_H_ */
