#ifndef __ERRORCORRECT__
#define __ERRORCORRECT__
#include<stdlib.h>
#include<math.h>
#include<string.h>

int* encMDPC(int* msg, size_t sz);
int* decMDPC(int* msg, size_t sz);
int* correcMDPC(int* msg, size_t sz);

#endif