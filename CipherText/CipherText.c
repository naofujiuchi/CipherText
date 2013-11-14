#include <stdio.h>
#include <stdlib.h>
#include "CipherText.h"

int i;

//measure input string length
static int stringlen(const char* text){
    int max_length = 0;
    while(text[max_length] != 0){
        max_length++;
    }
    return max_length;
}

//initialize CipherText object and keep memory space
void initCipherText(CipherText* cipher){
    cipher->shift = 0;
    cipher->text = NULL;
}

//delete CipherText object and free memory space
void deleteCipherText(CipherText* cipher){
    if(cipher->text != NULL){
        free(cipher->text);
        cipher->text = NULL;
    }
}

//coding function 'cipher'
//input... ("HELLO WORLD", 3, &a)
//output... &a->text: KHOOR#ZRUOG
int cipher(const char* plain_text, int shift, CipherText* ioCipher){
    ioCipher->shift = shift;
    int length = stringlen(plain_text);
    if(ioCipher->text != NULL){
        free(ioCipher->text);
    }
    ioCipher->text = malloc(sizeof(char)*(length+1));
    if(ioCipher->text == NULL){
        return 0;
    }
    for(i = 0; i < length; i++){
        ioCipher->text[i] = plain_text[i] + ioCipher->shift;
    }
    ioCipher->text[length] = 0;
    return 1;
}

//decode function 'decipher'
//input... (&a, plain_text)
//output... plain_text: HELLO WORLD
char* decipher(const CipherText* cipher){
    int length = stringlen(cipher->text);
    char* text = malloc(sizeof(char)*(length + 1));
    if(text == NULL){
        return NULL;
    }
    for(i = 0; i < length; i++){
        text[i] = cipher->text[i] - cipher->shift;
    }
    text[length] = 0;
    return text;
}