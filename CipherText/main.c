#include <stdio.h>
#include <stdlib.h>
#include "CipherText.h"

int main(int argc, const char* argv[]){
    CipherText a;
    initCipherText(&a);
    if(cipher("Hello world!", 3, &a) == 1){
        char* plain = decipher(&a);
        if(plain != NULL){
            printf("%s = %s\n", plain, a.text);
            free(plain);
        }
    deleteCipherText(&a);
    return 0;
    }
}