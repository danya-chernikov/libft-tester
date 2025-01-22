#include "../include/list.h"

/* It traverses the list starting from the node node to the end,
 * storing pointers to each node and the content of each node it
 * passes. This ensures that when the time comes to free the
 * content of each node, the content won't be freed twice. This
 * approach helps avoid a double-free error. */
void	detect_nodes_to_free(t_lst_d *list, t_list **node, t_lst_test *tests)
{
	t_list	*ni;
	int		i;

	i = 0;
	ni = *node;
	while (ni != NULL)
	{
		list->type_cnt--;
		tests->nodes_to_free[i] = (void *)ni;
		tests->cnts_to_free[i] = (void *)ni->content;
		ni = ni->next;
		i++;
	}
	tests->nodes_num_to_free = i;
}

/* It nullifies the `next` pointer of the node preceding
 * the node from which we start clearing the list. If we
 * are clearing the list starting from its head, this
 * function simply nullifies the pointer to the head of
 * the list in the `t_lst_d` structure that represents
 * our list. */
void	nullify_node_ptr(t_lst_d *list, t_list **node)
{
	t_list	*ni;
	
	ni = list->head;
	if (ni == *node)
	{
		list->head = NULL;
		return ;
	}
	while (ni->next != *node)
	{
		ni = ni->next;
		if (ni == NULL)
			break ;
		if (ni->next == *node)
		{
			ni->next = NULL;
			break ;
		}
	}
}
