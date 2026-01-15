#include "utils.h"
#include "mainlib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sifreKontrol(void){
    
    temizle();

    char sifre[100];
    printf("Sifreni gir  >> ");
    scanf("%s",sifre);

    int uzunluk = strlen(sifre);

    char *dizi = malloc((uzunluk + 1) * sizeof(char));
    strcpy(dizi, sifre);


    char harfler[]="abcdefghijklmnoprstuvyz",sayilar[]="123456789",karakterler[]="!'^+&/(=?_-*[]){}$#@,,;.:";
    int harfSayisi=0,sayiSayisi=0,karakterSayisi=0;

    for (int i = 0; i < uzunluk; i++) {
        
        if (isalpha(dizi[i])) {
            harfSayisi++;
        } 
        
        else if (isdigit(dizi[i])) {
            sayiSayisi++;
        } 
        
        else {
            for (int j = 0; j < strlen(karakterler); j++) {
                if (dizi[i] == karakterler[j]) {
                    karakterSayisi++;
                    break;
                }
            }
        }
    }
    free(dizi);

    int yuzde=harfSayisi*5 + sayiSayisi*4 + karakterSayisi*12;
    yuzde = (yuzde>100) ? yuzde=100 : yuzde;

    printf("\n\nSifrenin guvenilirligi >> %%%d \n.",yuzde);

    devam();
    temizle();

    return 0;
}