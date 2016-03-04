#include "types.h"
#include "mmu.h"
#include "stat.h"
#include "user.h"
#include "param.h"
#include "fs.h"
#include "proc.h"
#include "x86.h"

#define ACQUIRE 1
#define RELEASE 0

// Initializes a spinlock
void lock_init(lock_t * lock){
  //YOUR CODE HERE
}

// Acquire spinlock 
void lock_acquire(lock_t * lock)
{
  //Keep spinning until lock aquired  	
  //YOUR CODE HERE

}

// Release spinlock
void lock_release(lock_t * lock)
{
  //YOUR CODE HERE

}

//Thread creation function which calls clone.
// Allocate a new thread stack and pass it to clone with size
int thread_create(void *(*func)(void*),void *arg){

  int ret;
  void *stack = malloc(PGSIZE);  

  if(!stack)
    return -1;

  ret = clone(stack, PGSIZE);
  if (ret == 0)  {
    //Call the thread function here
    (*func)(arg);
    //Free the stack after execution	
    free(stack);
    //Exit the thread
    exit();
  }
  else {
    return ret;
  }
}

//When called by parent, waits for child
//to finish or return
int thread_join(void)
{
  return wait();
}
