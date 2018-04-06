/***************************************************
* Lab 1 #3
* Program: pipe.c
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  pid_t pid;
  int p[2];
  if(pipe(p) == -1) {
    perror("pipe");
    return -1;
  }

  if((pid = fork()) == -1) {
    close(p[0]);
    close(p[1]);
    perror("fork");
    return -1;
  }

  // Child
  if(pid == 0) {
    close(p[0]);  // Close read end of pipe.
    close(1);    // closes stdout
    dup(p[1]);
    close(p[1]);
    execlp("./pre", "pre", (void *) 0);  // Execute child program.
  }
  // Parent
  else {
    close(p[1]);   // Close write end of pipe.
    close(0);     // close stdin
    dup(p[0]);
    close(p[0]);
    execlp("./sort", "sort", (void *) 0);   // Execute parent program.
  }
  return 0;
}
