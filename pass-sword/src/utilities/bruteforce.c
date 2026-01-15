#include "mainlib.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int rastgele(void){
    while(1){
        int hedef;
        while(1){
            printf("Hedef sayiyi girin (6 basamakli)  >> ");
            scanf("%d",&hedef);
            if (hedef>99999 && hedef<1000000)
                break;
            hata("6 basamakli degil.");
        }

        int adet;
        while(1){
            printf("Kac tane sifre olusturmak istiyorsun  >> ");
            scanf("%d",&adet);
            if(adet>0)
                break;
            hata("adet 0 dan buyuk olmali.");
        }

        int *sifreDizisi = malloc(adet * sizeof(int)); 

        for (int i = 0; i < adet; i++) {
            int sayi = (rand() % 9) + 1; 
            for(int j = 0; j < 5; j++) { 
                sayi = sayi * 10 + (rand() % 10);
            }
            sifreDizisi[i] = sayi;
        }
        devam();


        int bulundumu=0;
        for (int i=0 ; i<adet ; i++){
            if (sifreDizisi[i]==hedef){
                printf("Sifre %d. denemede bulundu , Sifre = %d \n",i+1,hedef);
                bulundumu=1;
                break;
            }

            else{
                printf("%d. denenen sifre %d\n",i+1,sifreDizisi[i]);
            }
        }
        free(sifreDizisi);

        if (bulundumu==0){
            printf("Sifre bulunamadi :(\n\n");
        }

        char devammi;
        printf("Tekrar denemek istiyor musun (e/h)  >> ");
        scanf(" %c",&devammi);

        if (devammi=='e')
            continue;
        else if (devammi=='h')
            break;
        else{
            hata("ne girdin ??????????????");
            break;
        }


    }

    devam();
    temizle();

    return 0;
}



int ardisik(void){
    int hedef;
    while(1){
        printf("Hedef sayi gir  >> ");
        scanf("%d",&hedef);
        if (hedef>0)
            break;
        hata("yanlis secim");
    }

    int i=1,bulundumu=0;
    while(1){
        if (i==hedef){
            printf("\nSifre bulundu > %d\n\n",i,i);
            bulundumu=1;
            break;
        }
        else
            printf("Deneme : %d\n",i);
        
        i++;
    }

    if (bulundumu==0)
        printf("\n\nSifreniz bulunamadı :( \n\n");

    devam();
    temizle();

    return 0;
}



int disaridan(void){
    temizle();

    printf("\n!! BILGI : Sifre dosyasinin adi mypasswords.txt ve password klasorunde olmali .\n           Dosyanin duzeni satir>sifre olmali.\n\n\n");
    devam();

    FILE *dosya = fopen("../password/mypasswords.txt","r");

    if (dosya==NULL){
        hata("dosya yok");
        devam();
        return 0;
    }
    printf("\nDosya iceri aktarildi !!\n\n\n");

    char hedef[100];
    printf("Hedef sifre gir  >> ");
    scanf("%s",hedef);

    char bulundu=0,okunanSifre[100];
    int i=1;

    while (fscanf(dosya,"%s",okunanSifre)==1){
        if (strcmp(okunanSifre, hedef) == 0){
            bulundu=1;
            break;
        }

        i++;
    }

    fclose(dosya);

    if (bulundu==1)
        printf("\nSifre %d. satirda bulundu ve hedef => %s .\n\n",i,hedef);

    else 
        printf("\nBulunamadi .\n\n");


    devam();
    temizle();

    return 0;
}



int bruteForce(void){
    temizle();
    printf("Brute Force uygulamasina hosgeldin.\n\n");

    int secim;
    while(1){
        while(1){
            printf("   Menu :\n\n     1- Rastgele sayi olusturma ile brute force\n     2- Ardisik brute force\n     3- Disaridan dosya yukleyerek brute force\n     4- Geri\n\n   >>> ");
            scanf("%d",&secim);
            if (secim==1 || secim==2 || secim==3 || secim==4)
                break;
            hata("yanlis giris");
        } 

        switch(secim){
            case 1:
                rastgele();
                break;

            case 2:
                ardisik();
                break;

            case 3:
                disaridan();
                break;

            case 4:
                return 0;

        }
    }

    temizle();
    
    return 0;
}