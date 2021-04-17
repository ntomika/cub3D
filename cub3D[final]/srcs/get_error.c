#include "header.h"

void	get_error(char *message)
{
	printf("\033[31m");
	printf("ERROR\n%s.\n", message);
	printf("\033[0m");
}
