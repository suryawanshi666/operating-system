/*Implement the c program to accept to integer to be sorted 
main function create a child process using fork system call
parent process sorts the integer using bubble sort 
and wait for child process using wait system call 
child process sort the integer using inseration sort */
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
void bubblesort(int arr[30],int n)
{
   int i,j,temp;
   for(i=0;i<n;i++)
   {
      for(j=0;j<n-1;j++)
      {
         if(arr[j]>arr[j+1])
         {
             temp=arr[j];
             arr[j]=arr[j+1];
             arr[j+1]=temp;
         }
      }
   }
   }
void inserationsort(int arr[30],int n)
{
   int i,j,temp;
   for(i=1;i<n;i++)
   temp=arr[i];
   j=i-1;
   while(j>=0&&temp<=arr[j])
   {
      arr[j+1]=arr[j];
      j=j-1;
   }
   arr[j+1]=temp;  
}

void sort()
{
   int arr[25],arr1[25],n,i,status;
   printf("\n enter the number of values in array");
   scanf("%d",&n);
   printf("\n enter the array elements");
   for(i=0;i<n;i++)
   scanf("%d",&arr[i]);
   int pid=fork();
   if(pid==0)
   {
      printf("\n child process\n:");
      printf("child process id=%d\n",getpid());
      inserationsort(arr,n);
      printf("\n element sorted using inseration sort");
      printf("\n");
      for(i=0;i<n;i++)
      printf("%d,",arr[i]);
      printf("\b");
      printf("\n parent process id=%d\n",getpid());
   }
   else
   {
       printf("parent process\n");
       printf("\n parent process id=%d\n",getpid());
       bubblesort(arr,n);
       printf("element sorted using bubblesort");
       printf("\n");
       for(i=0;i<n;i++)
       printf("%d,",arr[i]);
       printf("\n\n\n");
   }
}
int main()
{
   sort();
   return 0;
}
