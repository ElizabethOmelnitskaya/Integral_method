#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

const int n = 2;
const int N = 100;

double myFunction(double x)
{
	return (cbrt(x) / ((sqrt(x) + cbrt(x))*x));
}

double Gauss(double a, double b)
{
	//n=2
	const double Xk[N] = { -0.5773503, 0.5773503 };
	const double Ak[N] = { 1.0000, 1.0000 };

	//n=3
	//const double Xk[n] = { -0.7745967, 0, 0.7745967 };
	//const double Ak[n] = { 0.5555556, 0.8888889, 0.5555556 };

	//n=5
	//const double Xk[n] = { -0.9061798, -0.5384693, 0, 0.5384693, 0.9061798 };
	//const double Ak[n] = {0.2369269, 0.4786287, 0.5688889, 0.4786287, 0.2369269};

	//n=11
	//const double Xk[n] = { -0.9782287, -0.8870626, -0.7301520, -0.5190961, -0.2695432, 0, 0.2695432, 0.5190961, 0.7301520, 0.8870626, 0.9782287 };
	//const double Ak[n] = { 0.0556686, 0.1255804, 0.1862902, 0.2331938, 0.2628045, 0.2729251, 0.2628045, 0.2331938, 0.1862902, 0.1255804, 0.0556686 };

	double ra = (b - a) / 2;
	double su = (a + b) / 2;
	double f, S=0;
	for (int i = 0; i < n; i++)
	{
		f = su + ra*Xk[i];
		S += Ak[i] * myFunction(f);
	}
	return ra*S;
}

int main()
{
	double a, b;

	cout << "Input a: "; cin >> a;
	cout << "Input b: "; cin >> b;
	cout << endl;

	double I = 0;
	for (int i = 0; i < N; ++i)
	{
		I += Gauss(a + i*(b - a) / N, a + (i + 1)*(b - a) / N);
	}
	cout << "Gauss: " << I << endl;
	cout << "Gauss: " << Gauss(a,b) << endl;
	system("pause");
	return 0;
}