
#include "tree.h"
#include "calculator.h"

/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Deskripsi	: Modul ini bertujuan untuk menentukan operand yang akan menjadi root dan melakukan perhitungan di dalam tree.
 * 			   	  Modul ini mengembalikan nilai perhitungan ke root dan mengembalikan nilai angka jika tidak terdapat operator 
 * 			   	  dengan tipe data double
 */
double calculate(address root, boolean *isSuccess)
{
	// root adalah operator
    if(root->isOperator){
    	// Melakukan perhitungan
        switch(root->opr){
            case '+':{
                return calculate(root->leftChild,isSuccess) + calculate(root->rightChild,isSuccess);
                break;
            }
            case '-':{
                return calculate(root->leftChild,isSuccess) - calculate(root->rightChild,isSuccess);
                break;
            }
            case '*':{
                return calculate(root->leftChild,isSuccess) * calculate(root->rightChild,isSuccess);
                break;
            }
            case '/':{
                if(calculate(root->rightChild,isSuccess) == 0) {
                    (*isSuccess) = false;
				}
                else
                    return calculate(root->leftChild,isSuccess) / calculate(root->rightChild,isSuccess);
                break;
            }
            case '^':{
                return pow(calculate(root->leftChild,isSuccess), calculate(root->rightChild,isSuccess));
                break;
            }
            case '%':{
                return (calculate(root->leftChild,isSuccess))/100;
                break;
            }
            case 'p':{
                return (calculate(root->leftChild,isSuccess))*PI;
                break;
            }
            case 'v':{
                return sqrt(calculate(root->rightChild,isSuccess));
                break;
            }
            case 'r':{
            	return log10(calculate(root->rightChild,isSuccess));
				break;
			}
			case 's':{
				return sin(calculate(root->rightChild,isSuccess));
				break;
			}
        }
    }
    
    return root->digit;
}

 /**
 * Deskripsi 	: Fungsi ini bertujuan untuk melakukan cek karakter pertama yang ada pada expression dan mengembalikan nilai kode ASCII operand yang paling awal
 */
double checkExpression(char str[],int start,int end){
    int i;	// iterator
    int flag = 1;	// sebagai penanda untuk elemen pertama
    int secondFlag = 0;	// sebagai penanda jika terdapat bilangan desimal
    double sum = 0;	// hasil konversi karakter menjadi integer
    double divFactor = 10.0;	// bertambah 10x lipat semakin ke posisi kanan dari simbol desimal
    
    // jika elemen pertama merupakan minus
    if(str[start] == '-'){
        flag = -1;
        start++;
    }
    for(i = start; i <= end; i++){
    	// jika elemen ke i bukan merupakan operand dan desimal
        if(!isdigit(str[i]) && str[i] != '.') 
			return MAX;
		
		// jika elemen ke i merupakan '.'
        if(str[i] == '.'){
        	secondFlag++;
        	i++;
		}
		
		if(!secondFlag){	// jika tidak terdapat bilangan desimal
        	sum = sum * 10 + str[i] - '0';
		}else{	// jika terdapat bilangan desimal
			sum = sum + (str[i] - '0') / divFactor;
			divFactor *= 10;
		}
    }
    return sum * flag;
}

/**
 * Modified from https://www.programmersought.com/article/95294413292/
 * Deskripsi 	: Modul ini bertujuan untuk menemukan operator berdasarkan prioritasnya
 *				  Mengembalikan nilai posisi operator
 */
