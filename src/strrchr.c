/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:12 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:55:34 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *funcname);
static void	test_helper(t_char_c *funcname, int ntest, t_char_c *str, int ch);

/* Main function that tests
 * ft_strrchr(), launching
 * both tests of our own
 * implementation and the
 * same tests of the original
 * strrchr() from Glibc, to be
 * able to compare their results */
void	strrchr_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_strrchr", MAX_FUNC_NAME_LEN);
	strncpy(orig_funcname, "strrchr", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	test_helper(t_char_c *funcname, int ntest, t_char_c *str, int ch)
{
	char	format[MAX_FORMAT_STR_LEN];
	char	*res;

	strncpy(format, "\t%d. %s%s%s(\"%s\", '%c') = ", MAX_FORMAT_STR_LEN);
	printf(format, ntest, YELLOW, funcname, WHITE, str, ch);
	if (strncmp(funcname, "ft_strrchr", MAX_FUNC_NAME_LEN) == 0)
		res = ft_strrchr(str, ch);
	else if (strncmp(funcname, "strrchr", MAX_FUNC_NAME_LEN) == 0)
		res = strrchr(str, ch);
	else
		res = ft_strchr(str, ch);
	printf("%p\n", res);
}

static void	launch_tests(t_char_c *funcname)
{
	char	str[32];
	char	str2[8];

	strncpy(str, "just a test string", 32);
	strncpy(str, "teste", 8);
	printf("\tstr = \"%s\"\n", str);
	printf("\tAddress of str is: %p\n", str);
	test_helper(funcname, 1, str, 'j');
	test_helper(funcname, 2, str, ' ');
	test_helper(funcname, 3, str, 'a');
	test_helper(funcname, 4, str, 'g');
	test_helper(funcname, 5, str, '\0');
	test_helper(funcname, 6, str, 'i');
	test_helper(funcname, 7, str2, 'e');
	test_helper(funcname, 8, str2, '\0');
}
