#include<iostream>
using namespace std;

//#define POINTERS_BASICS

void main()
{
	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl;	//вывод переменной 'a' на экран;
	cout << &a << endl;	//взятие адреса переменной 'a' прямо при выводе;
	cout << pa << endl; //вывод адреса переменной 'a', хранящегося в указателе 'pa';
	cout << *pa << endl;//разыменование указателя 'pa', и вывод на экран значения по адресу;

	int* pb;
	int b = 3;
	pb = &b;
	cout << pb << endl;
	cout << *pb << endl;

	//int  - 'int';
	//int* - Указатель на 'int';
	//double  - 'double';
	//double* - Указатель на 'double';  
#endif // POINTERS_BASICS

	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;
}

/*
-----------------------------------------
& - оператор взятия адреса (Address-of operator)
* - оператор разыменования (Dereference operator)
-----------------------------------------
*/

/*
-----------------------------------------
+
-
++
--
-----------------------------------------
*/