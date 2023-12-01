#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[])
{
  int pid, retime, rutime, stime;
  printf(1, "parent: %d\n", getpid());
  for(int i = 0; i < 3; i++){
    pid = fork();
    if(pid == 0){
      // child
      printf(1, "child: %d\n", getpid());
      for(int j = 0; j < 1000000000; j++); // busy loop
      exit();
    }
  }
  // parent
  for(int i = 0; i < 3; i++){
    pid = wait2(&retime, &rutime, &stime);
    printf(1, "pid: %d, ready: %d, running: %d, sleeping: %d\n", pid, retime, rutime, stime);
  }
  exit();
}