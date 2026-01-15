#include "mainlib.h"

#include <stdlib.h>
#include <stdio.h>



void hata(char *mesaj){
    printf("\n\nLutfen tekrar deneyin .Hata : %s .\n\n",mesaj);
}



void temizle(void){
    printf("\033[2J\033[H");
}



void devam(void) {
    printf("\nDevam etmek icin Enter'a basin...");
    
    while (getchar() != '\n'); 
    getchar(); 
}
