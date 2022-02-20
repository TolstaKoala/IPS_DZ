#include <iostream>
#include <math.h>
#include <chrono>
#include <thread>

using namespace std;

double TrapeziaMethodNoVector(double a, double b, double h,double n)
{
	double area = 0;
	#pragma loop(no_vector)
	for (int i = 1; i <= n; i++)
	{
		const double x1 = a + i*h;
        const double x2 = a + (i+1)*h;

        area = area + 0.5*(x2-x1)*(4*1/((1+x1*x1)*(1+x1*x1)) + 4*1/((1+x2*x2)*(1+x2*x2)));
	}

	return area;
}


int main()
{
	setlocale(LC_ALL, "Russian");

	// ������� ��������������.
	double a = -1;
	double b = 1;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	// ����� ����������.
	double n = 100;

	// ���������� ���� ���������:
	double h = (b - a) / n;

	cout << "����� ����������� ���������������:" << endl;
	cout << TrapeziaMethodNoVector(a,b,h,n) << endl;
	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration <double> durationTrapezia = (t2 - t1);
	cout << "����� �������� : " << durationTrapezia.count() << " ������." << " " << "����� ����������:"<< n << endl << endl;

	n = 1000;
	h = (b - a) / n;
	cout << TrapeziaMethodNoVector(a,b,h,n) << endl;
	t2 = chrono::high_resolution_clock::now();
	durationTrapezia = (t2 - t1);
	cout << "����� �������� : " << durationTrapezia.count() << " ������." << " " << "����� ����������:"<< n << endl << endl;

	n = 10000;
	h = (b - a) / n;
	cout << TrapeziaMethodNoVector(a,b,h,n) << endl;
	t2 = chrono::high_resolution_clock::now();
	durationTrapezia = (t2 - t1);
	cout << "����� �������� : " << durationTrapezia.count() << " ������." << " " << "����� ����������:"<< n << endl << endl;

	n = 100000;
	h = (b - a) / n;
	cout << TrapeziaMethodNoVector(a,b,h,n) << endl;
	t2 = chrono::high_resolution_clock::now();
	durationTrapezia = (t2 - t1);
	cout << "����� �������� : " << durationTrapezia.count() << " ������." << " " << "����� ����������:"<< n << endl << endl;

	n = 1000000;
	h = (b - a) / n;
	cout << TrapeziaMethodNoVector(a,b,h,n) << endl;
	t2 = chrono::high_resolution_clock::now();
	durationTrapezia = (t2 - t1);
	cout << "����� �������� : " << durationTrapezia.count() << " ������." << " " << "����� ����������:"<< n << endl << endl;

	return 0;
}