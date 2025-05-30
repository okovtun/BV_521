#pragma once
#include"stdafx.h"
#include"constants.h"

//template - создание шаблона
//typename - создает шаблонный тип данных
//T - это имя шаблонного типа (T - type)
template<typename T>void Print(T arr[], const int n);
template<typename T>void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);