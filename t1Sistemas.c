#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include "t1.h"

//---Parte a.---//

uint borrar_bits(uint x, uint pat, int len){

    uint masc = (1 << len) - 1;

    while (pat != 0) {
        //Cuando encuentra el patron
        if ((x & masc) == pat){
            x = x&(~masc);
            masc = masc << len;
            pat = pat << len;
        }
        //Cuando no encuentra el patron
        else {
            masc = masc << 1;
            pat = pat << 1;
        }
    }

    return x;
}

//---Parte b.---//

char *reemplazo(char *s, char c, char *pal){

    //Tamaño pal
    int lenPal = 0;
    char *pala = pal;
    while(*pala != '\0'){
        lenPal += 1;
        pala++;
    }

    //Tamaño string resultante
    int l = 0;
    char *sa = s;
    while(*sa != '\0'){
        if (*sa == c){
            l += lenPal;
        }
        else {
            l += 1;
        }
        sa++;
    }

    //Creacion string resultante
    char *sf = malloc(l*sizeof(int) + 1);
    *sf = '\0';
    char *sfa = sf;
    sa = s;
    while(*sa != '\0') {
        if (*sa == c) {
            pala = pal;
            for (int i = 0; i < lenPal; i++){
                *sf = *pala;
                pala++;
                sf ++;
            }
        }
        else {
            *sf = *sa;
            sf++;
        }
        sa++;
    }
    *sf = '\0';
    return sfa;
}

//---Parte c.---//

void reemplazar(char *s, char c, char *pal){

    //Tamaño pal
    int lenPal = 0;
    char *pala = pal;
    while(*pala != '\0'){
        lenPal += 1;
        pala++;
    }

    //Tamaño s
    int ls = 0;
    char* ss = s;
    while (*ss != '\0'){
        ls += 1;
        ss++;
    }

    //Tamaño string resultante
    int l = 0;
    char *sa = s;
    while(*sa != '\0'){
        if (*sa == c){
            l += lenPal;
        }
        else {
            l += 1;
        }
        sa++;
    }

    //String resultante
    if (lenPal == 0){
        char *sa1 = s;
        char *sa2 = s;
        int i = 0;
        while (i != l){
            if (*sa2 == c){
                sa2++;
            }
            *sa1 = *sa2;
            sa1++;
            sa2++;
            i++;
        }
        *sa1 = '\0';
    }

    if (lenPal == 1){
        char *sa3 = s;
        while (*sa3 != '\0'){
            if (*sa3 == c){
                *sa3 = *pal;
            }
            sa3++;
        }
    }

    if (lenPal > 1){
        int fin = ls;
        char *sa4 = s + ls - 1;
        char *sa5 = s + l - 1;
        char *saaaaaaaaaaaaaaaaaaaaaaaa = s + l;
        *saaaaaaaaaaaaaaaaaaaaaaaa = '\0';
        while (fin != 0){
            char *p1 = pala - 1;
            if(*sa4 == c){
                for (int i = 0; i < lenPal; i++) {
                    *sa5 = *p1;
                    p1--;
                    sa5--;
                }
            }
            else{
                *sa5 = *sa4;
                sa5--;
            }
            fin -= 1;
            sa4--;

        }
    }

}
