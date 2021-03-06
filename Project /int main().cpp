#include "pch.h"
#include <cmath>
#include <iostream>
#include "CMy2DPoint.h"
#include "CMy2DObject.h"
using namespace std;
int main()
{
	double a, a1, a2, a3, x_c, y_c, u;
	
		cout << "Input parametrs figure: " << endl;
		cout << "Side of figure - a: \t";
		cin >> a;
		cout << "Radius of figure - a1: \t";
		cin >> a1;
		cout << "Radius of figure - a2: \t";
		cin >> a2;
		cout << "Radius of figure - a3: \t";
		cin >> a3;
		cout << "Dot X centre - x_c: \t";
		cin >> x_c;
		cout << "Dot Y centre - y_c: \t";
		cin >> y_c;
		cout << "Input dangle: \t";
		cin >> u;
		cout << endl;

		

		CMy2DPoint dot(x_c, y_c);

		CMy2DObject b(a, a1, a2, a3, u, dot);
		b.set(a, a1, a2, a3);
		b.get();
		b.get_dAngle();
		b.Rotate(u);
		cout << "After rotate: \t" << endl;
		b.get_dAngle();
		cout << endl;

		double a_, b_;
		cout << "Move your figure: dx, dy" << endl;
		cout << "dx: \t"; cin >> a_;
		cout << "dy: \t"; cin >> b_;
		cout << endl;

		b.Move(a_, b_);
		cout << "Centre dot after moving: \t";
		b.get_centre();
		cout << endl;

		double amount, range1, range2;
		cout << "Input range for dot [a, b]: " << endl;
		cout << "Input a: \t"; cin >> range1;
		cout << "Input b: \t"; cin >> range2;
		cout << endl;
		cout << "Your diapozone is [" << range1 << ", " << range2 << "]" << endl;
		int range3 = (range2 - (range1 / 2));
		cout << "Input amount of dots: \t"; cin >> amount;
			for (int i = 0; i <= amount; i++)
			{
				double r1 = rand() % range3;
				double r2 = rand() % range3;
				CMy2DPoint p(r1, r2);
				if (b.IsInside(p))
				{
					cout << "Dot x, y: (" << r1 << ", " << r2 << ") is inside figure" << endl;
				}
				else
				{
					cout << "Dot x, y: (" << r1 << ", " << r2 << ") is not inside figure" << endl;
				}
			}
		system("pause");
		return 0;
}