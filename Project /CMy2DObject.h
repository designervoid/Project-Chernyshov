#pragma once
#include "CMy2DPoint.h"
#include "pch.h"
using namespace std;
const double radians = 3.14 / 180;
class CMy2DObject {
private:
	double a, a1, a2, a3;
	double m_dAngle;
	CMy2DPoint m_centre;
	double radian(double);
public:
	CMy2DObject();
	CMy2DObject(double, double, double, double, double, CMy2DPoint);
	void set(double, double, double, double);
	void get();
	void Move(double, double, double = 0);
	void Move(const CMy2DPoint, double = 0);
	void get_centre();
	void get_dAngle();
	double get_my_dAngle();
	void Rotate(double);
	bool IsInside(double, double);
	bool IsInside(CMy2DPoint);
};


