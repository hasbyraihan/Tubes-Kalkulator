
#include "UI.h"


int i, j, width, height, x, y;




/**
 * Tanggal		: 23-05-2022
 * Author 		: Cprogramming.com
 * Deskripsi 	: Kursor untuk menunjuk pada titik (x,y) tertentu
 * IS 			: Kursor masih menunjuk titik awal.
 * FS 			: kursor menunjuk titik yang didefinisikan.
 */
void gotoxy(int x, int y)
{
 HANDLE hConsoleOutput;
 COORD dwCursorPosition;
 dwCursorPosition.X = x;
 dwCursorPosition.Y = y;
 hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
 SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}


