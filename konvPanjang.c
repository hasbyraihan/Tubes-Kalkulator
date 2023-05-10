#include "konvPanjang.h"

void showkonvP()
{
	system("mode 92, 20");
	system("cls");
	char title[] = 
		"\t\t\t    {=================================}\n\
		  \t    /          Konvert Panjang	      |\n\
	 	    \t    @=================================~\n\
		";
		
	char outputkonvP[] = 
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
		
	char inputkonvP[] = 
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

	for(i = 0; i < strlen(outputkonvP); i++)
	{
		charToASCII(outputkonvP[i]);
	}
	printf("\n");
	
	gotoxy(0,5);
	for( i = 0; i < strlen(inputkonvP); i++)
	{
		charToASCII(inputkonvP[i]);
	}
}

double konvP()
{
//	system("cls");
    double pjgm, pjgmm, pjgcm, pjgkm, pjginc;
	gotoxy(3, 7);
    printf("Masukkan panjang dalam meter: ");
    scanf("%g", &pjgcm);

    pjgm = ConCMkeM (pjgcm);
    pjgmm = ConCMkeMM (pjgcm);
	pjgkm = ConCMkeKM (pjgcm);
	pjginc = ConCMkeINC (pjgcm);
	
	gotoxy(63,6);
	printf("Hasil Konvert\n");
	gotoxy(49,8);
    printf("Panjang dalam meter: %g cm\n", pjgm);
	gotoxy(49,10);
	printf("Panjang dalam milimeter: %g cm\n", pjgmm);
	gotoxy(49,12);
	printf("Panjang dalam kilometer: %g km\n", pjgkm);
	gotoxy(49,14);
	printf("Panjang dalam inch: %g inch\n", pjginc);

    return 0;
}

double ConCMkeM (double cm){
	double met;
	met = cm / 100;
	return met;
}
double ConCMkeMM (double cm){
	double mm;
	mm = cm * 10;
	return mm;
}
double ConCMkeKM (double cm){
	double km;
	km = cm / 100000;
	return km;
}
double ConCMkeINC (double cm){
	double inc;
	inc = cm / 2.54;
	return inc;
}