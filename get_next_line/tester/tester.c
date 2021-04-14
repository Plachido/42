#include "../get_next_line.h"
#include "../get_next_line.c"
#include "../get_next_line_utils.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "correct_gnl/test.h"
#include "correct_gnl/test.c"
#include <string.h>

int main(int argc, char *argv[])
{
	char **str;
	char **str2;
	int fd;
	int fd2;
	int res;
	int res2;
	int n;
	int i = 1;

	if (argc > 1)
	{
	
		fd = open (argv[1], O_RDONLY); 
		fd2 = open(argv[1], O_RDONLY);
		if (argv[2])
			n = atoi(argv[2]);
		else
			n = 200;

		printf("TEST...");
		while(i < n)
		{
			str = malloc(1*sizeof(char*) + 1);
			str2 = malloc(1*sizeof(char*) + 1);
			res = get_next_line(fd, str);
			res2 = get_next_line_test(fd2, str2);
	//		printf("MIO:	%s\n", *str);
	//		printf("GIUSTO: %s\n\n", *str2);
			if(res != res2 || strcmp(*str, *str2) != 0)
			{
				printf("KO AT LINE %d:\n", i);
				printf("EXPECTED: %s	%d\n", *str2, res2);
				printf("ACTUAL:	  %s	%d\n", *str, res);
				break;
			}
			i++;
			free(str);
			free(str2);
		}
		close(fd);
		close(fd2);
		if (i == n)
			printf("OK\n");
	}
}
