/*			Lab 2 Partial Example			*/



#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>


int main() {
char *path, *argv[20], buf[80], n, *p;
int m,j, status, inword, continu, pipes;

while(1) {

inword = 0;
p = buf;
m = 0;
continu = 0;



printf( "\nshhh> ");

while ( ( n = getchar() ) != '\n'  || continu ) {
	if ( n ==  ' ' ) {
		if ( inword ) {
			inword = 0;
			*p++ = 0;
	    }
	}
	else if (n == '\n')
		continu = 0;

	else if ( n == '\\' && !inword)
		continu = 1;

	else {
		if (!inword) {
		 inword = 1;
		 argv[m++] = p;
		 *p++ = n;
	 }
	 else
	 	*p++ = n;
	}
}
*p++ = 0;
argv[m] = 0;



if(strcmp(argv[0],"exit") == 0)
 exit (0);

/********************************************************************************/
/********************************************************************************/

if(fork() == 0) {
	execvp( argv[0], argv );
	printf ( " didn't exec \n ");
	}

wait(&status);

}
char *start[j];
for(j=0; j<=pipes; j++)
{
	if(argv[j]==0)
	{
		j++;
		start[j] = pipes+1;
	}

}
int lpipe[2], rpipe[2];
int i,N;
pipe(rpipe);
{
pid_t pid = fork();
if(pid>0)
{
	close(lpipe[0]);
	close(lpipe[1]);
}
lpipe[0]=rpipe[0];
lpipe[1]=rpipe[1];
}
    /* Run LS. */
    pid_t pid = fork();
    if (pid == 0)
    {
        /* Set stdout to the output side of the pipe, and run 'ls'. */
        dup2(rpipe[1], 1);
        close(rpipe[1]);
        close(rpipe[0]);
        char *argv[] = {"ls", NULL};
        execv("/bin/ls", argv);
        fprintf(stderr, "Failed to execute /bin/ls\n");
        exit(1);
    }

for(i = 1; i < N - 1; i++)
{
    pipe(rpipe); // make the next output pipe
    pid_t pid = fork();
    if (pid == 0)
    {
    close(lpipe[0]); // both ends are attached, close them on parent
    close(lpipe[1]);
    lpipe[0] = rpipe[0]; // output pipe becomes input pipe
    lpipe[1] = rpipe[1];

    char *argv[] = {"more", NULL};
        execv("/usr/bin/more", argv);
        fprintf(stderr, "Failed to execute /usr/bin/more\n");
        exit(1);
}

}
    /* Run WC. */
    if(n=creat("output.txt", 0754) < 0)
    exit(-1);
    pid = fork();
    if (pid == 0)
    {
        /* Set stdin to the input side of the pipe, and run 'wc'. */
        dup2(lpipe[0], 0);
        close(lpipe[0]);
        close(lpipe[1]);
        char *argv[] = {"wc", NULL};
        execv("/usr/bin/wc", argv);
        fprintf(stderr, "Failed to execute /usr/bin/wc\n");
        exit(1);
    }


return (0);

}
