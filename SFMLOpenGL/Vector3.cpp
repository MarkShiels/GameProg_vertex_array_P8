#include "Vector3.h"

void Vector3::setX(float t_x)
{
	m_x = t_x;
}

void Vector3::setY(float t_y)
{
	m_y = t_y;
}

void Vector3::setZ(float t_z)
{
	m_z = t_z;
}

Vector3::Vector3()
{
	setX(0.0f);
	setY(0.0f);
	setZ(0.0f);
}

Vector3::Vector3(float t_x, float t_y, float t_z)
{
	setX(t_x);
	setY(t_y);
	setZ(t_z);
}

Vector3::~Vector3()
{
}

float Vector3::length()
{
	// A method to return the length of the vector
	return sqrt((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

float Vector3::lengthSquared()
{
	// A method to return the length squared of the vector
	return (m_x * m_x) + (m_y * m_y) + (m_z * m_z);
}

void Vector3::normalise()
{
	// A method to reduce the length of the vector to 1.0 
	// keeping the direction the same
		if (length() > 0.0)
		{  // Check for divide by zero
			float magnitude = length();
			m_x /= magnitude;
			m_y /= magnitude;
			m_z /= magnitude;
		}
}

Vector3 Vector3::operator+(Vector3 v1)
{
	return Vector3(m_x + v1.m_x, m_y + v1.m_y, m_z + v1.m_z);
}

Vector3 Vector3::operator-(Vector3 v1)
{
	return Vector3(m_x - v1.m_x, m_y - v1.m_y, m_z - v1.m_z);
}

float Vector3::operator*(Vector3 v1)
{
	return float(m_x * v1.m_x + m_y * v1.m_y + m_z * v1.m_z);
}

 Vector3 operator+(const Vector3& v1, const Vector3& v2)
{
	// An overloaded operator + to return the sum of 2 vectors
	return Vector3(v1.m_x + v2.m_x, v1.m_y + v2.m_y, v1.m_z + v2.m_z);
}

 Vector3 operator-(const Vector3& v1, const Vector3& v2)
 {
	 // An overloaded operator - to return the difference of 2 vectors
	 return Vector3(v1.m_x - v2.m_x, v1.m_y - v2.m_y, v1.m_z - v2.m_z);
 }

 Vector3 Vector3::operator - ()
 {
	 // An overloaded operator - to return the negation of a single vector
	 return Vector3(m_x = -m_x, m_y = -m_y, m_z = -m_z);
 }

Vector3 Vector3::operator *(float k)
 {
	// An overloaded operator * to return the product of a scalar by a vector
	 return Vector3(m_x * k, m_y * k, m_z * k);
 }

Vector3 Vector3::operator ^(Vector3 V1)
{
	// An overloaded operator ^ to return the vector product of 2 vectors
	return Vector3((m_y * V1.m_z - m_z * V1.m_y), -(m_x * V1.m_z - m_z * V1.m_x), (m_x * V1.m_y - m_y * V1.m_x));
}

void Vector3::print()
{
	std::cout << " " << m_x << " " << m_y << " " << m_z << std::endl;
}