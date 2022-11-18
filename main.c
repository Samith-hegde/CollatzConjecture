// Samith Shripad Hegde
// 201ME349
// CS252 Assignment
// Question No. 3.21

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
	int k=0;
	
	pid_t pid;  // pid_t creates a process_id variable and stores the process_id of the current (parent) process, which can be used to access different process attributes

		do
		{
			printf("Enter a positive integer to run the Collatz Conjecture.\n"); 
  			scanf("%d", &k);	
		}while (k <= 0);

		pid = fork();  // fork() system call creates a child process, and returns process ID. Both the parent and child processes run concurrently after this line.

		if (pid == 0)  // fork() returns a 0 to the newly created child proccess, and the process ID (non-zero integer of the parent process)
		{
			printf("Child is working...\n");
			printf("%d\n",k);
			while (k!=1)
			{
				if (k%2 == 0)
				{
					k = k/2;
				}
				else if (k%2 == 1)
				{
					k = 3 * (k) + 1;
				}	
			
				printf("%d\n",k);
			}
		
			printf("k in child process = %d\n", k);
			printf("Child process (%d) is done.\n", pid);
		}
		else
		{
			printf("Parent process is waiting on child process...\n");
			wait(); // The Parent Process waits until the child process completes execution, that is returns a value (in this case, 0)
			printf("Parent process (%d) is done.\n", pid);
			printf("k in parent process = %d\n", k);
		}
	return 0; 
}
