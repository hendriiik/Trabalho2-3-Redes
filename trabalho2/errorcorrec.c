#include"errorcorrec.h"
#include<stdio.h>
//Binary
//https://en.wikipedia.org/wiki/Convolutional_code
//https://www.tutorialspoint.com/error-correcting-codes-binary-convolutional-code

//n is the number of encoder output bits corresponding to k info bits
//k= num of bits shifted into the encoder at one time, generally k=1
int encodeConv(size_t n, size_t k, size_t K2){
    double rc=(double)k/n; //code rate
    size_t sttencod = K2-1;

}
/*ex
k=1, n=2, K=3
rc=1/2;
input stream = 1011, put right to left into the encoder
*/

//Turbocode

//Linear Network Coding

//Multidimensional Parity Check
//https://en.wikipedia.org/wiki/Multidimensional_parity-check_code

//two-dimensional parity-check code (optimal rectangular code)
//Encoder?     //size_t
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

//correcting decode - might pass to decoder later
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
                printf("4where%d\n",i);
                msg2[i-1]=abs(msg[i+j+1]-msg[i+j]); //-'0' all
                printf("%d %d %d %d %d\n", i, msg[i+j-1], msg[i+j], msg[i+j+1],msg2[i+j-1]);
                printf("4where%d\n",i);
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

//Low-density parity
//forget about it, IT USES A FUCKING GRAPH
//


//Reed-Solomon
//https://en.wikipedia.org/wiki/Reed%E2%80%93Solomon_error_correction#:~:text=Reed%E2%80%93Solomon%20codes%20are%20able,erroneous%20symbols%20at%20unknown%20locations.
//https://www.tutorialspoint.com/error-correcting-codes-reed-solomon-codes
//https://www.geeksforgeeks.org/what-is-reed-solomon-code/
//https://www.cs.cmu.edu/~guyb/realworld/reedsolomon/reed_solomon_codes.html

//int gRS[]

//to encode m-bit symbols
long long* RS(size_t n, size_t k){
    //block length (n) is given by 2*m-1 symbols;
    size_t parCheck = n-k; //Parity Check size or 2t
    //message size needs to be n-2t
    double t=(double)(parCheck)/2.0; //t = number of errors corrected
    //min distance is given by (2t+1) (a)
    //message size is k bits ?
    //generator function //alpha is primitive element
        //g(x)=(x-alpha)(x-alpha^2)(x-alpha^3)...(x-alpha^2t)
    long long* g=malloc(sizeof(long long)*2*t);
    return g;
}

int encodeRS(long long* p, size_t k){
    //encode message as polyn p(x)
    //p * g (rs); //multiply it with a code generator polnym (g(x))
    //map msg vector [x1,x2,...,xk] to polyn p(x) of degree < k
        //px(alpha i)=xi for all i=1,2,3,...k
    //use interpolation methods such as lagrange
    //sender calculates s(x) = p(x)*g(x) and then sends over the coefficients of s(x)
}

//receiver end
int decodeRS(){
    //receives r(x)
    //divides r(x)/g(x)
    //r(x)/g(x) = 0 no error
    //rx/g(x)!=0, error polyn is evaluated just like the below one
    //or
    //if s(x)==r(x) then r(x)/g(x) has no remainder
    //if it has remainder, r(x)=p(x)*g(x)+e(x), e(x) is error polyn
    //error polyn gives error pos
}