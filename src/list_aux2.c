#include "../include/list.h"

void	addfront_quick(t_lst_d *list, void *cnt, t_cnt_type type, bool debug)
{
	t_list	*lst;

	insert_type_at_begin(list->types, list->type_cnt, type);
	lst = lstnew_test(cnt, type);
	lstadd_front_test(&list->head, lst);
	list->head = lst;
	list->type_cnt++;
	if (debug)
	{
		print_list(list, 0);
		lstsize_test(&list->head);
	}
}

void	addback_quick(t_lst_d *list, void *cnt, t_cnt_type type, bool debug)
{
	t_list	*lst;
	list->types[list->type_cnt] = type;
	lst = lstnew_test(cnt, type);
	lstadd_back_test(&list->head, lst);
	list->type_cnt++;
	if (debug)
	{
		print_list(list, 0);
		lstsize_test(&list->head);
	}
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
		// ni->next = NULL; ?
		list->head = NULL;
		return ;
	}
	if (ni->next == *node)
		ni->next = NULL;
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

/* It traverses the list starting from the node `*node` to the end,
 * storing pointers to each node and the content of each node it
 * passes. This ensures that when the time comes to free the
 * content of each node, the content won't be freed twice. This
 * approach helps avoid a double-free error. Also, this function
 * decrements the `type_cnt` variable of the `t_lst_d` structure
 * when the next node is passed */
void	detect_nodes_to_free(t_lst_d *list, t_list **node, t_lst_test *tests)
{
	t_list	*ni;
	int		i;
	int		last_ind;

	i = 0;
	ni = *node;
	last_ind = tests->nodes_num_to_free;
	while (ni != NULL)
	{
		list->type_cnt--;
		tests->nodes_to_free[last_ind + i] = (void *)ni;
		tests->cnts_to_free[last_ind + i] = (void *)ni->content;
		ni = ni->next;
		i++;
	}
	tests->nodes_num_to_free = last_ind + i;
}

/* It traverses the `list` and returns a pointer
 * to the node at the `node_num`-th position in
 * the `list`. The node count goes from zero.
 * If a caller wants to get the element that
 * does not exist the function returns NULL */
t_list	*get_node(t_lst_d *list, int node_ind)
{
	t_list	*node;
	int		i;

	if (node_ind < 0)
		return (NULL);
	i = 0;
	node = list->head;
	while (i < node_ind)
	{
		node = node->next;
		if (node == NULL)
			return (NULL);
		i++;
	}
	return (node);
}
