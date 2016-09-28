#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char ** argv) {

  int pageSize = 4096;

  int i;
  int j;
  int  numOfPages;
  int method;

  method = atoi(argv[2]);

  numOfPages = atoi(argv[1]);

  printf ("method,num: %d %d  \n", method,  numOfPages);


  if(method == 1){

  char* pageArray = (char*)malloc(numOfPages * pageSize);
  printf ("method 1  \n");


  int k = 0;
  for(k =0; k < numOfPages * pageSize; k+= pageSize){

    //    printf ("k: %d \n", k);
    pageArray[k] = 'P';

      }

  }else {

    printf ("method 2  \n");

  int pf[numOfPages][pageSize];
  int pagePop = 0;

  for (i = 0; i < pageSize; i++) {
      for (j=0; j<numOfPages; j++) {
        pagePop += pf[j][i];
      }
  }

 }

}