int searchOperator(char str[], int start, int end)
{
	int posPlusOrSub = 0;	// untuk menentukan posisi dari operator tambah atau kurang
    int numPlusOrSub = 0;	// untuk mengetahui jumlah terdapat operator tambah atau kurang
    int posDivOrMul = 0;	// untuk menentukan posisi dari operator kali, bagi, persen, atau pi
    int numDivOrMul = 0;	// untuk mengetahui jumlah terdapat operator kali, bagi, persen, atau pi
    int posPowOrRoot = 0; 	// untuk menentukan posisi dari operator pangkat atau akar
    int numPowOrRoot = 0; 	// untuk mengetahui jumlah terdapat operator pangkat atau akar
 
    int in_brackets = 0; //Identifiers not in parentheses 
    int i;
    for(i = start; i <= end; i++)
    {
    	if(str[i] == '(')
    		in_brackets++;
    	else if(str[i] == ')')
    		in_brackets--;
    	
    	if(!in_brackets)
    	{
    		if(str[i] == '+' || str[i] == '-')
    		{
    			if(i != start && isdigit(str[i-1])){
	    			posPlusOrSub = i;
	    			numPlusOrSub++;
				}else if(str[i-1] == '(' || str[i-1] == ')'){
	    			posPlusOrSub = i;
	    			numPlusOrSub++;
				}
			}
			else if(str[i] == '*' || str[i] == '/' || str[i] == '%' || str[i] == 'p')
			{
				posDivOrMul = i;
				numDivOrMul++;
			}else if(str[i] == '^' || str[i] == 'v' || str[i] == 'r' || str[i] == 's')
			{
				posPowOrRoot = i;
				numPowOrRoot++;
			}
		}
	}
	
	int posOprPrior = -1;	// untuk menentukan prioritas posisi operator
	
	if(numPlusOrSub)
		posOprPrior = posPlusOrSub;
	else if(numDivOrMul)
		posOprPrior = posDivOrMul;
	else if(numPowOrRoot)
		posOprPrior = posPowOrRoot;
	
	return posOprPrior;
}

/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Deskripsi	: Modul ini bertujuan untuk membuat tree
 */
address buildTree(char str[], int start, int end)
{
	address root = (address)malloc(sizeof(ElmtNode));
	
	if(start > end)
		return NULL;
	
	double digit = checkExpression(str, start, end);
	
	// jika elemen pertama merupakan operand
	if(digit != MAX)
	{
		root->isOperator = false;
		root->digit = digit;
		root->leftChild = NULL;
		root->rightChild = NULL;
		return root;
	}
	
	// menentukan posisi parent/root
	int posRoot = searchOperator(str, start, end);
	
	// jika tidak terdapat operator
	if(posRoot == -1)
		return buildTree(str, start + 1, end - 1);
	
	root->isOperator = true;	// operator pada parent/root
	root->opr = str[posRoot];	// value untuk parent/root diisi oleh string pada elemen ke-posRoot
	root->leftChild = buildTree(str, start, posRoot-1);
	root->rightChild = buildTree(str, posRoot + 1, end);
	
	return root;
}

/**
 * Modified From https://www.programmersought.com/article/95294413292/
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara postfix
 * IS 			: Ekspresi matematika belum ditampilkan secara postfix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal post-order
 */
void postOrder(address root)
{
	if(root != Nil)
	{
		postOrder(root->leftChild);
		postOrder(root->rightChild);
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", root->opr);
		}
	}
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara prefix
 * IS 			: Ekspresi matematika belum ditampilkan secara prefix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal pre-order
 */
void preOrder(address root)
{
	if(root != Nil)
	{
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", root->opr);
		}
		preOrder(root->leftChild);
		preOrder(root->rightChild);
	}
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menampilkan ekspresi matematika secara infix
 * IS 			: Ekspresi matematika belum ditampilkan secara infix
 * FS 			: Ekspresi matematika ditampilkan dengan menggunakan transversal in-order
 */
void inOrder(address root)
{
	if(root != Nil)
	{
		inOrder(root->leftChild);
		if(root->isOperator == false)
		{
			printf("%d ", (int)root->digit);
		}
		else
		{
			printf("%c ", (root->opr));
		}
		inOrder(root->rightChild);
	}
	
}

/**
 * Deskripsi 	: Modul ini bertujuan untuk menghapus tree
 * IS 			: Tree belum dihapus
 * FS 			: Tree sudah dihapus
 */
void deleteTree(address root)
{
	if(root == NULL)
		return;
	
	deleteTree(root->leftChild);
	deleteTree(root->rightChild);
	
	free(root);
}
