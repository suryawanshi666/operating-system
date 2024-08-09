/*implement the c program to create a child process using fork(),
display parent and child process id. child process will display
the message"i am child process"and the parent process should display
"i am parent process*/
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    int pid=fork();
    if(pid>0)
    {
       printf("I am parent process\n");
       printf("ID:%d\n\n",getpid());
    }
    else if(pid==0)
    {
        printf("I am child process\n");
        printf("Id:%d\n",getpid());
    }
    else
    {
       printf("Faild to create child process");
    }
    return 0;
}
