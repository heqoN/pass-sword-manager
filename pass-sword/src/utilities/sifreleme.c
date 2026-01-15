#include "utils.h"
#include "mainlib.h"

#include <stdio.h>
#include <stdlib.h>



int sifrele(void){
    char sifre[100];
    int anahtar;

    printf("Sifreni gir  >> ");
    scanf("%s",sifre);

    printf("Anahtarini gir (0-10 arasi onerilir)  >> ");
    scanf("%d",&anahtar);

    for (int i=0 ; sifre[i]!='\0' ; i++){
        sifre[i]+=anahtar;
    }

    printf("\nSifrelenmis hali -> %s\n\n",sifre);

    devam();
}



int sifreCoz(void){
    char sifre[100];
    int anahtar;

    printf("Sifreni gir  >> ");
    scanf("%s",sifre);

    printf("Anahtarini gir (0-10 arasi onerilir)  >> ");
    scanf("%d",&anahtar);

    for (int i=0 ; sifre[i]!='\0' ; i++){
        sifre[i]-=anahtar;
    }

    printf("\nSifre cozulmus hali -> %s\n\n",sifre);

    devam();
}



int sifreleme(void){
    int secim;
    while(1){
        temizle();
        while(1){
            printf("   Menu :\n\n     1- Sifrele\n     2- Sifre coz\n     3- Geri\n\n   >>> ");
            scanf("%d",&secim);
            if (secim==1 ||secim==2 || secim==3)
                break;
            hata("yanlis secim");
        }

        switch(secim){
            case 1:
                sifrele();
                break;

            case 2:
                sifreCoz();
                break;

            case 3:
                return 0;
        }


    }
}