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

        //T* new_block = new T[new_capacity];
        //this version of allocating memorry does not call constructor
        //that should not be done here anyway, just allocate memory
        T* new_block = (T*)::operator new(new_capacity*sizeof(T));

        for(int i = 0; i < m_size; i++)
            new_block[i] = std::move(m_data[i]);
            //new_block[i] = m_data[i];

        //delete[] m_data;
        for(int i = 0; i < m_size; i++)
            m_data[m_size].~T();

        //this version of deallocating memory does not call destructor
        ::operator delete(m_data, m_capacity * sizeof(T));

        m_data = new_block;
        m_capacity = new_capacity;
    }

public:
    Vector() : m_size(0)
    {
        m_data = nullptr;
        Realloc(2);
    }

    ~Vector()
    {
        Clear();
        ::operator delete(m_data, m_capacity * sizeof(T));
    }

    size_t Size()
    {
        return m_size;
    }

    void PushBack(const T& data)
    {
        if(m_size >= m_capacity)
            Realloc(m_capacity + m_capacity/2);
        m_data[m_size] = data;
        m_size++;
    }

    void PushBack(T&& data)
    {
        if(m_size >= m_capacity)
            Realloc(m_capacity + m_capacity/2);
        m_data[m_size] = std::move(data);
        m_size++;
    }

    template<typename... Args>
    T& EmplaceBack(Args&&... args)
    {
        if(m_size >= m_capacity)
            Realloc(m_capacity + m_capacity/2);

        //m_data[m_size] = T(std::forward<Args>(args)...);

        //placement new operator
        new(&m_data[m_size]) T(std::forward<Args>(args)...);

        return m_data[m_size++];
    }

    T& operator[](size_t index)
    {
        return m_data[index];
    }

    const T& operator[](size_t index) const
    {
        return m_data[index];
    }

    void PrintVectorInfo()
    {
        std::cout << "size: " << m_size << " capacity: " << m_capacity << std::endl;
    }

    void PopBack()
    {
        if(m_size > 0)
        {
            m_size--;
            m_data[m_size].~T();
        }
    }

    void Clear()
    {
        for(int i = 0; i < m_size; i++)
            m_data[m_size].~T();
        m_size = 0;
    }


};

#endif /* VECTOR_H_ */
