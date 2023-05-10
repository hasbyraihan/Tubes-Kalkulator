#include "UI.h"
#include "calculator.h"
#include "bmi.h"
#include "history.h"
#include "konvPanjang.h"
#include "ConvertSuhu.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	char input;
	Calculator calculator;
	boolean isSuccess;
	dataBMI data;
	int ConS;
//	PlaySound(TEXT("bin/IntroKeren.wav"),NULL,SND_SYNC);
	
//	splashScreen();
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
						if(isSuccess){
						// save history pada file
							saveStdHistory(calculator.expression, calculator.result);
						}
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
			}else if(input == '3'){
				// 
				do{
					showkonv();
					gotoxy(3, 7);
   					printf("Pilih apa yang akan anda Convert : ");
   					gotoxy(49,8);
    				printf("1. Convert Suhu Celcius");
					gotoxy(49,10);
    				printf("2. Convert Suhu Reamur");
					gotoxy(49,12);
    				printf("3. Convert Suhu Kelvin");
					gotoxy(49,14);
    				printf("4. Convert Suhu Fahrenheit");
    				gotoxy(39, 7);
    				scanf("%d", &ConS);
    				
    				switch(ConS){
    					case 1:
    						ConCel();
    						break;
    					case 2:
    						ConReam();
    						break;
    					case 3:
    						ConKelv();
    						break;
    					case 4:
    						ConFahr();
    						break;
					}
   				
					if(!isContinueCalculator()){
						break;
					}
				}while(true);
				goto menu;
			}else if(input == '4'){
				// 
				do{
					showkonvP();
					konvP();
					if(!isContinueCalculator()){
						break;
					}
				}while(true);
				goto menu;
			}else if(input == '5'){
				
				system("mode 94, 30");
				system("cls");
				showStdHistory();
				showBmiHistory();
				goto menu;
			}else if(input == '6'){
				// Help
				showHelp();
				goto menu;

			}else if(input == '0'){
			
				exit(1);
			}
	}while(input != '0');
			
	return 0;
}



