#include "pch.h"
#include "CMy2DPoint.h"
CMy2DPoint::CMy2DPoint()
{
	x[0] = 0;
	x[1] = 0;
}
CMy2DPoint::CMy2DPoint(double param1, double param2)
{
	x[0] = param1;
	x[1] = param2;
}

CMy2DPoint::~CMy2DPoint()
{
	//std::cout << "Destroying the object" << std::endl;
}

CMy2DPoint CMy2DPoint::operator+(CMy2DPoint op2)
{
	CMy2DPoint temp;
	temp.x[0] = x[0] + op2.x[0];
	temp.x[1] = x[1] + op2.x[1];
	return temp;
}

CMy2DPoint operator-(CMy2DPoint op1, CMy2DPoint op2)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] - op2.x[0];
	temp.x[1] = op1.x[1] - op2.x[1];
	return temp;
}

CMy2DPoint operator+(CMy2DPoint op1, double param)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] + param;
	temp.x[1] = op1.x[1] + param;
	return temp;
}

CMy2DPoint operator+(double param, CMy2DPoint op1)
{
	CMy2DPoint temp;
	temp.x[0] = param + op1.x[0];
	temp.x[1] = param + op1.x[1];
	return temp;
}

CMy2DPoint operator-(CMy2DPoint op1, double param)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] - param;
	temp.x[1] = op1.x[1] - param;
	return temp;
}

CMy2DPoint operator-(double param, CMy2DPoint op1)
{
	CMy2DPoint temp;
	temp.x[0] = param - op1.x[0];
	temp.x[1] = param - op1.x[1];
	return temp;
}

CMy2DPoint operator*(CMy2DPoint op1, CMy2DPoint op2)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] * op2.x[0];
	temp.x[1] = op1.x[1] * op2.x[1];
	return temp;
}

CMy2DPoint operator*(CMy2DPoint op1, double param)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] * param;
	temp.x[1] = op1.x[1] * param;
	return temp;
}

CMy2DPoint operator*(double param, CMy2DPoint op1)
{
	CMy2DPoint temp;
	temp.x[0] = param * op1.x[0];
	temp.x[1] = param * op1.x[1];
	return temp;
}

CMy2DPoint operator/(CMy2DPoint op1, CMy2DPoint op2)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] / op2.x[0];
	temp.x[1] = op1.x[1] / op2.x[1];
	return temp;
}

CMy2DPoint operator/(CMy2DPoint op1, double param)
{
	CMy2DPoint temp;
	temp.x[0] = op1.x[0] / param;
	temp.x[1] = op1.x[1] / param;
	return temp;
}

CMy2DPoint operator/(double param, CMy2DPoint)
{
	CMy2DPoint temp;
	temp.x[0] = param / temp.x[0];
	temp.x[1] = param / temp.x[1];
	return temp;
}

int operator==(CMy2DPoint op1, CMy2DPoint op2)
{
		if (op1.x[0] == op2.x[0] && op1.x[1] == op2.x[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operator==(CMy2DPoint op1, double param)
{
	if (op1.x[0] == param && op1.x[1] == param)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operator==(double param, CMy2DPoint op1)
{
	if (param == op1.x[0] && param == op1.x[1])
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int operator!=(CMy2DPoint op1, CMy2DPoint op2)
{
	if (op1.x[0] == op2.x[0] && op1.x[1] == op2.x[1])
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int operator!=(CMy2DPoint op1, double param)
{
	if (op1.x[0] == param && op1.x[1] == param)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int operator!=(double param, CMy2DPoint op1)
{
	if (param == op1.x[0] && param == op1.x[1])
	{
		return 0;
	}
	else
	{
		return 1;
	} 
}

std::istream &operator>>(std::istream &stream, CMy2DPoint &op2)
{
	std::cout << "Input coordinates x and y:" << std::endl;
	stream >> op2.x[0] >> op2.x[1];
	return stream;
}

std::ostream &operator<<(std::ostream &stream, CMy2DPoint &op2)
{
	stream << "(" << op2.x[0] << ", " << op2.x[1] << ")" << std::endl;
	return stream;
}

