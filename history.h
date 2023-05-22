

#ifndef HISTORY_H
#define HISTORY_H
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "UI.h"
#include <math.h>

struct historyStdCal{
	char time[100];
	char expression[200];
    double result;
}Record;


struct historyBMICal{
	char time[100];
	float height;
	float weight;
	float bmi;
}RecordBMI;

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan save ke dalam file untuk kalkulator standar.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int saveStdHistory(char *expression, double result);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk membaca file untuk history kalkulator standar.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int showStdHistory();

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan save ke dalam file untuk kalkulator BMI.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int saveBmiHistory(float *height, float *weight, float *result);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk membaca file untuk history kalkulator BMI.
 *				  Fungsi ini akan mengembalikan nilai 1 apabila terdapat error pada saat membuka file 
 *				  dan akan mengembalikan nilai 0 apabila tidak terdapat error
 */
int showBmiHistory();

#endif