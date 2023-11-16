#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char string[1024];

const char alphabet[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
char Cryptab[26][26];

void CreateCryptab() {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int somme = i+j;
            while(somme > 25) {
                somme -= 25;
            }
            Cryptab[i][j] = alphabet[somme];
        }
    }
}

void PrintCryptab() {
    printf("    ");
    for(int i = 0; i < 26; i++) {
        printf(" %c  ", alphabet[i]);
    }
    for(int i = 0; i < 26; i++) {
        printf("\n    --------------------------------------------------------------------------------------------------------\n %c |", alphabet[i]);
        for(int j = 0; j < 26; j++) {
            printf(" %c |", Cryptab[i][j]);
        }
    }
    printf("\n    --------------------------------------------------------------------------------------------------------\n");
}


void Decrypt(string saisie, string key) {
    string uncrypted;
    int lsaisie = strlen(saisie);
    int lkey = strlen(key);
    int j = 0;
    for(int i = 0; i < lsaisie; i++) {
        saisie[i] = toupper(saisie[i]);
        key[j] = toupper(key[j]);
        int somme = (saisie[i]-65) - (key[j]-65);
        while(somme < 0) {
            somme += 25;
        }
        uncrypted[i] = alphabet[somme];
        printf("%c - %c -> %c\n", saisie[i], key[j], uncrypted[i]);
        j++;
        if(j >= lkey) {
            j = 0;
        }
    }
    printf("Valeur decryptee: %s\n", uncrypted);
}

void Encrypt(string saisie, string key) {
    string Crypted;
    int lsaisie = strlen(saisie);
    int lkey = strlen(key);
    int j = 0;
    for(int i = 0; i < lsaisie; i++) {
        saisie[i] = toupper(saisie[i]);
        key[j] = toupper(key[j]);
        int somme = (saisie[i] + key[j]) - 130;
        while(somme >= 25) {
            somme -= 25;
        }
        Crypted[i] = alphabet[somme];
        printf("%c + %c -> %c\n", saisie[i], key[j], Crypted[i]);
        j++;
        if(j >= lkey) {
            j = 0;
        }
    }
    printf("Valeur cryptee: %s\n\n", Crypted);
}

void main() {
    CreateCryptab();
    string toEncrypt;
    string encryptKey;
    PrintCryptab();
    printf("Chaine a crypter: ");
    scanf("%s", toEncrypt);
    printf("Cle de cryptage:  ");
    scanf("%s", encryptKey);
    Encrypt(toEncrypt, encryptKey);
    string toDecrypt;
    string decryptKey;
    printf("Chaine a decrypter: ");
    scanf("%s", toDecrypt);
    printf("Cle de cryptage:  ");
    scanf("%s", decryptKey);
    Decrypt(toDecrypt, decryptKey);
}
