#include<stdio.h>
#include"crc/crc.h"
#include"errorcorrec.h"
//#include<math.h>

//gcc main.c errorcorrec.c ./crc/crc.c -o main -lm
int main(void){
    char c2[14] = "11010011101100";
    char c[4] = "1011";
    unsigned int data[] = {1,2,3,4,5,6,7,8,9}; //uint8_t
    printf("Assinatura CRC de 123456789, funcao por tabela: %u\n",CRC32Wiki(data,9)); //1511307769???
    printf("Assinatura CRC de 123456789, funcao sem tabela: %u\n\n",crc32((char*)data,9)); 
    printf("Processo do Remainder:\n");
    printf("\nChecagem de remainder de 11010011101100 com 1011: %s\n\n",crcRemainder(c2,c,'0')); //crcRemainder(c2,c,'0')[1]
    printf("Checando se 11010011101100 com 1011 da 101:\n");
    crcCheck(c2,c,"101");
    //size_t msg[6]={1,2,3,4,6,7};
    ///char msg[6]="123467";
    int msg[6]={1,2,3,4,6,7};
    
    //printf("%ld\n",encMDPC(msg,6));
    printf("\nCodificando 123467 em MDPC: \n");
    int* ret=encMDPC(msg,6);
    for (int i=0;i<(6+3+2);++i){
        //printf("%d %d %c\n",i,ret[i],ret[i]);
        printf("%d ",ret[i]);
    }
    printf("\n");
    printf("Decodificando em MDPC: \n");
    ret = decMDPC(ret,11); //11 //3232
    for (int i=0;i<(6);++i){ //6
        printf("%d ", ret[i]);
    }
    printf("\n");
    
    int retPraCorrigir[8]={2,2,5,3,2,5,5,4};
    //int retPraCorrigir[11]={3,2,5,2,2,5,4,2,8,9,6};
    printf("Corrigindo e decodificando 225 325 54 em MDPC: \n");
    int* newRetCorr = correcMDPC(retPraCorrigir,8); //11 //3232
    for (int i=0;i<(4);++i){ //6
        printf("%d %d %c\n",i,newRetCorr[i],newRetCorr[i]);
    }
}