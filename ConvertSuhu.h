#ifndef ConvertSuhu_H
#define ConvertSuhu_h
#include <stdio.h>
#include "math.h"
#include <string.h>
void showkonv();
double ConCel();
double ConReam();
double ConKelv();
double ConFahr();
// Fungsi untuk mengubah Celcius menjadi Fahrenheit
double ConCelFahr(double celc);

// Fungsi untuk mengubah Celcius menjadi Kelvin
double ConCelKelv(double celc);

// Fungsi untuk mengubah Celcius menjadi Reamur
double ConCelReam(double celc);

// Fungsi untuk mengubah Fahrenheit menjadi Celcius
double ConFahrCel(double fahr);

// Fungsi untuk mengubah Fahrenheit menjadi Kelvin
double ConFahrKelv(double fahr);

// Fungsi untuk mengubah Fahrenheit menjadi Reamur
double ConFahrReam(double fahr);

// Fungsi untuk mengubah Kelvin menjadi Celcius
double ConKelvCel(double fahr);

// Fungsi untuk mengubah Kelvin menjadi Fahrenheit
double ConKelvFahr(double fahr);

// Fungsi untuk mengubah Kelvin menjadi Reamur
double ConKelvReam(double fahr);

// Fungsi untuk mengubah Reamur menjadi Celcius
double ConReamCel(double ream);

// Fungsi untuk mengubah Reamur menjadi Fahrenheit
double ConReamFahr(double ream);

// Fungsi untuk mengubah Reamur menjadi Kelvin
double ConReamKelv(double ream);
#endif