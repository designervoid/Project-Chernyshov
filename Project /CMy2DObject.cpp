#include "pch.h"
#include "CMy2DPoint.h"
#include "CMy2DObject.h"
using namespace std;

CMy2DObject::CMy2DObject()
{
	CMy2DPoint point(0, 0);
	a = 0;
	a1 = 0;
	a2 = 0;
	a3 = 0;
	m_dAngle = 0;
	m_centre = point;
}

CMy2DObject::CMy2DObject(double value, double value1, double value2, double value3, double angle, CMy2DPoint my_centre)
{
		a = value;
		a1 = value1;
		a2 = value2;
		a3 = value3;
		m_dAngle = radian(angle);
		m_centre = my_centre;
}

double CMy2DObject::radian(double my_angle)
{
	return my_angle * radians;
}

void CMy2DObject::set(double value, double value1, double value2, double value3) {
	const double hypotenuse = value * 1.118;
	while ((value2 + value3 > value 
			&& value1 + value2 > hypotenuse 
			&& value2 + value3 > hypotenuse) 
			|| (value < 0) 
			|| (value1 < 0)	
			|| (value2 < 0) 
			|| (value3 < 0) 
			|| (value == 0))
	{
		cout << "figure is self-instructed or you was input negative numbers, try again: " << endl;
		cout << "Input a: \t";  cin >> value;
		cout << "Input a1: \t"; cin >> value1;
		cout << "Input a2: \t"; cin >> value2;
		cout << "Input a3: \t"; cin >> value3;
		if (value < 0) {
			cout << "You input negative A!" << endl;
			cout << "Try again. Input new A: \t";
			cin >> value;
			a = value;
		}
		if (value1 < 0) {
			cout << "You input negative radius A1!" << endl;
			cout << "Try again. Input new A1: \t";
			cin >> value1;
			a1 = value1;
		}
		if (value2 < 0) {
			cout << "You input negative radius A2!" << endl;
			cout << "Try again. Input new A2: \t";
			cin >> value2;
			a2 = value2;
		}
		if (value3 < 0) {
			cout << "You input negative radius A3!" << endl;
			cout << "Try again. Input new A3: \t";
			cin >> value3;
			a3 = value3;
		}
		if (value == 0) {
			cout << "You dont input A!" << endl;
			cout << "Try again. Input new A: \t";
			cin >> value;
			a = value;
		}
		if (value > 0 && value1 >= 0 && value2 >= 0 && value3 >= 0 && value2 + value3 < value && value1 + value2 < value * 1.118 && value2 + value3 < value * 1.118) {
			a = value;
			a1 = value1;
			a2 = value2;
			a3 = value3;
		}
	}
}

void CMy2DObject::get() {
		cout << "A side: \t"			<< a << endl;
		cout << "A1 - radius: \t"		<< a1 << endl;
		cout << "A2 - radius: \t"		<< a2 << endl;
		cout << "A3 - radius: \t"		<< a3 << endl;
		cout << "Figure was created"	<< endl;
}

void CMy2DObject::Rotate(double dAngle)
{
		m_dAngle += radian(dAngle);
	}


void CMy2DObject::Move(double dx, double dy, double my_angle) {
		m_centre.set_x(dx + m_centre.get_x());
		m_centre.set_y(dy + m_centre.get_y());
		m_dAngle += radian(my_angle);
}


void CMy2DObject::Move(const CMy2DPoint delta, double my_angle)
{
		m_centre = m_centre + delta;
		m_dAngle += radian(my_angle);
}

void CMy2DObject::get_centre()
{
		cout << "(" << m_centre.get_x() << ", " << m_centre.get_y() << ")" << endl;
}

void CMy2DObject::get_dAngle()
{
		cout << "Angle in radians = \t" << m_dAngle << endl;
}

double CMy2DObject::get_my_dAngle()
{
		return m_dAngle;
}

/*bool CMy2DObject::IsInside(double x, double y) {
	double z1, z2, z3;
	static double a_ = a / 2;

	z1 = sqrt((x - (m_centre.get_x() + (a_)))*(x - (m_centre.get_x() + (a_))) + (y - m_centre.get_y())*(y - m_centre.get_y()));
	z2 = sqrt((x - (m_centre.get_x() - (a_)))*(x - (m_centre.get_x() - (a_))) + (y - (m_centre.get_y() + (a_))*(y - (m_centre.get_y() + (a_)))));
	z3 = sqrt((x - (m_centre.get_x() - (a_)))*(x - (m_centre.get_x() - (a_))) + (y - (m_centre.get_y() - (a_))*(y - (m_centre.get_y() - (a_)))));
	bool s = ((x < (m_centre.get_x() - (a_)) || (x < (m_centre.get_x() + (a_)) || (y < (m_centre.get_y() - (a_)) || (y < (m_centre.get_y() + (a_))) || (z1 <= a1) || (z2 <= a2) || (z3 <= a3)))));
	if (s != 1) return 1;
	else return 0;
	//return (s == 1) ? false : true;
}*/
bool CMy2DObject::IsInside(double x, double y)
{
	static double a_half = a / 2;
		double temp_x = m_centre.get_x() - m_centre.get_x() * (1 - cos(m_dAngle));
		double temp_y = m_centre.get_y() + m_centre.get_x() * sin(-m_dAngle);
		if ((x >= temp_x - a_half) &&
			(x <= temp_x + a_half) &&
			(y >= temp_y - a_half) &&
			(y <= temp_y + a_half) &&
			(((x - (temp_x + a_half))*(x - (temp_x + a_half)) +
			(y - temp_y)*(y - temp_y) - a1 * a1) >= 0) &&
			(((x - (temp_x - a_half))*(x - (temp_x - a_half)) +
			(y - (temp_y - a_half))*(y - (temp_y - a_half)) - a3 * a3) >= 0) &&
			((y - x - ((temp_y + a_half - a2) - temp_x + a_half)) <= 0)
		)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
bool CMy2DObject::IsInside(CMy2DPoint point) {
	static double a_half = a / 2;
		double temp_x = m_centre.get_x() - m_centre.get_x() * (1 - cos(m_dAngle));
		double temp_y = m_centre.get_y() + m_centre.get_x() * sin(-m_dAngle);
		if ((point.get_x() >= temp_x - a_half) &&
			(point.get_x() <= temp_x + a_half) &&
			(point.get_y() >= temp_y - a_half) &&
			(point.get_y() <= temp_y + a_half) &&
			(((point.get_x() - (temp_x + a_half))*(point.get_x() - (temp_x + a_half)) +
			(point.get_y() - temp_y)*(point.get_y() - temp_y) - a1 * a1) >= 0) &&
			(((point.get_x() - (temp_x - a_half))*(point.get_x() - (temp_x - a_half)) +
			(point.get_y() - (temp_y - a_half))*(point.get_y() - (temp_y - a_half)) - a3 * a3) >= 0) &&
				((point.get_y() - point.get_x() - ((temp_y + a_half - a2) - temp_x + a / 2)) <= 0)
		)
		{
			return 1;
		}
		else
		{
			return 0;
		}
}
