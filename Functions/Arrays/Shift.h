#pragma once
#include"constants.h"

template<typename T>void ShiftLeft(T arr[], const int n, const int number_of_shifts);
template<typename T>void ShiftRight(T arr[], const int n, const int number_of_shifts);
template<typename T>void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);
template<typename T>void ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS, const int number_of_shifts);