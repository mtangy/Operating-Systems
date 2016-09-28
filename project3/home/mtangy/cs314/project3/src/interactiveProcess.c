#include "lab2-api.h"


/*
uint32 my_timer_get(){
  uint32 temp = total_num_quanta * 100 + total_num_quanta * 1;
  return temp;
}
*/

main (int argc, char *argv[])
{
  int number, i,j,offset;
  uint32 handle,tStart,tFinish, tTotal;
  sem_t semaphore;
  char num_str[10], semaphore_str[10];

  int iterCount;
  //  tStart = TimerGet();

  

  offset = dstrtol(argv[1], NULL, 10);       //Get semaphore
  semaphore = dstrtol(argv[2], NULL, 10);       //Get semaphore

  
  for(i=0;i<3;i++)
    {

      //sem_wait(semaphore);
      for(j=0;j<50000;j++);
      Printf("interactive: %c%d\n",'A'+offset,i);
      //sem_signal(semaphore);
      ProcessSleep();
      
    }
  

}
