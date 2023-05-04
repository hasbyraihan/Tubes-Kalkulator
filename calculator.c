#include "calculator.h"


/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan tampilan kalkulator yang ada pada standard calculator
 * IS 			: Tampilan kalkulator BMI yang ada pada BMI calculator belum ditampilkan
 * FS 			: Tampilan kalkulator BMI yang ada pada BMI calculator ditampilkan
 */
void showStdCalc()
{
	system("mode 100, 28");
	system("cls");
	int i;
		FILE*fsc;
		char stdCal[200];
		fsc = fopen("bin/stdCalc.txt","r");
		if(fsc == NULL)
		{
			printf("\nFile tidak ada di bin...");
			getch();
			showMenu();
		}
		while(!feof(fsc))
		{
			fgets(stdCal,sizeof(stdCal),fsc);
			for(i = 0; i < strlen(stdCal) ; i++)
			{
				
				charToASCII(stdCal[i]);
				
			}
			
		}
		
		fclose(fsc);	
		printf("\n");

}


/**
 * Deskripsi 	: Modul ini bertujuan untuk memberi nilai default pada attribut yang ada dalam struct Calculator
 * IS 			: Belum terdapat nilai default
 * FS 			: Attribut yang ada dalam struct Calculator diberi nilai default
 */
void createCalculator(Calculator *calculator) 
{
	// pemberian nilai default
	memset(calculator->expression, '\0', sizeof(calculator->expression));	// untuk melakukan set string expression menjadi Null
	calculator->result = 0;	// untuk set result menjadi 0
	calculator->expressionTree = (address)malloc(sizeof(struct tElmtNode));	// membuat alokasi memori untuk pointer expressionTree
}

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk mengecek apakah terdapat karakter yang bukan operator atau tidak valid pada ekspresi yang diinputkan oleh user.
 *                Fungsi ini akan mengembalikan nilai false apabila terdapat karakter yang bukan operator atau tidak valid 
 */
boolean isValidExpression(char *expression) {
	int i;
	
	// Check apakah pada string terdapat simbol yang bukan operator atau tidak valid
	for(i=strlen(expression)-1 ; i>=0 ; i--)
    {
        if(!isdigit(expression[i]) 	&& expression[i] != '-' && expression[i] != '+'
			        && expression[i] != '/' && expression[i] != '*' && expression[i] != 'p'
			        && expression[i] != '^' && expression[i] != '%' && expression[i] != 'v' 
					&& expression[i] != '.' && expression[i] != '(' && expression[i] != ')' 
					&& expression[i] != 'r' 
            ) 
        {
        	gotoxy(15, 5);
			printf("Inputan Salah!\n");
			return false;				
		}
    
    }
    
    return true;
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk user menginputkan ekspresi matematika di dalam kalkulator
 * IS 			: User belum dapat melakukan input pada kalkulator
 * FS 			: User dapat melakukan input operand dan operator pada kalkulator
 */
void insertExpression(Calculator *calculator) {
	// melakukan proses insertion
	printf("\n\n");
    fflush(stdin);
    gotoxy(15,4);
    scanf("%s", calculator->expression);
    printf("\n\n");
}

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan dari ekspresi matematika yang diinputkan oleh user pada tree. 
 * 				  Fungsi ini akan mengembalikan nilai true jika perhitungan pada tree berhasil dilakukan
 */
 boolean isCalculateSuccess(Calculator *calculator, address root) {
	boolean isSuccess = true;
	
	// hitung hasil dari ekspresi pada tree
	calculator->result = calculate(root, &isSuccess);
	
	// kembalikan status perhitungan
	return isSuccess;
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil ekspresi matematika yang diinputkan oleh user pada kalkulator
 * IS 			: Hasil ekspresi matematika belum ditampilkan pada kalkulator
 * FS 			: Hasil ekspresi matematika ditampilkan pada kalkulator
 */
void printResult(Calculator calculator, boolean isSuccess, address root) {
	
	// print calculator sesuai dengan format
    if(!isSuccess){
    	// jika proses perhitungan dibagi dengan 0
		gotoxy(12,5);
        printf("= %s","Error tidak bisa dibagi dengan 0");
    }
    else if (ceil(calculator.result) > calculator.result){
    	// jika proses perhitungan berhasil dan hasilnya adalah bilangan desimal
		gotoxy(15,5);
        printf("= %.2f",calculator.result);
    }
	else{
		// jika proses perhitungan berhasil dan hasilnya adalah bilangan bulat
		gotoxy(15,5);
        printf("= %d",(int)calculator.result);
    }
    
    gotoxy(64, 8);
    preOrder(root);
    gotoxy(64, 9);
    inOrder(root);
    gotoxy(64, 10);
    postOrder(root);
}

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk menanyakan kepada user apakah akan mencoba kalkulator kembali atau tidak. 
 * 				  Fungsi ini akan mengembalikan nilai true apabila user menginputkan huruf 'y' atau 'Y' 
 * 				  dan akan mengembalikan nilai false apabila user menginputkan huruf 'n' atau 'N'
 */
boolean isContinueCalculator() {
	char choice;
	
	// tentukan apakah user mengulang proses atau tidak
	while(true){
		gotoxy(15,24);
    	printf("Ingin Mencoba Kembali? (y/n) : ");
        fflush(stdin);
        scanf("%c", &choice);
            
        if(choice == 'y' || choice == 'Y'){
            return true;
        }else if(choice == 'n' || choice == 'N') {
        	return false;
		}else {
			gotoxy(15,25);
            printf("Harap menginputkan  y(yes), n(no)\n");
        }
    }
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk mengecek elemen pertama pada ekspresi matematika
 * IS 			: Belum terdidentifikasi apabila elemen pertama pada ekspresi merupakan '-'
 * FS 			: Terdidentifikasi apabila elemen pertama pada ekspresi merupakan '-'
 */
void checkMinAtFirst(char expression[]){
	int i;
	if(expression[0] == '-'){
	        for(i=strlen(expression)-1 ; i>=0 ; i--){
	                expression[i+1] = expression[i];
	        }
	
	        expression[0] = '0';
    	}
}
