/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:02 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 19:36:41 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* It prints the pointers representing
 * all the nodes of the singly linked
 * list, starting from the head node
 * that `head_ptr` points to, in the
 * form of a chain. The chain begins
 * with tabs number of '\t' symbols.
 * The `types` array contains the data
 * types of the nodes in the list,
 * beginning with the head node */
int	print_list(t_lst_d *list, int ntabs)
{
	t_list	*nptr;
	char	*arg;
	int		i;

	if (list->head == NULL)
		return (ERROR);
	arg = (char *)malloc((MAX_FORMAT_STR_LEN + 1) * sizeof (char));
	if (arg == NULL)
		return (ERROR);
	print_tabs(ntabs);
	process_arg(arg, list->head->content, list->types[0]);
	printf("[ %p | %s ] -> ", list->head, arg);
	nptr = list->head->next;
	i = 1;
	while (nptr != NULL)
	{
		process_arg(arg, nptr->content, list->types[i]);
		printf("[ %p | %s ] -> ", nptr, arg);
		nptr = nptr->next;
		i++;
	}
	printf("NULL\n");
	free(arg);
	return (SUCCESS);
}


/* It inserts the type at the beginning of the types array,
 * shifting all other elements to the right by one beforehand. 
 *     type_cnt - type counter. */
void	insert_type_at_begin(t_cnt_type *types, int type_cnt, t_cnt_type type)
{
	int	i;

	i = type_cnt;
	while (i > 0)
	{
		types[i] = types[i - 1];
		i--;
	}
	types[0] = type;
}

/* It deletes one element from the type_pos cell of the types array
 * and then shifts all elements to its right one position to the left.
 *     type_cnt - type counter. */
void	delete_type(t_cnt_type *types, int type_cnt, int type_pos)
{
	int	i;

	i = type_pos;
	while (i < type_cnt)
	{
		types[i] = types[i + 1];
		i++;
	}
}

/* It returns the size of the
 * list `lst`. This function
 * is the same as ft_lstsize(),
 * but it is used only for
 * internal purposes within
 * the tester, specifically
 * by the print_list() and
 * process_del_clear()
 * functions */
int	lstsize(t_list **lst)
{
	t_list	*nptr;
	int		size;

	if (*lst == NULL)
		return (0);
	size = 1;
	nptr = (*lst)->next;
	while (nptr != NULL)
	{
		nptr = nptr->next;
		size++;
	}
	return (size);
}

/* It prints n tabs consecutively */
void	print_tabs(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("\t");
		i++;
	}
}
