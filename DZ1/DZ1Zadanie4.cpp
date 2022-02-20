#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

void TrapeziaMethodThreaded(double a, double b,double n, double& area)
{
    double h = (b - a) / n;
	for (int i = 1; i <= n; i++)
	{
	const double x1 = a + i*h;
        const double x2 = a + (i+1)*h;

        area = area + 0.5*(x2-x1)*(4*1/((1+x1*x1)*(1+x1*x1)) + 4*1/((1+x2*x2)*(1+x2*x2)));
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");

	// Границы интегрирования.
	double a = -1;
	double b = 1;

	chrono::high_resolution_clock::time_point t1 = chrono::high_resolution_clock::now();

	// Количество интервалов.
	double n = 100;



	cout << "Метод трапеций на 2-х потоках:" << endl;

	double area1 = 0;
	double area2 = 0;
	n = 1000000;
	t1 = chrono::high_resolution_clock::now();
	std::thread thr1(TrapeziaMethodThreaded, -1, 0, n , std::ref(area1));
	std::thread thr2(TrapeziaMethodThreaded, 0, 1, n , std::ref(area2));
	thr1.join();
	thr2.join();
	double area = area1 + area2;
	cout << area << endl;

	chrono::high_resolution_clock::time_point t2 = chrono::high_resolution_clock::now();
	chrono::duration <double> durationTrapeziaThreaded = (t2 - t1);
	cout << "Время подсчёта методом трапеций на 2-х потоках: " << durationTrapeziaThreaded.count() << " секунд." << endl << endl;



	return 0;
}