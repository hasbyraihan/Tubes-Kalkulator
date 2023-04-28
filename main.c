
#include "UI.h"
#include "calculator.h"
#include "bmi.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char input;
	Calculator calculator;
	boolean isSuccess;
	dataBMI data;

	PlaySound(TEXT("bin/IntroKeren.wav"),NULL,SND_SYNC);
	
	splashScreen();
	getch();
	
	menu:
		do{
			system("cls");
			showMenu();
			input = getch();
			if(input == '1'){
				do{	
					system("cls");
					showStdCalc();
					createCalculator(&calculator);	// set nilai default pada attribut yang ada dalam struct Calculator
					insertExpression(&calculator);	// user melakukan input
					// cek validasi ekspresi
					if(!isValidExpression(calculator.expression)){
						getch();
						system("cls");
						goto menu;
					}else{
						checkMinAtFirst(calculator.expression);	// cek elemen pertama pada ekspresi matematika
						calculator.expressionTree = buildTree(calculator.expression, 0, strlen(calculator.expression)-1);	// untuk membuat tree
						boolean isSuccess = isCalculateSuccess(&calculator, calculator.expressionTree);	// melakukan perhitungan dari ekspresi matematika yang diinputkan oleh user pada tree
						printResult(calculator, isSuccess, calculator.expressionTree);	// menampilkan hasil perhitungan
						deleteTree(calculator.expressionTree);
						// menanyakan kepada user apakah akan mencoba kalkulator kembali atau tidak
						if(!isContinueCalculator()){
							break;
						}
						gotoxy(70,0);
					}

				}while(true);
			}else if(input == '2'){
				// kalkulator BMI
				do{
					showBMICalc();
					printCategories();
					inputBMI(data);	// user melakukan input pada kalkulator BMI
					gotoxy(3,17);
					if(!isContinueCalculator()){
						break;
					}
				}while(true);
				goto menu;
			}else if(input == '0'){
				exit(1);
			}
		}while(input != '0');
	
	return 0;
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
  
   for (int i = 0;i < strlen(loading);i++){
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
	if(fm == NULL)
		{
			printf("\nFile not found...");
			getch();
			showMenu();
		}
	while(!feof(fm))
	{
		fgets(menu,sizeof(menu),fm);
			for(int i = 0; i < strlen(menu); i++)
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


