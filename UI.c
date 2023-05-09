#include "UI.h"


int i, j, width, height, x, y;
/**
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

void splashScreen(){


	char loading[] = 
"\t\t\t\t=    =  ====  =    =\n\
\t\t\t\t\t\t=    =     =  =    =\n\
\t\t\t\t\t\t=    =     =  ==   =\n\
\t\t\t\t\t\t======     =  = =  =\n\
\t\t\t\t\t\t=    =     =  =  = =\n\
\t\t\t\t\t\t=    =  =  =  =   ==\n\
\t\t\t\t\t\t=    =  ====  =    =\n\
";



	char author[] =
 "\t              Created By :\n\
  \t\t\t\t\t\t     Hasby Raihan\n\
  \t\t\t\t\t     Jonanda Pantas Agitha Brahmana\n\
  \t\t\t\t\t       Muhammad Naufal Fadil Aziz\n\
 ";
 int i;
 gotoxy(17,8);
  
   for (i = 0;i < strlen(loading);i++){
   		Sleep(2);
 		charToASCII(loading[i]);
 	}
  
   gotoxy(39,18);
     for (i = 0; author[i]!=0 ; i++) {
    Sleep(10);
    printf("%c", author[i]);
  }
  
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan isi tampilan menu
 * IS 			: Tampilan menu belum ditampilkan
 * FS 			: Tampilan menu ditampilkan
 */
void showMenu(){
	system("mode 58, 10"); system("cls");
	
	FILE *fm;
	char menu[200];
	fm = fopen("bin/menu.txt", "r");
	int i;
	if(fm == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
	while(!feof(fm))
	{
		fgets(menu,sizeof(menu),fm);
			for(i = 0; i < strlen(menu); i++)
			{
				charToASCII(menu[i]);
				
			}
	}
	fclose(fm);	
	printf("\n Choose menu : ");
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk mengubah karakter tertentu menjadi ASCII.
 * IS 			: Karakter belum diubah menjadi ASCII.
 * FS 			: Karakter telah diubah menjadi ASCII.
 */
void charToASCII(char c) 
{
	/* Modul yang mengkonversi char ke char tertentu berdasarkan ASCII */
	switch(c)
	{
		case '=' :
			printf ("%c", 254);
			break;
		case '|' :
			printf ("%c", 222);
			break;
		case '#' :
			printf ("%c", 206);
			break;
		case '/' :
			printf ("%c", 221);
			break;
		case '&' :
			printf ("%c", 203);
			break;
		case '<' :
			printf ("%c", 204);
			break;
		case '>' :
			printf ("%c", 185);
			break;
		case 'Z' :
			printf ("%c", 075);
			break;
		case 'Q' :
			printf ("%c", 057);
			break;
		case '{' :
			printf ("%c", 201);
			break;
		case '}' :
			printf ("%c", 187);
			break;
		case '@' :
			printf ("%c", 200);
			break;
		case '~' :
			printf ("%c", 188);
			break;
		case 'X' :
			printf ("%c", 174);
			break;
		case '$' :
			printf("%c", 47);
			break;
		default :
			printf ("%c", c);		
	}
}

