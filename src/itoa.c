/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:43:52 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:36:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, int num);

void	itoa_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_itoa", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, 1924);
	test_helper(fname, 2, 0);
	test_helper(fname, 3, 1);
	test_helper(fname, 4, 66);
	test_helper(fname, 5, -1);
	test_helper(fname, 6, -47221);
	test_helper(fname, 7, 999000000);
	test_helper(fname, 8, 2147483647);
	test_helper(fname, 9, -2147483648);
}

static void	test_helper(t_char_c *fname, int ntest, int num)
{
	char	format[MAX_FORMAT_STR_LEN + 1];
	char	*ret;

	strncpy(format, "(%d) = \"%s\"\n", MAX_FORMAT_STR_LEN);
	ret = ft_itoa(num);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, num, ret);
	free(ret);
}
