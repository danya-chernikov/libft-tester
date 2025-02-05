/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:51 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/05 15:48:00 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

t_list	*lstmap_test(t_list *node,
			void *(*test_func)(void *), void (*del_func)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];
	char	format[MAX_FORMAT_STR_LEN];
	t_list	*new_list_head;
	int		ntest;

	ntest = 1;
	strncpy(fname, "ft_lstmap", MAX_FUNC_NAME_LEN);
	strncpy(format, "(%p, %p, %p)\n", MAX_FORMAT_STR_LEN);
	print_test_header(fname);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	new_list_head = ft_lstmap(node, test_func, del_func);
	if (new_list_head == NULL)
		return (NULL);
	printf(format, node, test_func, del_func);
	print_test_footer();
	return (new_list_head);
}
