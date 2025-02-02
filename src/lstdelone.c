/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:47 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/02 00:28:24 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int nt, t_list *n, void (*del)(void *));
static void detect_nodes_to_free(t_list *node, t_lst_test *tests);

void	lstdelone_test(t_list *n, t_lst_test *t, void (*f)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstdelone", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
    detect_nodes_to_free(n, t);
	test_helper(fname, 1, n, f);
	print_test_footer();
}

static void	test_helper(t_char_c *fn, int nt, t_list *n, void (*f)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	ft_lstdelone(n, f);
	printf(format, n, f);
}

static void detect_nodes_to_free(t_list *node, t_lst_test *tests)
{
    int last_ind;

	last_ind = tests->nodes_num_to_free;
	tests->nodes_to_free[last_ind] = (void *)node;
	tests->cnts_to_free[last_ind] = (void *)node->content;
	tests->nodes_num_to_free = last_ind + 1;
}
