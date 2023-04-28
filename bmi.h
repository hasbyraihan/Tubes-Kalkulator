
#ifndef BMI_H
#define BMI_H
#include "UI.h"
#include <stdio.h>

typedef struct dataBMI{
	float height;
	float weight;
	float bmi;
}dataBMI;

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil BMI
 * IS			: Hasil result BMI belum ditampilkan
 * FS			: Hasil result BMI ditampilkan
 */
void resultBMI(dataBMI data);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk mengkonversi tinggi dari cm ke m
 */
float convertHeight(dataBMI data);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan BMI. Fungsi ini akan mengembalikan nilai hasil perhitungan tersebut
 */
float calculateBMI(dataBMI data);

/**
 * Deskripsi 	: Modul ini bertujuan untuk user melakukan input pada kalkulator BMI
 * IS			: User belum dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 * FS			: User dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 */
void inputBMI(dataBMI data);

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan keterangan kategori BMI
 * IS			: Keterangan kategori BMI belum ditampilkan
 * FS			: Keterangan kategori BMI ditampilkan
 */
void printCategories();

#endif