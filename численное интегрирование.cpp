#include <iostream>
#include <math.h>

using namespace std;

double myFunction(double x){
	return (cbrt(x) / ((sqrt(x) + cbrt(x))*x));
}

double leftSide(double a, double b, double n){  //левые
	if (a == b) return 0;
	if (a > b) { double tmp = a; a = b; b = tmp;}
	double result = 0;
	double h = (b - a) / n;
	for (double i = a; i < b; i += h) {
		result += h*myFunction(i);
	}
	return result;
}

double rightSide(double a, double b, double n){ //правые
	if (a == b) return 0;
	if (a > b) { double tmp = a; a = b; b = tmp; }
	double result = 0;
	double h = (b - a) / n;
	for (double i = a; i < b - h / 2; i += h) {
		result += myFunction(i + h)*h;
	}
	return result;
}

double central(double a, double b, double n){   //центральные
	if (a == b) return 0;
	if (a > b) { double tmp = a; a = b; b = tmp; }
	double result = 0;
	double h = (b - a) / n;
	for (double i = a; i < b - h / 2; i += h) {
		result += myFunction(i + h / 2)*h;
	}
	return result;
}

double trapezoidal(double a, double b, double n){  //трапеции
	if (a == b) return 0;
	if (a > b) { double tmp = a; a = b; b = tmp; }
	double result = 0;
	double h = (b - a) / n;
	for (double i = 1; i < n ; i ++) {
		result += myFunction(a + h * i);
	}
	result += (myFunction(a) + myFunction(b)) / 2;
	result *= h;

	return result;
}

double Simpson(double a, double b, int n)
{
	if (a == b) return 0;
	if (a > b){ double tmp = a; a = b; b = tmp; }
	double result = 0;
	double h = (b - a) / (2 * n);
	for (int k = 1; k < n; k++)	{
		result += 4 * myFunction(a + h*(2 * k - 1));//Значения с нечётными индексами, которые нужно умножить на 4.
		result += 2 * myFunction(a + h * 2 * k);//Значения с чётными индексами, которые нужно умножить на 2.
	}
	result += 4 * myFunction(b - h) + myFunction(a) + myFunction(b);
	result *= h / 3;
	return result;
}

const int N = 5;

double Gauss(double a, double b){
	if (a == b) return 0;
	if (a > b){ double tmp = a; a = b; b = tmp; }
	double result = 0;

	//n=5
	const double Xk[N] = { -0.9061798, -0.5384693, 0, 0.5384693, 0.9061798 };
	const double Ak[N] = {0.2369269, 0.4786287, 0.5688889, 0.4786287, 0.2369269};
	
	//n=11
	//const double Xk[N] = { -0.9782287, -0.8870626, -0.7301520, -0.5190961, -0.2695432, 0, 0.2695432, 0.5190961, 0.7301520, 0.8870626, 0.9782287 };
	//const double Ak[N] = { 0.0556686, 0.1255804, 0.1862902, 0.2331938, 0.2628045, 0.2729251, 0.2628045, 0.2331938, 0.1862902, 0.1255804, 0.0556686 };

	double ra = (b - a) / 2;
	double su = (b + a) / 2;
	double f, S = 0;
	for (int i = 0; i < N; i++){
		f = su + ra*Xk[i];
		S += Ak[i] * myFunction(f);
	}
	result = ra*S;
	return result;
}

int main(){

	int n = 20;
	double a, b;

	cout << "Input a: "; cin >> a;
	cout << "Input b: "; cin >> b;
	cout << endl;

	cout << "trapezoidal: " << trapezoidal(a, b, n) << endl << endl;
	cout << "Simpson: " << Simpson(a, b, n) << endl << endl;
	cout << "leftSide: " << leftSide(a, b, n) << endl << endl;
	cout << "rightSide: " << rightSide(a, b, n) << endl << endl;
	cout << "central: " << central(a, b, n) << endl << endl;
	cout << "Gauss: " << Gauss(a, b) << endl << endl;
	
	system("pause");
	return 0;
}