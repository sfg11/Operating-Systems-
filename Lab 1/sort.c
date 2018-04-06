/***************************************************
* Lab 1 Part b)
* Program: sort.c
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student{
  char name[20];
};

int main(){

  struct student myStudent[20];
  int i;
  int j;
  char *line = NULL; // mark end of string
  size_t len = 0;
  int numStudents = 0;
  struct student temp;

  //printf("Enter name to stop press Ctrl+D :\n");

  for(i = 0; i < 20; i++) {
    if (getline(&line, &len, stdin) != -1) {
      sscanf(line,"%s", myStudent[i].name);
      numStudents++;
    } else {
       break;
     }
  }

  for (i = 0; i < numStudents; i++) {
    for(j = i; j < numStudents; j++) {
      if (strcmp(myStudent[i].name, myStudent[j].name) > 0){
        strcpy(temp.name, myStudent[i].name);
        strcpy(myStudent[i].name, myStudent[j].name);
        strcpy(myStudent[j].name, temp.name);
      }
    }
  }
  for (i = 0; i < numStudents; i++) {
    printf("%s\n", myStudent[i].name);
  }

  return 0;
}
