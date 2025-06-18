#include<FillRand.h>
#include<Print.h>
#include<Sort.h>
#include<Statistics.h>
#include"Kaktotak.h"

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	FillRand(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(arr, n) << endl;
	Sort(arr, n);
	Print(arr, n);
}