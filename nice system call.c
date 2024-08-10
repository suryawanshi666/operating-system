/*Write a program that demonstrates the use of nice() system call
after a child process is started using fork(),
assign highre priority to the child using nice() system call*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() 
{
   pid_t pid;
   int status;
   pid = fork();
   if (pid < 0) 
   {
       perror("fork failed");
       exit(EXIT_FAILURE);
    }
    else if (pid == 0) 
    {
        printf("Child process PID: %d\n", getpid());
        int new_nice_value = nice(-10); 
        if (new_nice_value == -1)
        {
           perror("nice failed");
           exit(EXIT_FAILURE);
        }
        printf("Child process new nice value: %d\n", new_nice_value);
        for (int i = 0; i < 5; i++) 
        {
            printf("Child process working... iteration %d\n", i+1);
            sleep(1);
        }

        exit(EXIT_SUCCESS);
    } 
    else 
    {
        printf("Parent process PID: %d\n", getpid());
        wait(&status);
        if (WIFEXITED(status)) 
        {
            printf("Child process exited with status %d\n", WEXITSTATUS(status));
        } 
        else 
        {
            printf("Child process did not exit successfully\n");
        }
    }

    return 0;
}


