/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:46:41 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *s1, t_char_c *s2);

void	strjoin_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_strjoin", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, "just a string", " and another string");
	test_helper(fname, 2, "y", "b");
	test_helper(fname, 3, "", "");
	test_helper(fname, 4, "lololo", "");
	test_helper(fname, 5, "", "kekeke");
}

static void	test_helper(t_char_c *fname, int ntest, t_char_c *s1, t_char_c *s2)
{
	char	format[MAX_FORMAT_STR_LEN];
	char	*ret;

	strncpy(format, "(\"%s\", \"%s\") = \"%s\"\n", MAX_FORMAT_STR_LEN);
	ret = ft_strjoin(s1, s2);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, s1, s2, ret);
	free(ret);
}
