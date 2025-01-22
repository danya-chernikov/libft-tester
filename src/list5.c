#include "../include/list.h"

/* It traverses the list starting from the node node to the end,
 * storing pointers to each node and the content of each node it
 * passes. This ensures that when the time comes to free the
 * content of each node, the content won't be freed twice. This
 * approach helps avoid a double-free error. */
void	detect_nodes_to_free(t_list **node, t_lst_test *tests)
{
	t_list	*ni;
	int		i;

	i = 0;
	ni = *node;
	while (ni != NULL)
	{
		tests->nodes_to_free[i] = (void *)ni;
		tests->cnts_to_free[i] = (void *)ni->content;
		ni = ni->next;
		i++;
	}
	tests->nodes_num_to_free = i;
}
