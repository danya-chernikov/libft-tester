/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstadd_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:44 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:22:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **head, t_list *new);

void	lstadd_front_test(t_list **head, t_list *new)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_addfront", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, head, new);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, t_list **head, t_list *new)
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	ft_lstadd_front(head, new);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, *head, new);
}
