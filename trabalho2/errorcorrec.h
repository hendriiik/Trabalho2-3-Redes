#ifndef __ERRORCORRECT__
#define __ERRORCORRECT__
#include<stdlib.h>
#include<math.h>
#include<string.h>

char* encMDPC(char* msg, size_t sz);
char* decMDPC(char* msg, size_t sz);
char* correcMDPC(char* msg, size_t sz);

#endif