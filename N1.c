            
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

	int  *resultat=(int *)malloc(strlen(str_origi)*sizeof(int));
	

	char listnumber[10] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '0' };
	int p = 1;
	int i, j, m;
	for (i = 0; i < 10; i++){

		for (j = 0; j < strlen(str_origi); j++){

			if (str_origi[j] == listnumber[i]){
				
				
				*(resultat + j )= p;
			
				p++;

			}

		}

	}
		for (m=0;m<strlen(str_origi);m++){
			printf("%d",resultat[m]);
		}


	return listnumber;

}






int main(int argc, char** argv) {
	// char* res = encipher('&');
	// printf("%s",res);
	char * text = "ABCDEFGHIJKIOPOUOGDSSgslkdgksjjfS";
	char * num = "30274304287712";
	position_by_order(num);
	//divide(text);
	return (EXIT_SUCCESS);
}


