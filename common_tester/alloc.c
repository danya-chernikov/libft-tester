#include "common_tester.h"

char	**alloc_str_2d(int strsnum, int strlen)
{
	char	**ptr;
	int		i;

	ptr = (char **)calloc(strsnum, sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < strsnum)
	{
		ptr[i] = (char *)calloc(strlen + 1, sizeof(char));
		if (ptr[i] == NULL)
			return (NULL);
		i++;
	}
	return (ptr);
}

void	free_str_2d(char **ptr, int strsnum)
{
	int	i;

	i = 0;
	while (i < strsnum)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}
