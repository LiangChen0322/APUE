//#include "apue.h"
#include <stdio.h>      /* for convenience */
#include <stdlib.h>     /* for convenience */
#include <unistd.h>     /* for convenience */

#define MAXLINE 4096            /* max line length */

int main(void)
{
	int 	n;
	int		fd[2];
	pid_t	pid;
	char	line[MAXLINE];

	if (pipe(fd)<0) {
		//err_sys("pipe error");
		printf("pipe error");
	}
	if ((pid = fork()) < 0) {
		//err_sys("fork error");
		printf("fork error");
	} else if (pid > 0) {	/* parent */
		close(fd[0]);
		write(fd[1], "hello world\n", 12);
	} else {
		close(fd[1]);
		n = read(fd[0], line, MAXLINE);
		write(STDOUT_FILENO, line, n);
	}

	exit(0);
}