/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:12 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/20 17:12:07 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *funcname);
static void	test_helper(t_char_c *funcname, int ntest, t_char_c *str, int ch);

/* Main function that tests ft_strrchr(), launching both tests of our own
 * implementation and the same tests of the original strrchr() from Glibc,
 * to be able to compare their results */
void	strchr_test()
{
	t_char_c	our_funcname[] = "ft_strrchr";
	t_char_c	orig_funcname[] = "strrchr";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	test_helper(t_char_c *funcname, int ntest, t_char_c *str, int ch)
{
	t_char_c	format[] = "\t%d. %s%s%s(\"%s\", '%c') = ";
	char		*res;

	printf(format, ntest, YELLOW, funcname, WHITE, str, ch);
	if (strncmp(funcname, "ft_strrchr", MAX_FUNC_NAME_LEN) == 0)
		res = ft_strrchr(str, ch);
	else if (strncmp(funcname, "strrchr", MAX_FUNC_NAME_LEN) == 0)
		res = strrchr(str, ch);
	else
		res = ft_strchr(str, ch);
	printf("%p\n", res);
}

static void	launch_tests(char const *funcname)
{
	char	str[32] = "just a test string";
	char	str2[8] = "teste";

	printf("str = \"%s\"\n", str);
	printf("Address of str is: %p\n", str);
	test_helper(funcname, 1, str, 'j');
	test_helper(funcname, 2, str, ' ');
	test_helper(funcname, 3, str, 'a');
	test_helper(funcname, 4, str, 'g');
	test_helper(funcname, 5, str, '\0');
	test_helper(funcname, 6, str, 'i');
	test_helper(funcname, 7, str2, 'e');
	test_helper(funcname, 8, str2, '\0');
}
