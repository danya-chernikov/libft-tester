#include "../include/list.h"

/* This function is used to test how
 * the ft_lstdelone() and ft_lstclear()
 * functions  works */
void	del(void *node_cnt)
{
	if (node_cnt != NULL)
		free(node_cnt);
	node_cnt = NULL;
}

/* This function is used to test how
 * the ft_lstiter() function works */
void	iter_func1(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = toupper(((char *)node_cnt)[i]);
		i++;
	}
}

/* This function is used to test how
 * the ft_lstiter() function works */
void	iter_func2(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = tolower(((char *)node_cnt)[i]);
		i++;
	}
}
