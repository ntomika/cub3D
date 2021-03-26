#include <stdio.h>
#include "libft.h"
int	main(void)
{
	char	**c;
	
	c = ft_split("vgusehcj",' ');
	while (*c)
	{
		printf("%s\n", *c);
		c++;
	}
	while(1)
		;
	return (0);
}
