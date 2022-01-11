#include "psets.h"
#include <math.h>
#include <stdlib.h>
#include <cs50.h>
#define PSET2_MENU "\nMENU PSET 2\n--------------\n1: readability\n2: Caesar\n3: Subsitution\n0: Go back to main menu"
char temp; //temp statement to clear the buffer
void readability();
void Caesar();
void Substitution();
int again = 0;
int grade(double L, double S);
double words(char *text);
double letters(char *text, double words);
double sentences(char *text, double words);

int pointer = 0;
void pset2(){
    int p2 = 1;
    
    while (p2 != 0) {
        system("clear");
        if(again == 1){
            p2 = pointer;
        }else{
            
            printf("%s\n", PSET2_MENU);
            scanf("%d", &p2);
        }

        switch(p2){
            case 1: readability(); break;
            case 2: Caesar(); break;
            case 3: Caesar(); break;
            case 0: break;
        }
   
	}

}
int encipher(string plaintext, int key);
int test_arguments(int arguments, string key[]);
void Caesar(){
    scanf("%c",&temp);
    system("clear");
        string plaintext = get_string("plaintext: ");
        int key = get_int("key: ");
        encipher(plaintext, key);
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &again);
    pointer=2;
}
int encipher(string plaintext, int key)
{
    
    printf("ciphertext: ");
    char ci;
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
        int c = plaintext[i];

        if (isalpha(c))
        {
            ci = c + key % 26;
            bool test_boundaries = islower(ci) || isupper(ci);
            if (!test_boundaries)
            {
                ci -= 26;
            }
        }
        else
        {
            ci = c;
        }
        ciphertext[i] = ci;
    }
    printf("%s\n", ciphertext);
    return 0;
}

void readability(){
    scanf("%c",&temp);
    system("clear");
    double L = 0;
    double S = 0;
    int grade_level = 0;
    double nwords = 0;
    string text = get_string("Text: ");
    nwords = words(text);
    L = letters(text, nwords);
    S = sentences(text, nwords);
    grade_level = grade(L, S);
    if(grade_level >= 0 && grade_level <= 16){
        printf("Grade %d\n", grade_level);
    }
    else if(grade_level > 16){
         printf("Grade 16+\n");
    }
    else{
        printf("Before Grade 1\n");
    }
    puts("\n \n \n....Escribe 1(Para volver a hacerlo) o Escribe 0(para volver al menu)");
	scanf("%d", &again);
    pointer=1;
}
//Using the Coleman-Liau index outputs returns the grade level
int grade(double L, double S){
    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
}

double letters(char *text, double words){
    double L = 0;
    double n_letters = 0;
    int size = 0;
    for(int i = 0, size = strlen(text); i < size; i++){
        if (text[i] >= 65 && text[i] <= 122)
        {
            n_letters++;
        }
     }//For end


    L = (n_letters/words)*100;

    return L;
}

double sentences(char *text, double words){
    double S = 0;
    double n_sentences = 0;
    int size = 0;
    for(int i = 0, size = strlen(text); i < size; i++){
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
                n_sentences++;
        }
     }//For end

    S = (n_sentences/words)*100;

    return S;
}

double words(char *text){
    double nwords = 0;
    int size = 0;

    for(int i = 0, size = strlen(text); i < size; i++){

        if (text[i] == 32 && (text[i - 1] != 33 && text[i - 1] != 46 && text[i - 1] != 63))
        {
            nwords++;
        }else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            nwords++;
        }

    }//For end

    return nwords;
}