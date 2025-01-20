#include "../include/list.h"

void	addfront_quick(t_lst_d *list, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	list->types[list->type_cnt] = type;
	lst = lstnew_test(cnt, type);
	lstadd_front_test(&list->head, lst);
	list->head = lst;
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
}

void	addback_quick(t_lst_d *list, void *cnt, t_cnt_type type)
{
	t_list	*lst;

	addfront_test_type(list->types, list->type_cnt, type);
	lst = lstnew_test(cnt, type);
	lstadd_back_test(&list->head, lst);
	list->type_cnt++;
	print_list(list, 0);
	lstsize_test(&list->head);
}

/* It traverses the `list` and returns a pointer
 * to the node at the `node_num`-th position in
 * the `list`. The count goes from zero */
t_list	*get_node(t_lst_d *list, int node_num)
{
	t_list	*node;
	int		i;

	i = 0;
	node = list->head;
	while (i < node_num && node->next != NULL)
	{
		node = node->next;
		i++;
	}
	return (node);
}

bool	cnt_was_freed(void *cnt, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = 0;
	while (i < tests->cnts_num_to_free)
	{
		if (cnt == tests->cnts_to_free[i])
		{
			was_freed = 1;
			break;
		}
		i++;
	}
	return (was_freed);
}

bool	node_was_freed(void *node, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = 0;
	while (i < tests->nodes_num_to_free)
	{
		if (node == tests->nodes_to_free[i])
		{
			was_freed = 1;
			break;
		}
		i++;
	}
	return (was_freed);
}
