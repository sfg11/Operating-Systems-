/***************************************************
* Assign 4
* Program: lab4
* Description: Compare the number of page faults
* generated by the Optimal and LRU algorithms. If
* there is a tie, randomly choose one to break the
* tie. Print out the page replacement process and
* you can see how LRU differs from the optimal.
* Author: Sarah Gibbons
* Class: CS 4328, Dr. Chen, T-TH 9:30
***************************************************/
#include <stdio.h>

int numFrames;
int numPages;
int frames[10];
int pages[30];
int t[10];
int time[];
int f1, f2, f3;
int i, j, k;
int position;
int max, min;
int numFaults = 0;
int counter;

int optimal(int*, int, int);
int LRU(int*, int, int);
int findLRU(int *, int);

int main(){

  printf("\n Enter number of frames:");
  scanf("%d", &numFrames);

  printf("\n Enter number of pages: ");
  scanf("%d", &numPages);

  printf("\n Enter page reference string: ");


  for(i = 0; i < numPages; ++i){
    scanf("%d", &pages[i]);
  }
  optimal(pages,numFrames, numPages);
  LRU(pages, numFrames, numPages);
  return 0;
}

int optimal(int *pages, int numFrames, int numPages){
  for(i = 0; i < numFrames; ++i){
    frames[i] = -1;
  }

  for(i = 0; i < numPages; ++i){
    f1 = f2 = 0;

    for(j = 0; j < numFrames; ++j){
      if(frames[j] == pages[i]){
        f1 = f2 = 1;
        break;
      }
    }

    if(f2 == 0){
      f3 =0;

      for(j = 0; j < numFrames; ++j){
        t[j] = -1;

        for(k = i + 1; k < numPages; ++k){
          if(frames[j] == pages[k]){
            t[j] = k;
            break;
          }
        }
      }

      for(j = 0; j < numFrames; ++j){
        if(t[j] == -1){
          position = j;
          f3 = 1;
          break;
        }
      }

      if(f3 ==0){
        max = t[0];
        position = 0;

        for(j = 1; j < numFrames; ++j){
          if(t[j] > max){
            max = t[j];
            position = j;
          }
        }
      }

      frames[position] = pages[i];
      numFaults++;
    }

    printf("\n");

    for(j = 0; j < numFrames; ++j){
      printf("\t%d\t", frames[j]);
    }
  }

  printf("\n\n OPTIMAL: Total Page numFaults = %d \n", numFaults);
}

int LRU(int *pages, int numFrames, int numPages){
  for(i = 0; i < numFrames; ++i){
    frames[i] = -1;
  }
  for(i = 0; i < numPages; ++i){
    f1 = f2 = 0;

    for(j = 0; j < numFrames; ++j){
      if(frames[j] == pages[i]){
        counter++;
        time[j] = counter;
        f1 = f2 = 1;
        break;
      }
    }
    if(f1 == 0){
      for(j = 0; j < numFrames; ++j){
        if(frames[j] == -1){
          counter++;
          numFaults++;
          frames[j] = pages[i];
          time[j] = counter;
          f2 = 1;
          break;
        }
      }
    }

    if(f2 == 0){
      int pos = findLRU(time, numFrames);
      counter++;
      numFaults++;
      frames[position] = pages[i];
      time[position] = counter;
    }
    printf("\n");
    for(j = 0; j < numFrames; ++j){
      printf("%d\t", frames[j]);
    }
  }
  printf("\n\n LRU: Total Page Faults = %d \n", numFaults);
}

int findLRU(int *time, int n){
  int pos;
  for(i = 1; i < n; ++i){
    if(time[i] < min){
      min = time[i];
      pos = i;
    }
  }
  return pos;
}
