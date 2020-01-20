#pragma once
#include <math.h>
#include <iostream>

class Vector3
{
public:

	float	m_x;
	float	m_y;
	float	m_z;

	void	setX(float t_x);
	void	setY(float t_y);
	void	setZ(float t_z);

	Vector3();
	Vector3(float t_x, float t_y, float t_z);
	~Vector3();


	float	length();
	float	lengthSquared();
	void	normalise();


	 Vector3	operator+(Vector3 v1);
	 Vector3	operator-(Vector3 v1);
	 float		operator*(Vector3 v1);
	 Vector3	operator *(float k);
	 Vector3	operator ^(Vector3 V1);
	 Vector3	operator - ();


	 friend Vector3 operator+(const Vector3& v1, const Vector3& v2);
	 friend Vector3 operator-(const Vector3& v1, const Vector3& v2);

	 void print();


	
};