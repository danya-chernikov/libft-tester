/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_del_processor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:16:31 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/05 17:24:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

static void	update_ptr(t_lst_d **list, t_list *node, t_list *next, void **pack);

static bool	update_ptr_if_node_is_first(t_lst_d **list,
				t_list *next, void **pack);

static bool	update_ptr_if_node_is_last(t_lst_d **list,
				t_list *node, void **pack);

static void	update_ptr_if_node_is_inmid(t_lst_d **list,
				t_list *next, t_list *node, void **pack);

/* It deletes a node specified by the `cmd->arg` variable. A node can be
 * specified as a number or as an address. Of course, if the user wants
 * to delete the first node of the list, the head pointer value in the
 * list structure must be updated. Furthermore, if the list contains only
 * one node and we are going to delete it, we should lower the `lcrt` flag
 * to indicate that the list has been removed */
int	process_cmd_del(t_lst_d **list, t_lst_test *tests, t_cmd *cmd, bool *lcrt)
{
	int		node_num;
	int		lsize;
	t_list	*node;
	t_list	*next;

	node = NULL;
	next = NULL;
	lsize = lstsize(&(*list)->head);
	node_num = atoi(cmd->arg);
	if ((node_num < 0) || (node_num > lsize - 1))
		return (ERROR);
	node = get_node(*list, node_num);
	if (node != NULL)
	{
		next = node->next;
		lstdelone_test(node, tests, del);
	}
	else
		return (ERROR);
	delete_type((*list)->types, (*list)->type_cnt, node_num);
	(*list)->type_cnt--;
	update_ptr(list, node, next,
		pack_args(3, (void *)&node_num, (void *)&lsize, (void *)lcrt));
	return (SUCCESS);
}

static void	update_ptr(t_lst_d **list, t_list *node, t_list *next, void **pack)
{
	if (update_ptr_if_node_is_first(list, next, pack))
		return ;
	if (update_ptr_if_node_is_last(list, node, pack))
		return ;
	update_ptr_if_node_is_inmid(list, node, next, pack);
}

/* If the user wants to delete the first (head) element
 * of the list, this function will update the `head`
 * pointer of the `list` structure. That is, the `head`
 * pointer will be set to the address of the next node
 * after the old `head` pointer. If the head element of
 * the list is the last one, the `lcrt` flag must be set
 * to false, indicating that the list has ceased to
 * exist. In addition, if the user wants to delete the
 * first element, the function returns true at the end;
 * otherwise, it returns false, instructing the caller
 * to proceed with the pointer update process via the
 * functions update_ptr_if_node_is_last() and
 * update_ptr_if_node_is_inmid() */
static bool	update_ptr_if_node_is_first(t_lst_d **list,
				t_list *next, void **pack)
{
	int		node_num;
	int		lsize;
	bool	*lcrt;

	node_num = *(int *)pack[0];
	lsize = *(int *)pack[1];
	lcrt = (bool *)pack[2];
	if (node_num == 0)
	{
		if (lsize == 1)
			*lcrt = false;
		else if (lsize > 1)
			(*list)->head = next;
		free(pack);
		return (true);
	}
	free(pack);
	return (false);
}

/* If the user wants to delete the last (tail) element
 * of the list, this function will set the `next` pointer
 * of the penultimate node of the list to NULL. In addition,
 * if the condition that the user specified the number of
 * the last element to delete is met, the function returns
 * true; otherwise, it returns false */
static bool	update_ptr_if_node_is_last(t_lst_d **list,
				t_list *node, void **pack)
{
	int		node_num;
	int		lsize;
	t_list	*ni;

	node_num = *(int *)pack[0];
	lsize = *(int *)pack[1];
	ni = (*list)->head;
	if (node_num == lsize - 1)
	{
		while (ni->next != node)
			ni = ni->next;
		ni->next = NULL;
		return (true);
	}
	return (false);
}

/* If the user wants to delete a middle element of the
 * list, this function will set the `next` pointer of
 * the preceding node to `node` to the address of the
 * node that comes after `node` */
static void	update_ptr_if_node_is_inmid(t_lst_d **list,
				t_list *node, t_list *next, void **pack)
{
	int		node_num;
	int		lsize;
	t_list	*ni;

	node_num = *(int *)pack[0];
	lsize = *(int *)pack[1];
	ni = (*list)->head;
	if ((node_num > 0) && (node_num < lsize - 1))
	{
		while (ni->next != node)
			ni = ni->next;
		ni->next = next;
	}
	free(pack);
}
