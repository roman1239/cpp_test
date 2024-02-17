/*
 * Vector3.h
 *
 *  Created on: Feb 17, 2024
 *      Author: roman
 */

#ifndef VECTOR3_H_
#define VECTOR3_H_

class Vector3
{
private:
    float m_x, m_y, m_z;

public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3& other);
    Vector3(Vector3&& other);

    ~Vector3();

    Vector3& operator=(const Vector3& other);
    Vector3& operator=(Vector3&& other);

    float GetX(){return m_x;}
    float GetY(){return m_y;}
    float GetZ(){return m_z;}
};

#endif /* VECTOR3_H_ */
