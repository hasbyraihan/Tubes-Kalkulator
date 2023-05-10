#include "ConvertSuhu.h"

void showkonv()
{
	system("mode 92, 20");
	system("cls");
	char title[] = 
		"\t\t\t    {=================================}\n\
		  \t    /          Konvert Suhu	      |\n\
	 	    \t    @=================================~\n\
		";
		
	char outputkonv[] = 
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
		
	char inputkonv[] = 
		"  {=======================================}\n\
  /                                       |\n\
  /                                       |\n\
  /                                       |\n\
  @=======================================~\n\
		";
	int i;
	for( i = 0; i < strlen(title); i++)
	{
		charToASCII(title[i]);
	}
	printf("\n\n");

	for(i = 0; i < strlen(outputkonv); i++)
	{
		charToASCII(outputkonv[i]);
	}
	printf("\n");
	
	gotoxy(0,5);
	for( i = 0; i < strlen(inputkonv); i++)
	{
		charToASCII(inputkonv[i]);
	}
}

double ConCel()
{
	system("cls");
	showkonv();
    double Celc,Ream,Kelv,Fahr;
	gotoxy(3, 7);
    printf("Masukkan Suhu Celcius: ");
    scanf("%lf", &Celc);

    Ream = ConCelReam (Celc);
    Kelv = ConCelKelv (Celc);
	Fahr = ConCelFahr (Celc);
	
	gotoxy(63,6);
	printf("Hasil Konvert\n");
	gotoxy(49,8);
    printf("%g Celius dalam Reamur : %g \n",Celc ,Ream);
	gotoxy(49,10);
    printf("%g Celius dalam Kelvin : %g \n",Celc ,Kelv);
	gotoxy(49,12);
    printf("%g Celius dalam Fahrenheit : %g \n",Celc ,Fahr);

    return 0;
}

double ConReam()
{
	system("cls");
    showkonv();
	double Celc,Ream,Kelv,Fahr;
	gotoxy(3, 7);
    printf("Masukkan Suhu Celcius: ");
    scanf("%lf", &Ream);

    Celc = ConCelReam (Ream);
    Kelv = ConReamKelv (Ream);
	Fahr = ConReamFahr (Ream);
	
	gotoxy(63,6);
	printf("Hasil Konvert\n");
	gotoxy(49,8);
    printf("%g Reamur dalam Celcius : %g \n",Ream ,Celc);
	gotoxy(49,10);
    printf("%g Reamur dalam Kelvin : %g \n",Ream ,Kelv);
	gotoxy(49,12);
    printf("%g Reamur dalam Fahrenheit : %g \n",Ream ,Fahr);

    return 0;
}

double ConKelv()
{
	system("cls");
    showkonv();
	double Celc,Ream,Kelv,Fahr;
	gotoxy(3, 7);
    printf("Masukkan Suhu Kelv: ");
    scanf("%lf", &Kelv);

    Ream = ConKelvReam (Kelv);
    Celc = ConKelvCel (Kelv);
	Fahr = ConKelvFahr (Kelv);
	
	gotoxy(63,6);
	printf("Hasil Konvert\n");
	gotoxy(49,8);
    printf("%g Kelvin dalam Reamur : %g \n",Kelv ,Ream);
	gotoxy(49,10);
    printf("%g Kelvin dalam Celcius : %g \n",Kelv ,Celc);
	gotoxy(49,12);
    printf("%g Kelvin dalam Fahrenheit : %g \n",Kelv ,Fahr);

    return 0;
}

double ConFahr()
{
	system("cls");
	showkonv();
    double Celc,Ream,Kelv,Fahr;
	gotoxy(3, 7);
    printf("Masukkan Suhu Fahrenheit: ");
    scanf("%lf", &Fahr);

    Ream = ConFahrReam (Fahr);
    Kelv = ConFahrKelv (Fahr);
	Celc = ConFahrCel (Fahr);
	
	gotoxy(63,6);
	printf("Hasil Konvert\n");
	gotoxy(49,8);
    printf("%g Fahrenheit dalam Reamur : %g \n",Fahr ,Ream);
	gotoxy(49,10);
    printf("%g Fahrenheit dalam Kelvin : %g \n",Fahr ,Kelv);
	gotoxy(49,12);
    printf("%g Fahrenheit dalam Celcius : %g \n",Fahr ,Celc);

    return 0;
}
double ConCelFahr(double celc){
	double fahr; 
	fahr = (9.0/5.0 * celc) + 32;
	return fahr;
}
 
 double ConCelKelv(double celc){
	double kelv;
	 
	kelv = celc + 273.15;
	return kelv;
}

double ConCelReam(double celc){
	double ream;
	 
	ream = celc * (4.0/5.0) ;
	return ream;
}

double ConFahrCel(double fahr){
	double celc; 
	celc = (5.0/9.0) * (fahr - 32);
	return celc;
}
 
double ConFahrKelv(double fahr){
	double kelv;
	kelv = (fahr - 32)* 5/9 + 273,15;
	return kelv;
}

double ConFahrReam(double fahr){
	double ream;
	ream = (fahr - 32)* 4/9 ;
	return ream;
}

double ConKelvCel(double kelv){
	double celc; 
	 celc = kelv - 273,15;
	return celc;
}
 
double ConKelvFahr(double kelv){
	double fahr;
	fahr = kelv * 9/5 - 459,67;
	return fahr;
}

double ConKelvReam(double kelv){
	double ream;
	ream = (kelv - 273) * 4/5;
	return ream;
}

double ConReamCel(double ream){
	double celc; 
	celc = (5.0/4.0) * ream;
	return celc;
}
 
double ConReamFahr(double ream){
	double fahr;
	fahr = ream * (9.0/4.0) + 32;
	return fahr;
}

double ConReamKelv(double ream){
	double kelv;
	kelv = 273.15 + (5.0/4.0) * ream;
	return kelv;
}