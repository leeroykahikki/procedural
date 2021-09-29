#include <iostream>
#include <conio.h>

using namespace std;


int main()
{
	setlocale(LC_ALL, "RU");
	const unsigned int DIM1 = 3, DIM2 = 4;
	const unsigned int DIM3 = 4, DIM4 = 2;
	const int sum = 3, fee = 2;

	double A[DIM1][DIM2] = {
		{5,2,0,10},
		{3,5,2,5},
		{20,0,0,0}
	};
	double B[DIM3][DIM4] = {
		{1.20,0.50},
		{2.80,0.40},
		{5.00,1.00},
		{2.00,1.50}
	};

	double C[DIM1][DIM4];

	for (int i = 0; i < sum; i++) {
		for (int j = 0; j < fee; j++) {
			C[i][j] = 0;
			for (int k = 0; k < DIM2; k++) {
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}

	double max_profit = 0, min_profit = 100, max_fee = 0, min_fee = 100, sum_earn = 0, sum_fee = 0, sum_total = 0;
	int maxprofit_id, minprofit_id, maxfee_id, minfee_id;

	for (int i = 0; i < sum; i++)
	{
		sum_earn += C[i][0];
		sum_fee += C[i][1];
		sum_total += (C[i][0] + C[i][1]);

		if ((C[i][0] - C[i][1]) > max_profit) {
			max_profit = C[i][0] - C[i][1];
			maxprofit_id = i + 1;
		}
		if ((C[i][0] - C[i][1]) < min_profit) {
			min_profit = C[i][0] - C[i][1];
			minprofit_id = i + 1;
		}
		if (C[i][1] > max_fee) {
			max_fee = C[i][1];
			maxfee_id = i + 1;
		}
		if (C[i][1] < min_fee) {
			min_fee = C[i][1];
			minfee_id = i + 1;
		}
	}

	cout << "№ \t" << "Выручка \t" << "Комиссионные \t" << endl;
	for (int i = 0; i < sum; i++)
	{
		cout << i + 1 << "\t";
		for (int j = 0; j < fee; j++) {
			cout << C[i][j] << "\t \t";
		}
		cout << endl;
	}

	cout << endl;
	cout << "1) Наибольшая прибыль: №" << maxprofit_id << "\tНаименьшая прибыль: №" << minprofit_id << endl;
	cout << "2) Наибольшие комиссионные: №" << maxfee_id << "\tНаименьшие комиссионные: №" << minfee_id << endl;
	cout << "3) Общая сумма вырученных денег: " << sum_earn << endl;
	cout << "4) Общая сумма комиссионных: " << sum_fee << endl;
	cout << "5) Общая сумма денег: " << sum_total << endl;

	return _getch();
}