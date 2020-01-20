#pragma once
#define _USE_MATH_DEFINES
#include "Vector3.h"
#include <cmath>


class Matrix3
{

public:

	// The class has nine variables, 3 rows and 3 columns
	float m_A11;
	float m_A12;
	float m_A13;
	float m_A21;
	float m_A22;
	float m_A23;
	float m_A31;
	float m_A32;
	float m_A33;

	// Constructor 1 create a zero matrix
	Matrix3();

	// Constructor 2 To allow 3 rows of vectors to be declared as a matrix
	Matrix3(Vector3 r1, Vector3 r2, Vector3 r3);

	// Constructor 3 to allow 9 floats
	Matrix3(float t_A11, float t_A12, float t_A13,
			 float t_A21, float t_A22, float t_A23,
			  float t_A31, float t_A32, float t_A33);

	// An overloaded operator * to return the  product of the matrix by a vector
	Vector3 operator *(Vector3 V1);

	// a method to transpose a given matrix
	Matrix3 transpose();

	// An overloaded operator + to return the  sum of two matrix 
	Matrix3 operator +(Matrix3 M1);

	// An overloaded operator * to return the  difference of two matrix
	Matrix3 operator -(Matrix3 M1);

	// An overloaded operator * to return the  product of the matrix by a scalar
	Matrix3 operator *(float x);

	// An overloaded operator * to return the  product of two matrix
	Matrix3 operator *(Matrix3 M1);

	// method to return the determinant of a 3x3 matrix
	float determinant();

	// a method to return as Row as vector3 1 == first row
	Vector3 row(int i);

	// a method to return as column as vector3 1 == first column
	Vector3 column(int i);

	// method to return the inverse of a matrix if exists else zero vector
	Matrix3 inverse();

	Matrix3 rotation(float angle);

	Matrix3 translate(float dx, float dy);

	Matrix3 Scale(float dx, float dy);
	
	Matrix3 operator -();
	
	Matrix3 rotationX(float angle);

	Matrix3 rotationY(float angle);

	Matrix3 rotationZ(float angle);

	Matrix3 scale3D(float dx);

};

