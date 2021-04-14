#include "../get_next_line.h"
#include "../get_next_line.c"
#include "../get_next_line_utils.c"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include "correct_gnl/test.h"
#include "correct_gnl/test.c"

int main(int argc, char *argv[])
{
	char **str;
	int n = 111;
	int fd = open (argv[1], O_RDONLY); 
	int i = 1;
	int res;
	
	if (argc > 1)
	{
		if (argv[2])
			n = atoi(argv[2]);
		printf("------------EXPECTED:------------\n");
		while(i < n)
		{
			str = malloc(1*sizeof(char*));
			res = get_next_line_test(fd, str);
			printf("LINE: %d -- STRING: %s	VAL: %d\n", i,*str, res);
			i++;
			free(str);
		}
		close(fd);
		i = 1;
		fd = open(argv[1], O_RDONLY);
		printf("------------ACTUAL:-------------\n");
		while(i < n)
		{
			str = malloc(1*sizeof(char*));
			res = get_next_line(fd, str);
			printf("LINE: %d -- STRING: %s	VAL: %d\n", i, *str, res);
			i++;
			free(str);
		}
		close(fd);
	}
}
