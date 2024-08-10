/*write a c program to illustrate the concept of orphan process 
parent process create a child and terminate before child  has finished its task
so child process become orphan process (Use fork(),sleep(),getpid(),getppid())*/
#include<stdio.h>
#include<sys/type.h>
#include<unistd.h>
int main()
{
   pid_t pid;
   pid=fork();
   if(pid==0)
   {
       printf("\n i am child process,id=%d\n",getpid());
       printf("\n priority:%d,id=id\n",nice(-7),getpid());
   }
   else
   {
        printf("\n i am parent process,id=%d\n",getpid());
        nice(1);
        printf("\n priority:%d,id=id\n",nice(15),getpid());
   }
   return 0;
}
