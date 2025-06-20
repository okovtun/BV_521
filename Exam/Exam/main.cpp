#include<iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "");
	cout << sizeof(bool) << endl;
	cout << typeid('+').name() << endl;
}