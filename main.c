#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char **argv)
{
	char *str = NULL;
	size_t n;
	char *stkn;
	pid_t mypid;
	char *arr[1024];

	while (1)
	{
		printf("$ ");
		getline(&str, &n, stdin);

		stkn = strtok(str, " \n");

		/*arr[1024] = {stkn, NULL};*/
		arr[0] = stkn;

		/*compares two strings, returns 0 if the strings are equal*/
		if (strcmp(stkn, "exit") == 0)
		exit(0);

		mypid = fork();
		if (mypid == -1)/*returns -1 if the fork system call is unsuccesful*/
		{
			perror("Error");
			return (1);
		}
		else if (mypid == 0)/*executed in the child process*/
		{
			if (execve(arr[0], arr, NULL) == -1 && arr[0] != NULL)

			{
				perror(argv[0]);
				return (1);
			}
		}
		else/*executed in the parent process*/
		{
			wait(NULL);

		}
	}
	free(str);
	return (0);
}
