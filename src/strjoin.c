/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:03 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/25 16:18:08 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *s1, t_char_c *s2);

void	strjoin_test(void)
{
	t_char_c	our_funcname[] = "ft_strjoin";

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
	t_char_c	format[] = "(\"%s\", \"%s\") = \"%s\"\n";
    char		*ret;

	ret = ft_strjoin(s1, s2);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, s1, s2, ret);
	free(ret);
}
