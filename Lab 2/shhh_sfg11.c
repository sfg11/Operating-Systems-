/******************************************************************
* To excute: gcc shh_sfg11.c -o run
* Assignment: Lab 2
* Program: shhh_sfg11.c
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
* Description: A small shell program that can do the following:
* 1. Can execute a command with the accompanying arguments.
* 2. Recognize multiple pipe requests and handle them.
* 3. Recognize redirection requests and handle them.
* 4. Type "exit" to quit the shhh shell.
**************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int main(){

  char *path, *argv[20], buf[80], n, *p;
  int m, status, inword, continu;
  int i, j;
  int left_fd[2];
  int right_fd[2];
  int start[20];
  int pipes, count;

  while(1) {
    pipes = 0;
    inword = 0;
    p = buf;
    m = 0;
    continu=0;
    printf( "\nshhh> ");
    count = 0;
    while ( ( n = getchar() ) != '\n'  || continu ) {
      if ( n ==  ' ' ) {
        if ( inword ) {
          inword = 0;
          *p++ = 0;
        }
      }
      else if ( n == '\n' ) continu = 0;
      else if ( n == '\\'&& !inword ) continu = 1;
      else {
        if ( !inword ) {
          inword = 1;
          argv[m++] = p;
          count++;
          *p++ = n;
        }else
        *p++ = n;
      }
    }
    *p++ = 0;
    argv[m] = 0;

    if ( strcmp(argv[0],"exit") == 0){
      exit (0);
    }

    char *fout[1];
    char *fin[1];
    pipes = 0;
    start[0] = 0;
    int iFlag = 0;
    int oFlag = 0;
    j = 1;
    // manage redirection
    for(i = 0; i < count; i++){
      if(argv[i] == NULL){
        break;
      } else if(strcmp(argv[i], "|") == 0){
        argv[i] = 0;
        pipes++;
        start[j] = i +1;
        j++;
      } else if(strcmp(argv[i], ">") == 0){
        oFlag = 1;
        argv[i] = 0;
        fout[0] = argv[i+1];
      }else if(strcmp(argv[i], "<") == 0){
        iFlag = 1;
        argv[i] = 0;
        fin[0] = argv[i+1];
      }
    }
    for(j = 0; j <= pipes; j++){
      if( pipes > 0 && j != pipes){
        pipe(right_fd);
      }

      int  PID;
      PID = fork();

      if(PID > 0 && pipes > 0){
        if(j > 0){
          close(left_fd[0]);
          close(left_fd[1]);
        }
        left_fd[0]=right_fd[0];
        left_fd[1]=right_fd[1];
        wait(&status);
      } else if(PID == 0){
        if(j == 0 && iFlag == 1){

          int ifd = open(fin[0], O_RDONLY);
          close(0);
          dup(ifd);
          close(ifd);
        } if(pipes > 0){
          if(j == 0){
            close(1);
            dup(right_fd[1]);
            close(right_fd[1]);
            close(right_fd[0]);
          } else if(j == pipes){
            close(0);
            dup(left_fd[0]);
            close(left_fd[0]);
            close(left_fd[1]);
          } else {
            close(1);
            dup(right_fd[1]);
            close(0);
            dup(left_fd[0]);
            close(right_fd[1]);
            close(right_fd[0]);
            close(left_fd[0]);
            close(left_fd[1]);
          }
        } if(oFlag == 1 && j == pipes) {
          int ofd = creat(fout[0], 00777);
          close(1);
          dup(ofd);
          close(ofd);
        }
        execvp(argv[start[j]], &argv[start[j]]);
      }
    }
    wait(&status);
  }
  return 0;
}
