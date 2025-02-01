/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstlast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:22:50 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:22:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int nt, t_list *head, t_cnt_type type);

/* This function needs to accept
 * the content type type of the
 * last element in the list list
 * to interpret its content */
void	lstlast_test(t_lst_d *list)
{
	char		fname[MAX_FUNC_NAME_LEN];
	t_cnt_type	type;

	strncpy(fname, "ft_lstlast", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	type = list->types[list->type_cnt - 1];
	test_helper(fname, 1, list->head, type);
	print_test_footer();
}

static void	test_helper(t_char_c *fn, int nt, t_list *head, t_cnt_type type)
{
	char	format[MAX_FORMAT_STR_LEN];
	char	cnt_str[MAX_CNT_STR_LEN];
	t_list	*last;

	strncpy(format, "(%p) = [ %p | %s ]\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	last = ft_lstlast(head);
	process_arg(cnt_str, last->content, type);
	printf(format, head, last, cnt_str);
}
