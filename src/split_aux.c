#include "../include/split.h"
#include <stddef.h>
#include <stdlib.h>

void	split_free(char ***res)
{
	size_t	i;
	
	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}