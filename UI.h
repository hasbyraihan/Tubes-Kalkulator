#ifndef UI_H
#define UI_H
#include <stdio.h>
#include <windows.h>
#include <MMsystem.h>
#include <ctype.h>
#include <conio.h>
#include <unistd.h>

/**
 * Author 		: Cprogramming.com
 * Deskripsi 	: Kursor untuk menunjuk pada titik (x,y) tertentu
 * IS 			: Kursor masih menunjuk titik awal.
 * FS 			: kursor menunjuk titik yang didefinisikan.
 */	
void gotoxy(int x, int y);


void showMenu();

void showHelp();

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi credit yang di ambil dari file
 * IS 			: Tampilan credit belum ditampilkan
 * FS 			: Tampilan credit ditampilkan
 */	

void charToASCII(char c);

#endif
