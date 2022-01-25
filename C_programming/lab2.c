#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


int op = 1;
int p = 0;
int try_again = 0;
char temp; //temp statement to clear the buffer
void lowerCase();
void upperCase();
void interpersing();
void replace();
void execCommand();

int main(void) {
	while (op != 0) {
        if(try_again == 1){
            op = p;
        }else{
            system("clear");
            puts("\nMENU LAB 1");
            puts("--------------");
            puts("1: Convert to lower case");
            puts("2: Convert to upper case");
            puts("3: Interpersing between lower and upper case");
            puts("4: Replace letter(input: String,letter_to_change,how_to_change)");
            puts("5: Execute linux command in console");
            puts("0: Exit");
            scanf("%d", &op);
        }

        switch(op){
            case 1: lowerCase(); break;
            case 2: upperCase(); break;
            case 3: interpersing(); break;
            case 4: replace(); break;
            case 5: execCommand(); break;
            case 0: break;

        }
   
	}
}

void lowerCase(){
    scanf("%c",&temp);
    int i = 0;
    system("clear");
    char name[50];
    printf("input something\n");
    scanf("%[^\n]",name);
    while( name[i] ) {
        putchar(tolower(name[i]));
        i++;
    }
            
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &try_again);
    p=1;
}

void upperCase(){
    scanf("%c",&temp);
    int i = 0;
    system("clear");
    char name[50];
    printf("input something\n");
    scanf("%[^\n]",name);
    while( name[i] ) {
        putchar(toupper(name[i]));
        i++;
    }
            
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &try_again);
    p=2;
}
void interpersing(){
    scanf("%c",&temp);
    int i = 0;
    system("clear");
    char name[50];
    printf("input something\n");
    scanf("%[^\n]",name);
    while( name[i] ) {
        if(i%2==0){
            putchar(toupper(name[i]));
        }else{
            putchar(tolower(name[i]));
        }
                
        i++;
    }
            
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &try_again);
     p=3;
}
void replace(){
    scanf("%c",&temp);
    char *name_split;
    int i = 0;
    int counter = 0;
    char *arg1;
    char arg2;
    char arg3;
    system("clear");
    
    char name1[50];
    printf("input something(String,letter_to_change,how_to_change)\n");
    scanf("%[^\n]",name1);
    //char name[50] = name1;
    name_split = strtok(name1, ",");
    while (name_split != NULL)
    {
        if(counter == 0){
            arg1 = name_split;
        }
        else if(counter == 1){
            arg2 = name_split[0];
        }
        else if(counter == 2){
            arg3 = name_split[0];
        }
        name_split = strtok(NULL, ",");
        counter++;
    }
    while( arg1[i] ) {
        if(arg2==arg1[i]){
            arg1[i]=arg3;
        }
        putchar(arg1[i]);
        i++;
    }
            
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &try_again);
     p=4;
}

void execCommand(){
    scanf("%c",&temp);
    int i = 0;
    system("clear");
    char name[50];
    printf("input a command\n");
    scanf("%[^\n]",name);
    system(name);
            
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &try_again);
    p=5;
}
