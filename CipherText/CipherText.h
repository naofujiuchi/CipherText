#ifndef CipherText_CipherText_h
#define CipherText_CipherText_h

typedef struct{
    int shift;
    char* text;
}CipherText;

void initCipherText(CipherText* cipher);
void deleteCipherText(CipherText* cipher);
int cipher(const char* plain_text, int shift, CipherText* cipher);
char* decipher(const CipherText* cipher);

#endif