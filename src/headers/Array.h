/*
 * Array.h
 *
 *  Created on: Feb 15, 2024
 *      Author: cman
 */

#ifndef ARRAY_H_
#define ARRAY_H_

#include <iostream>

template<typename T, size_t S>
class Array
{
private:
    T m_array[S];

public:
    size_t Size()
    {
        return S;
    }

    T* GetData()
    {
        return m_array;
    }

    T& operator[](size_t index)
    {
        return m_array[index];
    }


    //Iterator

    struct Iterator
    {
        T* m_itr;

        Iterator(T* itr): m_itr(itr) {}

        Iterator& operator++()
        {
            m_itr++;
            return *this;
        }

        Iterator& operator++(int)
        {
            Iterator* tmp = this;
            ++(*this);
            return *tmp;
        }

        Iterator& operator--()
        {
            m_itr--;
            return *this;
        }

        Iterator& operator--(int)
        {
            Iterator* tmp = this;
            m_itr--;
            return *tmp;
        }

        bool operator==(const Iterator& other) const
        {
            return this->m_itr == other.m_itr;
        }

        bool operator!=(const Iterator& other) const
        {
            return !(this->m_itr == other.m_itr);
        }

        T& operator*()
        {
            return *m_itr;
        }

        T& operator[](size_t index)
        {
            return *(m_itr + index);
        }

        T* operator->()
        {
            return m_itr;
        }

        T& at(size_t index)
        {
            return *(m_itr + index);
        }

    };

    Iterator begin()
    {
        return Iterator(m_array);
    }

    Iterator end()
    {
        return Iterator(m_array + S);
    }


};


#endif /* ARRAY_H_ */
