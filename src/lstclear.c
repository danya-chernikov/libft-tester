/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstclear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:45 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/02 19:35:28 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int nt, t_list **n, void (*del)(void *));
static void	nullify_node_ptr(t_lst_d *list, t_list **node);
static void	detect_nodes_to_free(t_lst_d *l, t_list **node, t_lst_test *tests);

/* l - Pointer to the structure that represents the list;
 * n - Double pointer to the node from which we start clearing the list;
 * f - Function that deletes the content of each node in the list;
 * t - Pointer to the structure that stores pointers to the content
 *     of each node. */
void	lstclear_test(t_lst_d *l, t_list **n, t_lst_test *t, void (*f)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstclear", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	nullify_node_ptr(l, n);
	detect_nodes_to_free(l, n, t);
	test_helper(fname, 1, n, f);
	print_test_footer();
}

/* It sets NULL in the cells of types that contain pointers to the contents of
 * nodes traversed from *node to the tail of the list*/
static void	test_helper(t_char_c *fn, int nt, t_list **n, void (*del)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	ft_lstclear(n, del);
	printf(format, n, del);
}

/* It nullifies the `next` pointer of the node preceding
 * the node from which we start clearing the list. If we
 * are clearing the list starting from its head, this
 * function simply nullifies the pointer to the head of
 * the list in the `t_lst_d` structure that represents
 * our list */
static void	nullify_node_ptr(t_lst_d *list, t_list **node)
{
	t_list	*ni;

	ni = list->head;
	if (ni == *node)
	{
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

/* It traverses the list starting from the node `*node` to the end, storing
 * pointers to each node and the content of each node it passes. This ensures
 * that when the time comes to free the content of each node, the content won't
 * be freed twice. This approach helps avoid a double-free error. Also, this
 * function decrements the `type_cnt` variable of the `t_lst_d` structure when;
 * the next node is passed */
static void	detect_nodes_to_free(t_lst_d *l, t_list **node, t_lst_test *tests)
{
	t_list	*ni;
	int		i;
	int		last_ind;

	i = 0;
	ni = *node;
	last_ind = tests->nodes_num_to_free;
	while (ni != NULL)
	{
		l->type_cnt--;
		tests->nodes_to_free[last_ind + i] = (void *)ni;
		tests->cnts_to_free[last_ind + i] = (void *)ni->content;
		ni = ni->next;
		i++;
	}
	tests->nodes_num_to_free = last_ind + i;
}
