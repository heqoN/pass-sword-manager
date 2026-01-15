#include "mainlib.h"
#include "utils.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sifreOlustur(void){
    temizle();
    printf("\n--------------------Sifre olusturma aracina hosgeldiniz.--------------------\n");

    int adet,basamak,yaz,secim1,secim2,secim3;
    char harfler[]="abcdefghijklmnoprstuvyz",sayilar[]="123456789",karakterler[]="!'^+&/()=?*#${[]}-_",sifre[100];
    int x,y,z,k;

    FILE *dosya = fopen("../password/passwords.txt", "w");

    if (dosya==NULL){
        hata("!! Dosya olusturulamadi !!");
        return 1;

    }

    while(1){
        printf("Kac tane sifre olusturulacak ?  >> ");
        scanf("%d",&adet);
        if (adet>0)
            break;
        hata("adet 0'dan buyuk olmali");
    }

    while (1){
        printf("Sifreler dosyaya yazdirilacakmi (txt) (Evet=1 , Hayir=0) ?   >> ");
        scanf("%d",&yaz);
        if (yaz==1 || yaz==0)
            break;
        hata("yanlis secim");
    }


    while(1){
        printf("Sifreniz kac basamakli olsun ?  >> ");
        scanf("%d",&basamak);
        if (basamak>0)
            break;
        hata("basamak 0'dan buyuk olmali");
    } 

    while (1){
        printf("Sifrenizde sayilar olsunmu ? (Evet=1 , Hayir=0)  >> ");
        scanf("%d",&secim1);
        if (secim1==1 || secim1==0)
            break;
        hata("yanlis secim");
    }

    while (1){
        printf("Sifrenizde harfler olsunmu ? (Evet=1 , Hayir=0)  >> ");
        scanf("%d",&secim2);
        if (secim2==1 || secim2==0)
            break;
        hata("yanlis secim");
    }

    while (1){
        printf("Sifrenizde ozel karakterler olsun mu ? (Evet=1 , Hayir=0) >> ");
        scanf("%d",&secim3);
        if (secim3==0 || secim3==1)
            break;
        hata("yanlis secim");

    }

    if (secim1==0 && secim2==0 && secim3==0){
        hata("en az 1'i bulunmali");
        return 1;
    }

    devam();

    for (int g=1 ; g<=adet ; g++){
        for (int i=0 ; i< basamak ; i++){
            y=rand()%strlen(sayilar);
            z=rand()%strlen(harfler); 
            k=rand()%strlen(karakterler);
        
            if (secim1==1 && secim2==1 && secim3==1){
                x=rand()%3;
                if (x==0)
                    sifre[i]=sayilar[y];
                else if (x==1)
                    sifre[i]=harfler[z];
                else
                    sifre[i]=karakterler[k];
            }

            else if (secim1==1 && secim2==1){
                x=rand()%2;
                if (x==0)
                    sifre[i]=sayilar[y];
                else
                    sifre[i]=harfler[z];
            }

            else if (secim1==1 && secim3==1){
                x=rand()%2;
                if (x==0)
                    sifre[i]=sayilar[y];
                else
                    sifre[i]=karakterler[k];
            }

            else if (secim2==1 && secim3==1){
                x=rand()%2;
                if (x==0)
                    sifre[i]=harfler[z];
                else
                    sifre[i]=karakterler[k];
            }
            
            else if (secim1==1)
                sifre[i]=sayilar[y];
            
            else if (secim2==1)
                sifre[i]=harfler[z];
            
            else
                sifre[i]=karakterler[k];

    

        }

        sifre[basamak] = '\0';
        printf("Olusturulan sifre : %s\n\n",sifre);

        if (yaz==1)
            fprintf(dosya,"%s\n",sifre);


    }

    devam();
    temizle();

    fclose(dosya);

    return 0;
}