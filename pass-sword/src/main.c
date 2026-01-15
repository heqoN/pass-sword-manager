#include "mainlib.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    srand(time(NULL));
    printf("\n\n   --------------------Pass Sword'a hosgeldin.--------------------");

    int cikis=0,secim;
    while(cikis==0){
        temizle();

        printf("\n   Menu  :\n\n   1- Sifre olustur\n   2- Brute force\n   3- Sifre kontrol\n   4- Sifreleme\n   5- Cikis\n\n     >>> ");
        scanf("%d",&secim);

        switch (secim){
            case 1:
                sifreOlustur();
                break;

            case 2:
                bruteForce();
                break;
            
            case 3:
                sifreKontrol();
                break;
            
            case 4:
                sifreleme();
                break;

            case 5:
                cikis=1;
                break;
            default :
                hata("yanlis secim");
        }
    }

    return 0;
}