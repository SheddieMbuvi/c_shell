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

		mypid = fork();
		if (mypid == -1)
		{
			perror("Error");
			return (1);
		}
		else if (mypid == 0)/*solves the issue of exiting*/
		{
			if (execve(arr[0], arr, NULL) == -1 && arr[0] != NULL)

			{
				perror(argv[0]);
				return (1);
			}
		}
		else
		{
			wait(NULL);
	
		}
	}	
	free(str);
	return (0);
}
