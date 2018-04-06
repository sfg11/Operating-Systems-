$ gcc -o runA noMutexPartA.c -lpthread -lm
./runA
$ gcc -o runB mutexPartB.c -lpthread -lm
./runB