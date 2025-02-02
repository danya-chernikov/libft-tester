/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:06 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/02 00:11:25 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* list->type_cnt - type counter */
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
