/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:19 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *s, t_char_c *set);

void	strtrim_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_strtrim", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, "ERFFHIt's G just F aH stringGRDF", "ERFHGD");
	test_helper(fname, 2, "EFDDGHRgFFDFERGGGGD", "ERFHGD");
	test_helper(fname, 3, "ergrrrerqeeferere", "er");
	test_helper(fname, 4, "rrfvnws34ftyutuk", "tyu");
	test_helper(fname, 5, "rtyutuuuutttyyyytyutur", "tyu");
	test_helper(fname, 6, "rtyutuuuutttyyyytyutu", "tyu");
	test_helper(fname, 7, "tyutuuuutttyyyytyutur", "tyu");
	test_helper(fname, 8, "tyutuuuutttyyyytyutu", "tyu");
	test_helper(fname, 9, "tyutuuuutttyyyytyutu", "t");
	test_helper(fname, 10, "tyutuuuutttyyyytyutu", "");
	test_helper(fname, 11, "tyutuuuutttyyyytyutu", "sssssss");
	test_helper(fname, 12, "r", "kwhefuh");
	test_helper(fname, 13, "hello", "hello");
	test_helper(fname, 14, "mmmmmmm", "mmmmmmm");
	test_helper(fname, 15, "r", "r");
	test_helper(fname, 16, "", "rwefh");
	test_helper(fname, 17, "", "");
}

static void	test_helper(t_char_c *fname, int ntest, t_char_c *s, t_char_c *set)
{
	char	format[MAX_FORMAT_STR_LEN];
	char	*ret;	

	strncpy(format, "(\"%s\", \"%s\") = \"%s\"\n", MAX_FORMAT_STR_LEN);
	ret = ft_strtrim(s, set);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, s, set, ret);
	free(ret);
}
