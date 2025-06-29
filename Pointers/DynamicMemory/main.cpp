﻿//DynamicMemory
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

int** Allocate(const int rows, const int cols);
void Clear(int**& arr, const int rows, const int cols = 0);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void Print(int arr[], const int n);
void Print(int** arr, const int rows, const int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);

int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);

int** push_row_back(int** arr, int& rows, const int cols);
int** insert_row(int** arr, int& rows, const int cols, const int index);

void push_col_back(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];	//Объявление динамического массива
	//short  - short
	//short* - Указатель на 'short';
	//int  - 'int';
	//int* - Указатель на 'int';
	//double  - 'double';
	//double* - Указатель на 'double';

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	arr = pop_front(arr, n);
	Print(arr, n);

	delete[] arr;
	//Memory leak - утечка памяти.  
#endif // DYNAMIC_MEMORY_1

	int rows;
	int cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** arr = Allocate(rows, cols);

	//Copy	  - функция НЕ изменяет переданную в нее память, а возвращает измененную копию полученной памяти.
	//Mutable - Функция изменяет полученный блок памяти;

	///	///////////////////////////////////////////////////////////////	///

	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	for (int i = 0; i < rows; i++)arr[i][cols - 1] = rand() % 1000;
	Print(arr, rows, cols);

	int index;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	arr = insert_row(arr, rows, cols, index);
	Print(arr, rows, cols);

	///	///////////////////////////////////////////////////////////////	///

	Clear(arr, rows, cols);

}

int** Allocate(const int rows, const int cols)
{
	///////////////////////////////////////////////////////////////////////
	////////		Объявление двумерного динамического массива		///////
	///////////////////////////////////////////////////////////////////////

	//1) Содаем массив указателей:
	int** arr = new int*[rows];

	//2) Выделяем память под строки:
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}

	return arr;
}
void Clear(int**& arr, const int rows, const int cols)
{
	///////////////////////////////////////////////////////////////////////
	////////		Удаление двумерного динамического массива		///////
	///////////////////////////////////////////////////////////////////////

	//1) Сначала удаляются строки двумерного массива:
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}

	//2) Только теперь можно удалить массив указателей:
	delete[] arr;

	//3) Зануляем указатель на массив
	arr = nullptr;
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;	//Через арифметику указателей и оператор разыменования
	}
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void Print(int arr[], const int n)
{
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << "\t";		//Через оператор индексирования (Subscript operator)
	}
	cout << endl;
}
void Print(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}

int* push_back(int arr[], int& n, const int value)
{
	//1) Создаем буферный массив нужного размера:
	int* buffer = new int[n + 1];

	//2) Копируем все элементы из исходного массива в буферный:
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив:
	delete[] arr;

	//4) Подменяем адрес исходного массива адресом нового массива:
	arr = buffer;
	//buffer = nullptr;	//nullptr - это указатель на 0;

	//5) Только после всего вышенаписанного в массиве 'arr' появляется элемент,
	//	 в который можно сохранить добавляемое значени:
	arr[n] = value;

	//6) После добавления элемента в массив, количество его элементов увеличивается на 1:
	n++;

	//7) Mission complete - значение добавлено.
	return buffer;
}

int* push_front(int arr[], int& n, const int value)
{
	//1) 
	int* buffer = new int[n + 1];
	//2)
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	//3)
	delete[] arr;

	//4)
	buffer[0] = value;

	//5)
	n++;

	return buffer;
}

int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)buffer[i] = arr[i + 1];
	delete[] arr;
	return buffer;
}

int** push_row_back(int** arr, int& rows, const int cols)
{
	//1) Создаем буферный массив указателей нужного размера:
	int** buffer = new int*[rows + 1];

	//2) Копируем адреса строк в новый массив:
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];
	}

	//3) Удаляем исходный массив указателейЖ
	delete[] arr;

	//4) Добавляем добавляемую строку:
	buffer[rows] = new int[cols] {};

	//5) После добавления строки, количество строк увеличивается на 1:
	rows++;

	//6) Возвращаем новый массив:
	return buffer;
}
int** insert_row(int** arr, int& rows, const int cols, const int index)
{
	if (index<0 || index>rows)
	{
		cout << "Error: Out of range exception" << endl;
		return arr;
	}
	int** buffer = new int*[rows + 1]{};
	/*for (int i = 0; i < index; i++)buffer[i] = arr[i];
	for (int i = index; i < rows; i++)buffer[i + 1] = arr[i];*/
	for (int i = 0; i < rows; i++)
	{
		//if (i < index)buffer[i] = arr[i];
		//else buffer[i + 1] = arr[i];
		//i < index ? buffer[i] = arr[i] : buffer[i + 1] = arr[i];
		buffer[i < index ? i : i + 1] = arr[i];
	}
	delete[] arr;
	buffer[index] = new int[cols] {};
	rows++;
	return buffer;
}

void push_col_back(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		//1) Создаем буяерную строку нужного размера:
		int* buffer = new int[cols + 1]{};
		//2) Копируем элементы из исходной строки в буферную:
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		//3) Удаляем исходную строку:
		delete[] arr[i];
		//4) Подменяем адрес исходной строки адресом новой строки:
		arr[i] = buffer;
	}
	cols++;
}