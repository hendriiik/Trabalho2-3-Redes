#include<stdio.h>
#include"crc/crc.h"
#include"errorcorrec.h"
//#include<math.h>

int main(void){
    char c2[14] = "11010011101100";
    char c[4] = "1011";
    //int x[]={1,1,1,0,1,0,0,0}; int y[]={1,0,1,1}; int z=0; int rem=0;
    //for (int i=0;i<4;++i){
    //    z+=(x[i]^y[i])*pow(10,3-i);
        //printf("%d\n",y>>(3-i));
        //z+=((x[i]^(y>>(3-i)))*pow(10,3-i));
    //}
    //printf("%d\n",z);
    //char* ch="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";//=malloc(4);
    //ch=
    //printf("%s\n",nPadString(3,ch));
    unsigned int data[] = {1,2,3,4,5,6,7,8,9}; //uint8_t
    printf("%u\n",CRC32Wiki(data,9)); //1511307769???
    //printf("%s\n",crcRemainder(c2,c,'0')); //crcRemainder(c2,c,'0')[1]
    crcCheck(c2,c,"101");
    //size_t msg[6]={1,2,3,4,6,7};
    ///char msg[6]="123467";
    int msg[6]={1,2,3,4,6,7};
    //size_t msg[2][2]={{1,2},{3,4}};
    //printf("%ld\n",encMDPC(msg,6));
    /*int* ret=encMDPC(msg,6);
    for (int i=0;i<(6+3+2);++i){
        //printf("%d %d %c\n",i,ret[i],ret[i]);
        printf("%d ",ret[i]);
    }*/
    printf("\n");
    //printf("%s\n",ret);
    //ret="22532554";
    ///ret="325225428";
    //ret="12312324";
    int ret[8]={2,2,5,3,2,5,5,4};
    //int ret[11]={3,2,5,2,2,5,4,2,8,9,6};
    int* newRet = correcMDPC(ret,11); //11 //3232
    for (int i=0;i<(4);++i){ //6
        printf("%d %d %c\n",i,newRet[i],newRet[i]);
    }
    ///printf("%u\n",crc32("123456789",9));
}



//printf("%d %ld\n",nPad(3,1010),11010011101100000^1011);
    //z*10000;
    //z= (x[0]*1000+x[1]*100+x[2]*10+x[3]);
    //for (int i=3;i>=0;--i){
        //z=x[i]^(rem>>(0));
    //    z+=x[3-i]^(y>>i);//(y%10);
        //z*=10;
         //y/=10;
    //}
    //z-=10000;
    //printf("%d",z);
    //puts(nPad(3,c));