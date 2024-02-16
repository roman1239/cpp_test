/*
 * Vector.h
 *
 *  Created on: Feb 16, 2024
 *      Author: roman
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>

template<class T>
class Vector
{
private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;

    void Realloc(size_t new_capacity)
    {
        //allocate new memory
        //copy elements
        //free memory

        T* new_block = new T[new_capacity];
        m_capacity = new_capacity;

        for(int i = 0; i < m_size; i++)
            new_block[i] = m_data[i];

        delete[] m_data;

        m_data = new_block;
    }

public:
    Vector() : m_size(0)
    {
        m_data = nullptr;
        Realloc(2);
    }

    size_t Size()
    {
        return m_size;
    }

    void PushBack(T data)
    {
        if(m_size >= m_capacity)
            Realloc(m_capacity + m_capacity/2);
        m_data[m_size] = data;
        m_size++;
    }

    T& operator[](size_t index)
    {
        return m_data[index];
    }

    void PrintVectorInfo()
    {
        std::cout << "size: " << m_size << " capacity: " << m_capacity << std::endl;
    }
};

#endif /* VECTOR_H_ */
