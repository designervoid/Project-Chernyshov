#pragma once
#include "pch.h"
#ifndef CMy2DPoint_H
#define CMy2DPoint_H
#include <iostream>
using namespace std;
class CMy2DPoint
{
	double x[2];
public:
	CMy2DPoint();
	CMy2DPoint(double, double);
	CMy2DPoint operator+(CMy2DPoint);
	friend CMy2DPoint operator+(CMy2DPoint, double);
	friend CMy2DPoint operator+(double, CMy2DPoint);
	friend CMy2DPoint operator-(CMy2DPoint, CMy2DPoint);
	friend CMy2DPoint operator-(CMy2DPoint, double);
	friend CMy2DPoint operator-(double, CMy2DPoint);
	friend CMy2DPoint operator*(CMy2DPoint, CMy2DPoint);
	friend CMy2DPoint operator*(double, CMy2DPoint);
	friend CMy2DPoint operator*(CMy2DPoint, double);
	friend CMy2DPoint operator/(CMy2DPoint, CMy2DPoint);
	friend CMy2DPoint operator/(CMy2DPoint, double);
	friend CMy2DPoint operator/(double, CMy2DPoint);
	friend int operator==(CMy2DPoint, CMy2DPoint);
	friend int operator==(CMy2DPoint, double);
	friend int operator==(double, CMy2DPoint);
	friend int operator!=(CMy2DPoint, CMy2DPoint);
	friend int operator!=(CMy2DPoint, double);
	friend int operator!=(double, CMy2DPoint);
	friend std::istream &operator>>(std::istream &stream, CMy2DPoint &op2);
	friend std::ostream &operator<<(std::ostream &stream, CMy2DPoint &op2);
	void set_x(double a) { x[0] = a; };
	void set_y(double b) { x[1] = b; };
	double get_x() { return x[0]; };
	double get_y() { return x[1]; };

	~CMy2DPoint();
};

#endif CMy2DPoint_H
