#include "types.h"
#include "user.h"
#include "stat.h"
#include "param.h"

int main(int argc, char *argv[])
{
  struct uproc up;
  int pid;

  printf(1, "name\tpid\tppid\tsz\tstate\tchan\tkilled\n"); // Print header

  for(pid = 1; pid < NPROC; pid++){ // Loop through all possible pids
    if(getprocinfo(pid, &up) == 0){ // If getprocinfo succeeds
      printf(1, "%s\t%d\t%d\t%d\t%d\t%d\t%d\n", up.name, up.pid, up.ppid, up.sz, up.state, up.chan, up.killed); // Print process information 
    }
  }

  exit(); // Exit the program
}