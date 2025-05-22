#include "../include/list.h"

/* This function is used to
 * test how the ft_lstdelone()
 * and ft_lstclear() functions
 * works */
void	del(void *node_cnt)
{
	if (node_cnt != NULL)
		free(node_cnt);
	node_cnt = NULL;
}

/* It serves for Exam02 preparation
 * exercise ft_list_remove_if.c */
int		cmp(void *data1, void *data2)
{
	if (*((int *)data1) != *((int *)data2))
		return (1);
	return (0);
}
