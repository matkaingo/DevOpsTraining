#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "psets.h"
#define MAIN_MENU "\nMENU Cs50\n--------------\n1: pset1\n2: pset2\n0: Exit\n"

int op = 1;
int try_again = 0;

int main(void) {
	while (op != 0) {
        system("clear");
        printf("%s",MAIN_MENU);
        scanf("%d", &op);
        switch(op){
            case 1: pset1(); break;
            case 2: pset2(); break;
            case 0: break;
        }
   
	}
}