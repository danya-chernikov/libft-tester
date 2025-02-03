/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstiter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:48 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/03 15:59:40 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int nt, t_list *head, void (*f)(void *));

void	lstiter_test(t_list *head, void (*test_func)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstiter", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, head, test_func);
	print_test_footer();
}

static void	test_helper(t_char_c *fn, int nt, t_list *head, void (*f)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	ft_lstiter(head, f);
	printf(format, head, f);
}
