/***************************************************
* Assign 3 Part a) without mutual exclusion
* Program: mutexPartA.c
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <math.h>

const float AB = .10;
const float CD = .15;

void *pirateA();
void *pirateB();
void *pirateC();
void *pirateD();

int numPearls = 1000;
int totalTaken = 0;

int main(){
  pthread_t tid; // create thread variable

  pthread_setconcurrency(4); // create 4 threads

  pthread_create(&tid, NULL, (void *(*)(void *))pirateA, NULL);
  pthread_create(&tid, NULL, (void *(*)(void *))pirateB, NULL);
  pthread_create(&tid, NULL, (void *(*)(void *))pirateC, NULL);
  pthread_create(&tid, NULL, (void *(*)(void *))pirateD, NULL);

  pthread_exit(0);

}

void *pirateA(){

  while(numPearls > 0){
    int amtTaken = 0;
    amtTaken = ceil(numPearls * AB);
    totalTaken += amtTaken;
    sleep(1);
    numPearls -= amtTaken;
    printf("\nPirate A has got %d pearls \n", amtTaken);
    printf("\nUpdated total pearls taken: %d \n", totalTaken);

  }
}

void *pirateB(){

  while(numPearls > 0){
    int amtTaken = 0;
    amtTaken = ceil(numPearls * AB);
    totalTaken += amtTaken;
    sleep(1);
    numPearls -= amtTaken;
    printf("\nPirate B has got %d pearls \n", amtTaken);
    printf("\nUpdated total pearls taken: %d \n", totalTaken);


  }
}

void *pirateC(){
  while(numPearls > 0){
    int amtTaken = 0;
    amtTaken = ceil(numPearls * CD);
    totalTaken += amtTaken;
    sleep(1);
    numPearls -= amtTaken;
    printf("\nPirate C has got %d pearls \n", amtTaken);
    printf("\nUpdated total pearls taken: %d \n", totalTaken);

  }
}

void *pirateD(){
  while(numPearls > 0){
    int amtTaken = 0;
    amtTaken = ceil(numPearls * CD);
    totalTaken += amtTaken;
    sleep(1);
    numPearls -= amtTaken;
    printf("\nPirate D has got %d pearls \n", amtTaken);
    printf("\nUpdated total pearls taken: %d \n", totalTaken);


  }
}
