
#include "bmi.h"

void showBMICalc()
{
	system("mode 92, 20");
	system("cls");
	char title[] = 
		"\t\t\t    {=================================}\n\
		  \t    /          BMI Calculator         |\n\
	 	    \t    @=================================~\n\
		";
		
	char outputBMI[] = 
		"\t\t\t\t\t\t{========================================}\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t<========================================>\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t/                                        |\n\
\t\t\t\t\t\t@========================================~\n\
		";
		
	char inputBMI[] = 
		"  {=======================================}\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  @=======================================~\n\
		";
	
	for(int i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");

	for(int i = 0; i < strlen(outputBMI); i++)
	{
		charToASCII(outputBMI[i]);
	}
	printf("\n");
	
	gotoxy(0,5);
	for(int i = 0; i < strlen(inputBMI); i++)
	{
		charToASCII(inputBMI[i]);
	}
}



/**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan perhitungan BMI. Fungsi ini akan mengembalikan nilai hasil perhitungan tersebut
 */
float calculateBMI(dataBMI data) {
	data.height = convertHeight(data);	// mengkonversi tinggi dari cm ke m
   	data.bmi = data.weight / (data.height * data.height);	// rumus BMI
   
   	return data.bmi;
}

/**
 * Deskripsi 	: Fungsi ini bertujuan untuk mengkonversi tinggi dari cm ke m
 */
float convertHeight(dataBMI data){
	return data.height/100;
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan hasil BMI
 * IS			: Hasil result BMI belum ditampilkan
 * FS			: Hasil result BMI ditampilkan
 */
void resultBMI(dataBMI data){
	gotoxy(6,10);
	printf("BMI Anda\t\t:  %.2f\n", data.bmi); 
	gotoxy(6,12);
	 if(data.bmi <= 18.5)  
    {  
        printf("BMI anda terdeteksi Kurus\n");  
    }  
    else if(data.bmi > 18.5 && data.bmi <= 24.9)  
    {  
        printf("BMI anda terdeteksi Ideal\n");  
    }  
    else if(data.bmi > 24.9 && data.bmi <= 29.9)  
    {  
        printf("BMI anda terdeteksi Gemuk\n");  
    }  
     
    else if(data.bmi > 29.9)  
    {  
        printf("BMI anda terdeteksi Obesitas!! \n");  
    }  
    else  
    {  
        printf("Ada Kesalahan!\n");  
    }  
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk user melakukan input pada kalkulator BMI
 * IS			: User belum dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 * FS			: User dapat menginputkan tinggi dan berat badan dalam kalkulator BMI
 */
void inputBMI(dataBMI data){	
	gotoxy(6,6);
	printf ("Berat Badan \t: ");
	gotoxy(31,6);
	printf("kg");
	gotoxy(27,6);
	scanf("%f",&data.weight);
	
	gotoxy(6,8);
	printf("Tinggi Badan \t: ");
	gotoxy(31,8);
	printf("cm");
	gotoxy(27,8);
	scanf("%f",&data.height);
	data.bmi = calculateBMI(data);
	if(data.height > 0 && data.weight > 0){	
		resultBMI(data);
	}else{
		gotoxy(6,12);
		printf("Inputan Salah !!!\n");
	}
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan keterangan kateogori BMI
 * IS			: Keterangan kategori BMI belum ditampilkan
 * FS			: Keterangan kategori BMI ditampilkan
 */
void printCategories(){
	gotoxy(63,6);
	printf("Kategori BMI\n");
	gotoxy(50,8);
	printf("Kurus : Kurang dari 18.5\n");
	gotoxy(50,10);
	printf("Ideal : 18.5 Sampai 24.9\n");
	gotoxy(50,12);
	printf("Gemuk : 25 Sampai 29.9\n");
	gotoxy(50,14);
	printf("Obesitas : Lebih dari 30 \n");
}