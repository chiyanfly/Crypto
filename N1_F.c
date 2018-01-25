            
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>

/*
*
*/



char checkerboard[5][11] = { { '\0', '5', '0', '7', '3', '8', '9', '4', '6', '1', '2' },
			     { '\0', 'C', 'E', 'L', 'O', 'S', 'I', 'A', '\0', '\0', '\0' },
			     { '6', 'B', 'G', '.', 'K', '&', 'P', 'T', 'W', 'Z', '@' },
			     { '1', 'D', 'H', ',', 'M', '*', 'Q', 'U', 'X', '!', ':' },
			     { '2', 'F', 'J', ';', 'N', '#', 'R', 'V', 'Y', '?', '\'' } };

char * encipher_char(char character){
	int i = 1;
	while (i < 5){
		int j = 1;
		while (j < 11){
			if ((int)character >= (int)'0' && (int)character <= (int)'9'){
				char* result = (char*)malloc(7 * sizeof(char)+1);
				result[0] = '1';
				result[1] = '8';
				result[2] = character;
				result[3] = character;
				result[4] = character;
				result[5] = '1';
				result[6] = '8';
				result[7] = '\0';
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
	return result;
}

char * encipher_text(char * plaintext){
  int L = strlen(plaintext);
  char * result = malloc(1000);
  char * crypto_char = malloc(100);
  crypto_char = encipher_char(plaintext[0]);
  strncpy(result, encipher_char('#'), 2*sizeof(char));
  for(int i = 0; i < strlen(plaintext); i++){
    crypto_char = encipher_char(plaintext[i]);
    strncat(result, crypto_char, strlen(crypto_char) + 1);
  }
  return result;
}

char ** allocate_board(int rows, int cols)
{    
    char **board = (char **)malloc(rows * sizeof(char *)); 
    int row;

    for (int r = 0; r < rows; r++) {
        board[r] = (char *)malloc(cols * sizeof(char));
    }
    return board;
}


char ** transform1(char * cypher, int keyword_length){
  int l = strlen(cypher);
  int cols = keyword_length;
  int rows = (int)(((float)l/(float)cols) + 0.5);
  char ** cypher_tr = allocate_board(rows, cols);
  int i = 0;
  for(int r = 0; r<rows; r++){
    for(int c = 0; c<cols; c++){
      cypher_tr[r][c] = cypher[i];
      //printf("%d = %d\n", l,i);
      if (i < strlen(cypher)-1){
	i++;
      }
      else
	return cypher_tr;
    }
  }
}

void display_double_array(char ** arr, int rows, int cols){
  for(int r = 0; r<rows; r++){
    for(int c = 0; c<cols; c++){
      printf("%c", arr[r][c]);
    }
    printf("\n");
  }
}


/** B-C plus
D is writen
E id l'ordre de alph
F  ????C ??? ?????????10??
G  E+F  ?10??
H
*/
/*char *  position_by_order(char * str_origi){

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

	}*/






int main(int argc, char** argv) {

	char * text = "ABCDEFGHIJKIOPOUOGDSSGSOPIZR1EPOIRZ.";
	char * num = "30274304287712";
	//position_by_order(num);
	char * text2 = divide(text);
	printf("%s\n",text2);
       	printf("%s\n",encipher_text(text2));
	char ** cyph = transform1(encipher_text(text2),5);
	display_double_array(cyph, strlen(encipher_text(text2)), 5 );
	


	return (EXIT_SUCCESS);
}


