//NULLTerminatedLines
#include<iostream>
#include<Windows.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

int StringLength(const char str[]);
char* ToUpper(char str[]);
char* Shrink(char str[]);
bool isPalindrome(const char str[]);
bool isIntNumber(const char str[]);
int  toIntNumber(const char str[]);
bool isBinNumber(const char str[]);
bool isHexNumber(const char str[]);
unsigned long long bin2dec(const char str[]);
unsigned long long hex2dec(const char str[]);
bool isIPaddress(const char str[]);

//#define BASIC_STRING_OPERATIONS


void main()
{
	cout << sizeof(long int) << endl;
	//for (;;)cout << "Hello";
	cout << 'ё' << "\t" << 'Ё' << endl;
	cout << (int)'ё' << "\t" << (int)'Ё' << endl;
	setlocale(LC_ALL, "");
	//for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	//char str[] = "Hello";

#ifdef BASIC_STRING_OPERATIONS
	const int SIZE = 256;
	//char str[SIZE] = "Хорошо      живет     на     свете      Винни      Пух";
	char str[] = "Аргентина манит негра";
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin >> str;
	cin.getline(str, SIZE);
	SetConsoleCP(866);
	cout << str << endl;
	cout << StringLength(str) << endl;
	cout << strlen(str) << endl;//возвращает размер строки в символах
	//cout << ToUpper(str) << endl;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
	cout << Shrink(str) << endl;
	cout << "Строка " << (isPalindrome(str) ? "" : "НЕ ") << "является палиндромом" << endl;
	cout << "Строка " << (isIntNumber(str) ? "" : "НЕ ") << "является целым числом" << endl;
	int multiplier;
	cout << "Введите множитель: "; cin >> multiplier;
	cout << str << " * " << multiplier << " = " << toIntNumber(str) * multiplier << endl;
	//cout << str * 2 << endl;
	cout << str << " * " << multiplier << " = " << atoi(str)*multiplier << endl;
	//https://legacy.cplusplus.com/reference/cstdlib/atoi/  
#endif // BASIC_STRING_OPERATIONS

	const int SIZE = 65;
	char str[SIZE] = {};
	cout << "Введите двоичное число: "; //cin >> str;
	cin.getline(str, SIZE);
	//cout << "Строка " << (isBinNumber(str) ? "" : "НЕ ") << "является двоичным числом" << endl;
	//cout << bin2dec(str) << endl;

	//cout << "Строка " << (isHexNumber(str) ? "" : "НЕ ") << "является шестнадцатеричным числом" << endl;
	//cout << hex2dec(str) << endl;

	cout << "Строка " << (isIPaddress(str) ? "" : "НЕ ") << "является IP-адресом\n";

	main();
}

int StringLength(const char str[])
{
	int i = 0;
	for (; str[i]; i++);
	return i;
}
char* ToUpper(char str[])
{
	//	  counter ; condition; expression
	for (int i = 0; str[i]; i++)
	{
		/*if (str[i] >= 'a' && str[i] <= 'z')str[i] -= ' ';
		if (str[i] >= 'а' && str[i] <= 'я')str[i] -= ' ';
		if (str[i] == 'ё')str[i] -= 16;*/
		str[i] = toupper(str[i]);//https://legacy.cplusplus.com/reference/cctype/tolower/
	}
	return str;
}
char* Shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
char* RemoveSymbol(char str[], const char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)str[j] = str[j + 1];
		}
	}
	return str;
}
bool isPalindrome(const char str[])
{
	int n = strlen(str);
	char* buffer = new char[n + 1]{};
	for (int i = 0; str[i]; i++)buffer[i] = str[i];
	ToUpper(buffer);
	n = strlen(RemoveSymbol(buffer, ' '));
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}
bool isIntNumber(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		//if (str[i] == ' ')continue;
		if (str[i]<'0' || str[i]>'9')return false;
	}
	return true;
}
int  toIntNumber(const char str[])
{
	if (!isIntNumber(str))return INT_MIN;
	int number = 0;
	//int weight = 1;	//Весовой коэффициент разряда
	for (int i = 0; str[i]; i++)
	{
		number = number * 10 + str[i] - '0';
	}
	return number;
}
//int contiguousSymbolsCount(const char str[], const char symbol)
//{
//	for (int i = 0; str[i]; i++)
//	{
//		if (str[i] != symbol)return i;
//	}
//}
bool isBinNumber(const char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (str[i] != '0' && str[i] != '1')return false;
	}
	return true;
}
bool isHexNumber(const char str[])
{
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		if ((str[i] <'0' || str[i]>'9') && (str[i]<'A' || str[i]>'F') && (str[i]<'a' || str[i]>'f'))
			return false;
	}
	return true;
}
unsigned long long bin2dec(const char str[])
{
	if (!isBinNumber(str))return ULLONG_MAX;
	unsigned long long int decimal = 0;
	for (int i = 0; str[i]; i++)
	{
		decimal = decimal * 2 + str[i] - '0';
	}
	return decimal;
}
unsigned long long hex2dec(const char str[])
{
	if (!isHexNumber(str))return ULLONG_MAX;
	unsigned long long decimal = 0;
	for (int i = str[0] == '0' && str[1] == 'x' ? 2 : 0; str[i]; i++)
	{
		char hex_digit = str[i];
		if (hex_digit >= '0' && hex_digit <= '9')hex_digit -= '0';
		if (hex_digit >= 'A' && hex_digit <= 'F')(hex_digit -= 'A') += 10;
		if (hex_digit >= 'a' && hex_digit <= 'f')(hex_digit -= 'a') += 10;
		decimal = decimal * 16 + hex_digit;
	}
	return decimal;
}

bool isIPaddress(const char str[])
{
	int n = strlen(str);
	if (n < 7 || n > 15)return false;
	char byte[4] = {};
	for (int i = 0, j = 0,points=0; str[i]; i++)
	{
		if (str[i] == '.')
		{
			j = 0;
			points++;
			if (points > 3)return false;
			if (toIntNumber(byte) > 255)return false;
			continue;
		}
		byte[j++] = str[i];
		if (j > 3)return false;
	}
	return true;
}
//bool isIPaddress(const char str[])
//{
//	int n = strlen(str);
//	if (n < 7 || n > 15)return false;
//	char bytes[4][4] = {};
//	for (int i = 0, j = 0,k=0; str[i]; i++)
//	{
//		if (str[i] == '.')
//		{
//			j++;
//			if (j > 3)return false;
//			k = 0;
//			continue;
//		}
//		bytes[j][k++] = str[i];
//	}
//	for (int i = 0; i < 4; i++)
//	{
//		if (toIntNumber(bytes[i]) > 255)return false;
//		cout << bytes[i] << "\t";
//	}
//	cout << endl;
//	return true;
//}