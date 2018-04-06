
/***************************************************
* Lab 1 Part a)
* Program: pre.c
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
***************************************************/
#include <stdio.h>
#include <stdlib.h>

struct student {
  char name[20];
  float gpa;
};

int main(){

  struct student myStudent[20];
  int i;
  char *line = NULL; // mark end of string
  size_t len = 0; // unisgned integer time to get gpa
  int numStudents = 0;

  printf("Enter name and gpa scores to stop press Ctrl+D :\n");

  for(i = 0; i < 20; i++) {
    if(getline(&line, &len, stdin) != -1) {
      sscanf(line,"%s %f",myStudent[i].name, &myStudent[i].gpa);
      numStudents++;
    } else {
      break;
    }
  }
  for(i = 0; i < numStudents; i++) {
    if(myStudent[i].gpa >= 3.0){
      printf("%s\n", myStudent[i].name);
    }
  }
  return 0;
}
