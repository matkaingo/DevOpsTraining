#include "psets.h"
#include <math.h>
#include <stdlib.h>
#define PSET1_MENU "\nMENU PSET 1\n--------------\n1: mario_less\n2: mario_more\n3: cash\n4: credit\n0: Go back to main menu"
char temp; //temp statement to clear the buffer
void mario_less();
void mario_more();
void cash();
void credit();
int tryagain = 0;
int valid(long c);
int sumValues(long c);
char *Type(long c);

int p=0;
void pset1(){
    int p1 = 1;
    
    while (p1 != 0) {
        if(tryagain == 1){
            p1 = p;
        }else{
            system("clear");
            printf("%s\n", PSET1_MENU);
            scanf("%d", &p1);
        }

        switch(p1){
            case 1: mario_less(); break;
            case 2: mario_more(); break;
            case 3: cash(); break;
            case 4: credit(); break;
        }
   
	}

}
void repeat(char c, int times)
{
    while (--times >= 0)
    {
        printf("%c", c);
    }
}
void mario_less(){
    scanf("%c",&temp);
    system("clear");
    int height, width;

    do
    {
        printf("Height: ");
        scanf("%d", &height);
        width = height + 1;
    }
    while (height < 0 || height > 23);

    for (int i = 1; i <= height; i++)
    {
        int num_hashes = i + 1;
        int num_spaces = width - num_hashes;

        repeat(' ', num_spaces);
        repeat('#', num_hashes);

        printf("\n");
    }
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &tryagain);
    p=1;
}

void mario_more(){
    scanf("%c",&temp);
    system("clear");
        int height;
    
    do{
        
    printf("Height: ");
    scanf("%d", &height);
    
    }while(height<1 || height>8); //Asks for height until user inputs a height thats greater than 1 and lesser than 9
    
    int count=0;//counter to know number of hashes
    int i=0;//counter for the first loop
    int j=0; //counter for the second loop
    int k=0;//counter for the hashes
    
    if (height > 0 || height < 9){
        for(i=0;i<height;i++){//creates a loop that goes from 1 to height(the number the user added)
        if (count != height){
    	    for(j=(height-1)-count;j>0;j--){//Loop to create the spaces till de first block of the pyramid
                printf(" "); //prints space
    	    }
                for(k=0;k<=count;k++){ //Creates hashes form the left side
                    printf("#"); //prints hash
                }
                  printf("  "); //Middle space
                  
                for (k=0; k <=count; k++) {  //Creates hashes form right side
                    printf("#"); //prints hash
                }
                
                printf("\n");//new line
                
                count++; //increments the counter
            }
        }
    }
        puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &tryagain);
    p=2;  
}

void cash(){
    scanf("%c",&temp);
    system("clear");
    int cents_owed;
    float dollars_owed;
    do
    {
        printf("Change owed: ");
        scanf("%f", &dollars_owed);
        cents_owed = round(dollars_owed * 100);
    }
    while (cents_owed <= 0);

    int quarters = cents_owed / 25;
    int dimes = (cents_owed % 25) / 10;
    int nickels = ((cents_owed % 25) % 10) / 5;
    int pennies = ((cents_owed % 25) % 10) % 5;

    printf("%d\n", quarters + dimes + nickels + pennies);

        puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &tryagain);
    p=3;  
}

void credit(){
    scanf("%c",&temp);
    system("clear"); 
    long cnumber;

   do{
       printf("Number: ");
       scanf("%ld",&cnumber);
   }while(cnumber<0);

   char *kind=Type(cnumber);

    if((valid(cnumber))==1){
        printf("%s",kind);
    }else{
        printf("INVALID\n");
    }
      puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &tryagain);
    p=4;  
}
int valid(long c){
    int len=0;
    int sum=sumValues(c);
    int boo=0; //int that acts as a boolean if a statement is false then its 0, if its true then its 1

    for(len=0;c!=0;len++){//For to get the lenght of the long
        c=c/10;
    }

    if((len==13)||(len==15)||(len==16)){
        if(sum==1){
            boo=1;
        }
    }

    return boo;
}

int sumValues(long c){
    int sum=0;
    int boo=0; //int that acts as a boolean if a statement is false then its 0, if its true then its 1
    for(int i=0;c!=0;i++){
        if((i%2)==0){ //if i is even
            sum+=c%10;
        }
        else{
            int d=2*(c%10);
            sum+=(d/10)+(d%10);
        }
        c=c/10;

    }
    if((sum%10)==0){
            boo=1;
        }
    return boo;
}

char *Type(long c){
    char *type="INVALID\n";

    if((c>33e13 && c<35e13) || (c>=37e13 && c<38e13)){
        type="AMEX\n";
    }
    else if(c>50e14 && c< 56e14){
        type="MASTERCARD\n";
    }
    else if((c>=4e12 && c<5e12) || (c >= 4e15 && c < 5e15)){
        type="VISA\n";
    }

    return type;
}