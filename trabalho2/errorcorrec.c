#include"errorcorrec.h"
#include<stdio.h>
//Multidimensional Parity Check
//https://en.wikipedia.org/wiki/Multidimensional_parity-check_code

//two-dimensional parity-check code (optimal rectangular code)
//Usado: 2D
int* encMDPC(int* msg, size_t sz){
    //is the msg string? if so, parity digits, so this might be wrong
    //guarantee C=2?
    size_t totSz=sz+(sz/2)+2;
    int* msg2=malloc(sizeof(int)*totSz);
    size_t sum=0;
    size_t j=-1;
    for (size_t i=0;i<sz;++i){ //sz/2 ?
        sum+=msg[i]; //-'0'
        ///if (i==0){
        //    msg2[0]=msg[0]-'0';
        //}
        //else{
            msg2[j+(i%2)+1]=msg[i];//-'0'
        //}
        if ((i)%2!=0){
            //printf("%ld\n",sum3);
            j=i+(i+1)/2;
            //printf("%ld %ld\n",j,i);
            msg2[j]=sum;
            sum=0;
        }
    }
    sum=0;
    for (size_t i=0;i<sz;i+=2){
        //sum+=*(*(msg+i)+2);
        sum+=*((msg+i)); //-'0'
        /*if ((i+1)%2==0){

        }*/
    }
    msg2[totSz-2]=sum;
    sum=0;

    for (size_t i=1;i<sz;i+=2){
        //sum+=*(*(msg+i)+2);
        sum+=*((msg+i)); //-'0'
    }
    msg2[totSz-1]=sum;
    //realloc to add to array?
    //guarantee 2 -> sz/2 = lines lines+2=new parity
    return msg2;
}

//n-dimensional parity scheme
//error correction is guaranteed to correct up to n/2 errors, min distance is (n+1)

//Usado: 2D
int* decMDPC(int* msg, size_t sz){
    size_t newSz=sz-(sz/2);
    int* msg2=malloc(sizeof(int)*newSz);
    int j=0;
    for (size_t i=0;i<newSz;++i){
        //for (size_t j=1;j<=2;++j){
        msg2[i]=msg[i+j];
        //printf("%ld %d\n",i,msg2[i]);
        if (i%2!=0){
            ++j;
        }
        //}
    }
    return msg2;
}

//correcting decode
int* correcMDPC(int* msg, size_t sz){
    size_t newSz=sz-(sz/2); //8-4=4
    int* msg2=malloc(sizeof(int)*newSz);
    int j=0;
    //msg2=msg;
    //strcpy(msg2,msg);
    //printf("where\n");
    for (size_t i=0;i<sz-j-3;++i){ //up to newSz? //i+=3
        //for (size_t j=1;j<=2;++j){
         msg2[i]=msg[i+j];
        //printf("where\n");
        //printf("%ld %d\n",i,msg2[i]);
        if (i%2!=0){
            //printf("where\n");
            ///printf("%d %d %d %d\n", i, msg[i+j-1], msg[i+j], msg[i+j+1]);
            if (msg[i+j+1]!=abs(msg[i+j]+msg[i+j-1])){ //-'0' all
                //printf("4where%d\n",i);
                msg2[i-1]=abs(msg[i+j+1]-msg[i+j]); //-'0' all
                //printf("%d %d %d %d %d\n", i, msg[i+j-1], msg[i+j], msg[i+j+1],msg2[i+j-1]);
                ///printf("4where%d\n",i);
            }
            ++j;
        }
        //}
    }
    /*size_t sum=0;
    for (size_t i=0;i<sz;i+=2){
        //sum+=*(*(msg+i)+2);
        sum+=*((msg+i)); //-'0'
        /*if ((i+1)%2==0){

        }*/
    /*}
    if (msg[sz-2]!=sum){
        
    }*/
    
    return msg2;
}