#include"stdafx.h"
#include"constants.h"
#include"FillRand.h"
//#include"FillRand.cpp"//Реализации НЕшаблонных функций НИКОГДА НЕ ПОДКЛЮЧАЮТСЯ НА МЕСТО ВЫЗОВА
#include"Print.h"
#include"Print.cpp"		//Реализации шаблонных функций В ОБЯЗАТЕЛЬНОМ ПОРЯДКЕ ПОДКЛЮЧАЮТСЯ НА МЕСТО ВЫЗОВА

template<typename T>void Sort(T arr[], const int n);
template<typename T>void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T Sum(T arr[], const int n);
template<typename T>T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>double Avg(T arr[], const int n);
template<typename T>double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>T minValueIn(T arr[], const int n);
template<typename T>T minValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);
template<typename T>T maxValueIn(T arr[], const int n);
template<typename T>T maxValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS);

template<typename T>void ShiftLeft(T arr[], const int n, const int number_of_shifts);
template<typename T>void ShiftRight(T arr[], const int n, const int number_of_shifts);
template<typename T>void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);
template<typename T>void ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	int arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	//FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);
	cout << "Сумма элементов массива: " << Sum(arr, n) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(arr, n) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(arr, n) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(arr, n) << endl;

	int number_of_shifts;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	ShiftRight(arr, n, number_of_shifts);
	Print(arr, n);

	const int SIZE = 8;
	double brr[SIZE];
	FillRand(brr, SIZE);
	Print(brr, SIZE);
	Sort(brr, SIZE);
	Print(brr, SIZE);
	cout << "Сумма элементов массива: " << Sum(brr, SIZE) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(brr, SIZE) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(brr, SIZE) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(brr, SIZE) << endl;

	int i_arr_2[ROWS][COLS];
	FillRand(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	Sort(i_arr_2, ROWS, COLS);
	Print(i_arr_2, ROWS, COLS);
	cout << "Сумма элементов массива: " << Sum(i_arr_2, ROWS, COLS) << endl;
	cout << "Среднее-арифметическое элементов массива: " << Avg(i_arr_2, ROWS, COLS) << endl;
	cout << "Минимальное значение в массиве: " << minValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Максимальное значение в массиве: " << maxValueIn(i_arr_2, ROWS, COLS) << endl;
	cout << "Введите количество сдвигов: "; cin >> number_of_shifts;
	ShiftRight(i_arr_2, ROWS, COLS, number_of_shifts);
	Print(i_arr_2, ROWS, COLS);

}


template<typename T>void Sort(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[i])
			{
				T buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
		}
	}
}
template<typename T>void Sort(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
				{
					if (arr[k][l] < arr[i][j])
					{
						T buffer = arr[i][j];
						arr[i][j] = arr[k][l];
						arr[k][l] = buffer;
					}
				}
			}
		}
	}
}
template<typename T>T Sum(T arr[], const int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += arr[i];
	}
	return sum;
}
template<typename T>T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T sum = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			sum += arr[i][j];
		}
	}
	return sum;
}
template<typename T>double Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}
template<typename T>double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	return (double)Sum(arr, ROWS, COLS) / ROWS / COLS;
}
template<typename T>T minValueIn(T arr[], const int n)
{
	T min = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)min = arr[i];
	}
	return min;
}
template<typename T>T minValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T min = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] < min)min = arr[i][j];
		}
	}
	return min;
}
template<typename T>T maxValueIn(T arr[], const int n)
{
	T max = arr[0];
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)max = arr[i];
	}
	return max;
}
template<typename T>T maxValueIn(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T max = arr[0][0];
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			if (arr[i][j] > max)max = arr[i][j];
		}
	}
	return max;
}
template<typename T>void ShiftLeft(T arr[], const int n, const int number_of_shifts)
{
	for (int i = 0; i < number_of_shifts; i++)
	{
		T buffer = arr[0];
		for (int i = 1; i < n; i++)
		{
			arr[i - 1] = arr[i];
		}
		arr[n - 1] = buffer;
	}
}
template<typename T>void ShiftRight(T arr[], const int n, const int number_of_shifts)
{
	ShiftLeft(arr, n, n - number_of_shifts);
}

template<typename T>void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	/*for (int i = 0; i < ROWS; i++)
	{
		ShiftLeft(arr[i], COLS, number_of_shifts);
	}*/
	for (int i = 0; i < number_of_shifts; i++)
	{
		T buffer = arr[0][0];
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 1; j < COLS; j++)
			{
				arr[i][j - 1] = arr[i][j];
			}
			arr[i][COLS - 1] = arr[i + 1][0];
		}
		arr[ROWS - 1][COLS - 1] = buffer;
	}
}
template<typename T>void ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts)
{
	/*for (int i = 0; i < ROWS; i++)
	{
		ShiftRight(arr[i], COLS, number_of_shifts);
	}*/
	for (int i = 0; i < number_of_shifts; i++)
	{
		T buffer = arr[ROWS - 1][COLS - 1];
		for (int i = ROWS - 1; i >= 0; i--)
		{
			for (int j = COLS - 2; j >= 0; j--)
			{
				arr[i][j+1] = arr[i][j];
			}
			arr[i][0] = arr[i - 1][COLS - 1];
		}
		arr[0][0] = buffer;
	}
}