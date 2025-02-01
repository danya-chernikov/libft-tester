/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstdelone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:47 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:22:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list *node, void (*del)(void *));

void	lstdelone_test(t_list *node, void (*del)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstdelone", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, node, del);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, t_list *node, void (*del)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	ft_lstdelone(node, del);
	printf(format, node, del);
}
