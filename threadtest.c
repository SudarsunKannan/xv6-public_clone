#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "param.h"

lock_t *lock;
int counter;

//Acquire lock and increment counter 
//by loop count
void *inc_counter(void * a)
{ 
  int i;   
  for(i = 0; i < (int)a; i++) { 
    //Acquire thread lock here
    //YOUR CODE HERE  

    counter++;  
    //Release thread lock here
    //YOUR CODE HERE
  }
  return 0;
}

//Check the counter value with output
int check(int numThrds, int numloops, int counter){

  //Check if result is correct
  if(counter != numThrds * numloops){
    return -1;
  }
  return 0;
}

int test(int numThrds, int numloops)
{
  int cnt=0;

  if (numThrds > NPROC - 3){
    printf(2, "Error: Max threads %d)\n", 61);
    exit();
  }
  counter = 0;
  lock = malloc(sizeof(lock_t));

  //Initialize the lock
  lock_init(lock);
  
  for (cnt = 0; cnt < numThrds; cnt++)
    //Thread will increament the counter by numloops
    if (thread_create(inc_counter,(void *)numloops) == -1){
      printf(2, "Error: thread_create failed");
      exit();
    }
		//Wait for all threads to get back
  for(; cnt > 0; cnt--)
    thread_join(); 

  free(lock);
  //For debugging
  //printf(1,"Counter: %d\n", counter);
  return check(numThrds, numloops, counter);
}

int main(void) {

  int numThrds=1;
  int numloops=1;

  if(test(numThrds, numloops)) {
     printf(1, "TEST 1 failed \n");
  }else{
    printf(1, "TEST 1 succeeded \n");
  }

  numThrds=61;
  numloops=50;

  if(test(numThrds, numloops)) {
     printf(1, "TEST 2 failed \n");
  }else{
    printf(1, "TEST 2 succeeded \n");
  }
  exit();	
}
