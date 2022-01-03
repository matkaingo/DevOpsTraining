
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *ip;
char word1[100];
char word2[100];
int op = 1;
int ip_len;
int try_again = 0;
int p;

int ip_validation(char *ip);
int ConvertAscii(int number);
int randomize();
char *concat(char word1[100], char word2[100]);




int main(void) {
	while (op != 0) {
        if(try_again == 1){
            op = p;
        }else{
            system("clear");
            puts("\nMENU LAB 1");
            puts("--------------");
            puts("1: Confirmar si una IP es valida");
            puts("2: Convertir numero en ASCII");
            puts("3: Generar un numero aleatorio entre 1 y 6");
            puts("4: Concatenar (juntar) dos palabras ingresadas por consola");
            puts("0: Salir");
            scanf("%d", &op);
        }

		
		
		
		
		if (op == 1) {
            system("clear");
            ip = malloc(256);
            puts("Confirmar si una IP es valida");
            puts("-----------------------------");
			puts("Escribe una IP");
			scanf("%s", ip);
            printf("\n");

            if((ip_validation(ip))==1){
                puts("IP valida");
            }
            else{
                puts("IP invalida");
            }
            free(ip);
            puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
			scanf("%d", &try_again);
            p=1;
		}
		else if (op == 2) {
            system("clear");
            int number;
            puts("Convertir numero en ASCII");
            puts("-------------------------");
			puts("Escribe el numero Ascii a convertir");
			scanf("%d", &number);
            printf("\n Ascii => %c",ConvertAscii(number));

            puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
			scanf("%d", &try_again);
            p=2;
			
		}
		
		else if (op == 3) {
            system("clear");
            puts("Generar un numero aleatorio entre 1 y 6");
            puts("---------------------------------------");
			puts("El numero random generado es:");
			printf("El numero random generado es => %d", randomize());


            puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
			scanf("%d", &try_again);
            p=3;
		}
		
		else if (op == 4) {
            system("clear");
            puts("Concatenar (juntar) dos palabras ingresadas por consola");
            puts("-------------------------------------------------------");
			puts("Escribe Primera palabra");
            scanf("%s", word1);
            strcat(word1, " ");			
			puts("Escribe Segunda palabra");
            scanf("%s", word2);
            printf("Las palabras quedarian asi => %s", concat(word1,word2));
			



            puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
			scanf("%d", &try_again);
            p=4;
		}
		
		else if (op == 0) {
			printf("Apagando...\n");
		}
		
		else {
			printf("Opcion no valida\n");
		}
	}
}

//Retorna 1 si es valido y 0 si no lo es
int ip_validation(char *ip){
    char *ip_split;
    int bool =1;
    int count = 0;
    ip_split = strtok(ip, ".");
    while (ip_split != NULL && bool ==1)
    {
        if((strtol(ip_split,NULL,10))<0||(strtol(ip_split,NULL,10))>255){
            bool = 0;
        }
        ip_split = strtok(NULL, ".");
        count ++;

    }
    if(count!=4){
        bool = 0;
    }
    
    return bool;
}

int ConvertAscii(int number){char ascii = number; return ascii; }

int randomize(){return 1 + rand() / (RAND_MAX / (6 - 1 + 1) + 1);}

char *concat(char word1[100], char word2[100]){return strcat(word1, word2);}
