#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/*
*
*/



char checkerboard[5][11] = { { '\0', '5', '0', '7', '3', '8', '9', '4', '6', '1', '2' },
{ '\0', 'C', 'E', 'L', 'O', 'S', 'I', 'A', '\0', '\0', '\0' },
{ '6', 'B', 'G', '.', 'K', '&', 'P', 'T', 'W', 'Z', '@' },
{ '1', 'D', 'H', ',', 'M', '*', 'Q', 'U', 'X', '!', ':' },
{ '2', 'F', 'J', ';', 'N', '#', 'R', 'V', 'Y', '?', '~' } };

char * encipher(char character){
	int i = 1;
	while (i < 5){
		int j = 1;
		while (j < 11){
			if ((int)character >= (int)'0' && (int)character <= (int)'9'){
				char* result = (char*)malloc(3 * sizeof(char)+1);
				result[0] = character;
				result[1] = character;
				result[2] = character;
				result[3] = '\0';
				return result;
			}
			else{
				if (character != checkerboard[i][j]){
					j++;
				}
				else {
					if (i == 1){
						char* result = (char*)malloc(sizeof(char)+1);
						result[0] = checkerboard[0][j];
						result[1] = '\0';
						return result;
					}
					else{
						char* result = (char*)malloc(2 * sizeof(char)+1);
						result[0] = checkerboard[i][0];
						result[1] = checkerboard[0][j];
						result[2] = '\0';
						return result;
					}
				}

			}

		}
		i++;
	}
}

char * divide(char * plaintext){

	int divide_position = rand() % strlen(plaintext);
	// printf("%d\n",divise_position);
	char * str_first = (char*)malloc(strlen(plaintext) - divide_position + 1);
	// printf("%d\n",strlen(plaintext));
	char * str_second = (char*)malloc(divide_position + 1);
	int i = 0;
	for (; i<strlen(plaintext); i++){
		if (i >= divide_position)
			str_first[i - divide_position] = plaintext[i];
		else
			str_second[i] = plaintext[i];

	}
	char * result = (char*)malloc(strlen(str_first) + strlen(str_second) + 1);
	// printf("%s\n",str_second);
	// printf("%s\n",str_first);
	 strncpy(result, str_first, strlen(str_first));
	 strncat(result, str_second, strlen(str_second)+1);
	printf("%s\n", result);
	return result;
}
/** B-C plus
D is writen
E id l'ordre de alph
F  ????C ??? ?????????10??
G  E+F  ?10??
H
*/
char *  position_by_order(char * str_origi){

	char  *resultat=(char *)malloc(strlen(str_origi)*sizeof(char));
	

	char listnumber[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	int p = 1;
	int i, j, m;
	for (i = 0; i < 10; i++){

		for (j = 0; j < strlen(str_origi); j++){

			if (str_origi[j] == listnumber[i]){
				
				
				*(resultat + j )= p%10+'0';
			
				p++;

			}

		}

	}
		

	return resultat;

}



char * LineF(char * F_orig){

  char * result= (char *)malloc(20*sizeof(char));
  strncpy(result,F_orig, strlen(F_orig));
		
	for(int i = 5;i<10;i++){
		result[i]= ( (result[i-5]-'0') +  (result[i-4] -'0')  )%10 +'0';
	}
	for(int j= 10;j<20;j++){
	     result[j]=(j+1)%10+'0';
	}

	return result;


}



char * LineG(char *LineE,char *LineF){

	char * result = (char *)malloc(strlen(LineE)/2*sizeof(char));
	for(int i =0;i<strlen(LineE)/2;i++){

			result[i]= ((LineE[i]-'0')+(LineF[i]-'0'))%10+'0'; 
		}
	return result;
}

char * LineH(char *LineE,char *LineF,char *LineG){
		

	char * result = (char *)malloc(strlen(LineG)*sizeof(char));
	for(int i =0;i<strlen(LineG);i++){
		
		for(int j =10;j<20;j++){
				if(LineG[i]==LineF[j]){
					result[i]=LineE[j];								
				}

			}
		}

		return result;
}



//Line  k L M N P
char * add_two_voisins(char *source){


	char * result = (char *)malloc(strlen(source)*sizeof(char));

		for (int i=0;i<strlen(source)-1;i++){
			result[i]=((source[i]-'0')+(source[i+1]-'0'))%10 +'0';
		}
		result[strlen(source)-1]=((source[strlen(source)-1]-'0')+(result[0]-'0'))%10+'0';

		return result;
}


char * LineQR(char *J, char*K,char*L,char *M,char*N,char *P){
char *result= 	(char *)malloc(31*sizeof(char));	
		char listnumber[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
		int p = 0;
		for(int i =0;i<10;i++){
				for(int j =0;j<strlen(J);j++){
		             if(J[j]==listnumber[i]){
					if(p<31)			
					result[p++]=K[j];
					if(p<31)
					result[p++]=L[j];
					if(p<31)
					result[p++]=M[j];
					if(p<31)
					result[p++]=N[j];
					if(p<31)
					result[p++]=P[j];
					}


				}

		}
return result;

}

char * LineQ(char* QR,int n){

char * result = (char *)malloc(n*sizeof(char));	
 strncpy(result, QR, n);
return result;

}

char * LineR(char* QR,int n){

char * result = (char *)malloc(n*sizeof(char));	
for(int i =0;i<n;i++)
{
result[i]=QR[n+i];
}
return result;

}



char ** addetoile(int line,int column,char ** array){

for(int i =0;i<a;i++	){
for(int j=0;j<b;j++){





}

}




}


//cle second line
char transition(int rows,int columns,char *cle){



int lignbegin=0;

for(int num=1;num<=columns;num++){

for(int position_of_cle=0;position_of_cle<strlen(cle);position_of_cle++){

if((cle[position_of_cle]-'0')==num)
{

addetoile(lignebegin,position_of_cle);
lignebegin= lignebegin+(strlen(cle)-position_of_cle )+1;

}




}




}


}




int main(int argc, char** argv) {
	// char* res = encipher('&');
	// printf("%s",res);
	char * text = "ABCDEFGHIJKIOPOUOGDSSgslkdgksjjfS";
	char * num = "30274304287712";

	char  * test_f = "91724";

	char * E="74201563986871954032";
	char * F=LineF(test_f);
	char * G=LineG(E,F);
	char * H=LineH(E,F,G);
	char * J= position_by_order(H);
	char * K=add_two_voisins(H);
	char * L=add_two_voisins(K);
	char * M=add_two_voisins(L);
	char * N=add_two_voisins(M);
	char * P=add_two_voisins(N);

	char  * S = position_by_order(P);
	char* QR= LineQR(J,K,L,M,N,P);
	char * Q = LineQ(QR,17);
	char * R=LineR(QR,17);
 	printf("%s\n%s\n",Q,R);


	//position_by_order(H);
	//position_by_order(num);
	//divide(text);
	return (EXIT_SUCCESS);
}

