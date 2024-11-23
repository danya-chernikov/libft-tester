/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:02 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/23 19:17:32 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, t_char_c *s1, t_char_c *s2, size_t n);
static void	regular_test(t_char_c *fname, int ntest, char *strs, size_t n);
static void	launch_tests(t_char_c *fname);

void	strncmp_test(void)
{	
	t_char_c	our_funcname[] = "ft_strncmp";
	t_char_c	orig_funcname[] = "strncmp";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, t_char_c *s1, t_char_c *s2, size_t n)
{
	int	ret;

	cprintf(YELLOW, "%s", fname);
	printf("(\"%s\", \"%s\", %lu) = ", s1, s2, n);
	if (strncmp(fname, "ft_strncmp", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_strncmp(s1, s2, n);
	else if (strncmp(fname, "strncmp", MAX_FUNC_NAME_LEN) == 0)
		ret = strncmp(s1, s2, n);
	else
		ret = ft_strncmp(s1, s2, n);
	printf("%d\n", ret);
}

static void	regular_test(t_char_c *fname, int ntest, char *strs, size_t n)
{
	char	s1[MAX_STRNCMP_STR_LEN];
	char	s2[MAX_STRNCMP_STR_LEN];

	printf("\t%d. ", ntest);
	unpack_strs(strs, s1, s2);
	test_helper(fname, s1, s2, n);
}

static void	launch_tests(t_char_c *fname)
{
	regular_test(fname, 1, pack_strs("string1", "string2"), 7);
	regular_test(fname, 2, pack_strs("string2", "string1"), 7);
	regular_test(fname, 3, pack_strs("string", "string"), 7);
	regular_test(fname, 4, pack_strs("stringz", "stringa"), 7);
	regular_test(fname, 5, pack_strs("stringa", "stringz"), 7);
	regular_test(fname, 6, pack_strs("stringr", "string"), 7);
	regular_test(fname, 7, pack_strs("string", "stringr"), 7);
	regular_test(fname, 8, pack_strs("string", "stringqe"), 7);
	regular_test(fname, 9, pack_strs("string", "stringqe"), 6);
	regular_test(fname, 10, pack_strs("stringqe", "string"), 7);
	regular_test(fname, 11, pack_strs("stringqe", "string"), 1);
	regular_test(fname, 12, pack_strs("string5", "string"), 20);
	regular_test(fname, 13, pack_strs("~", "string"), 7);
	regular_test(fname, 14, pack_strs("~", "string"), 0);
	regular_test(fname, 15, pack_strs("~", "string"), 1);
	regular_test(fname, 16, pack_strs("strtn", "string"), 5);
	regular_test(fname, 17, pack_strs("", ""), 5);
	regular_test(fname, 18, pack_strs("", ""), 0);
	regular_test(fname, 19, pack_strs("ß¶©", "ß¶©"), strlen("ß¶©"));
	regular_test(fname, 20, pack_strs("ß¶®", "ß¶©"), strlen("ß¶®"));
	regular_test(fname, 21, pack_strs("ß¶©", "ß¶®"), strlen("ß¶©"));
	regular_test(fname, 22, pack_strs("ß¶©Ø", "ß¶®"), strlen("ß¶©Ø"));
	regular_test(fname, 23, pack_strs("ß¶©", "ß¶®Ø"), strlen("ß¶©Ø"));
}
