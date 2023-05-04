
#ifndef CALCULATOR_H
#define CALCULATOR_H
#include "tree.h"
#include <math.h>

typedef struct {
	char expression[100];
	double result;
	address expressionTree;	
}Calculator;



/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator BMI yang ada pada BMI calculator belum ditampilkan
 * FS 			: Tampilan kalkulator BMI yang ada pada BMI calculator ditampilkan
 */
void showStdCalc();

/**
 * Deskripsi 	: Modul ini bertujuan untuk memberi nilai default pada attribut yang ada dalam struct Calculator
 * IS 			: Belum terdapat nilai default
 * FS 			: Attribut yang ada dalam struct Calculator diberi nilai default
 */
void createCalculator(Calculator *calculator);

/**
 * Deskripsi 	: Modul ini bertujuan untuk user menginputkan ekspresi matematika di dalam kalkulator
 * IS 			: User belum dapat melakukan input pada kalkulator
 * FS 			: User dapat melakukan input operand dan operator pada kalkulator
 */
void insertExpression(Calculator *calculator);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan dari ekspresi matematika yang diinputkan oleh user pada tree. 
 * 				  Fungsi ini akan mengembalikan nilai true jika perhitungan pada tree berhasil dilakukan
 */
boolean isCalculateSuccess(Calculator *calculator, address root);

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil ekspresi matematika yang diinputkan oleh user pada kalkulator
 * IS 			: Hasil ekspresi matematika belum ditampilkan pada kalkulator
 * FS 			: Hasil ekspresi matematika ditampilkan pada kalkulator
 */
void printResult(Calculator calculator, boolean isSuccess, address root);

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk menanyakan kepada user apakah akan mencoba kalkulator kembali atau tidak. 
 * 				  Fungsi ini akan mengembalikan nilai true apabila user menginputkan huruf 'y' atau 'Y' 
 * 				  dan akan mengembalikan nilai false apabila user menginputkan huruf 'n' atau 'N'
 */
boolean isContinueCalculator();

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk mengecek apakah terdapat karakter yang bukan operator atau tidak valid pada ekspresi yang diinputkan oleh user.
 *                Fungsi ini akan mengembalikan nilai false apabila terdapat karakter yang bukan operator atau tidak valid 
 */
boolean isValidExpression(char *expression);

/**
 * Deskripsi 	: Modul ini bertujuan untuk mengecek elemen pertama pada ekspresi matematika
 * IS 			: Belum terdidentifikasi apabila elemen pertama pada ekspresi merupakan '-'
 * FS 			: Terdidentifikasi apabila elemen pertama pada ekspresi merupakan '-'
 */
void checkMinAtFirst(char expression[]);
#endif