/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:07 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/24 16:14:41 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(const char *fname);
static void	test_helper(const char *fname, int ntest, char *strs, size_t len);

void	strnstr_test()
{
	const char	our_funcname[] = "ft_strnstr";
	const char	orig_funcname[] = "strnstr";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

/* It launches all the ft_strnstr() tests we have */
static void	launch_tests(const char *fname)
{
	char	big[] = "abc def ghi jkl";
	char	big2[] = "lorem ipsum dolor sit amet";

	printf("\taddress of big string is: %p\n", big);
	test_helper(fname, 1, pack_strs(big, "def"), strlen(big));
	test_helper(fname, 2, pack_strs(big, "jkl"), strlen(big));
	test_helper(fname, 3, pack_strs(big, "l"), strlen(big));
	test_helper(fname, 4, pack_strs(big, ""), strlen(big));
	test_helper(fname, 5, pack_strs(big, "ghi"), strlen(big));
	test_helper(fname, 6, pack_strs(big, " j"), 10);
	test_helper(fname, 7, pack_strs(big, " j"), 20);
	test_helper(fname, 8, pack_strs(big, "abc def ghi jkl"), strlen(big));
	test_helper(fname, 9, pack_strs(big, "abc def ghi jkl*"), strlen(big));
	test_helper(fname, 10, pack_strs(big, "abc def ghi jkl*"), 20);
	test_helper(fname, 11, pack_strs(big, "abc def ghi jkp"), strlen(big));
	test_helper(fname, 12, pack_strs(big2, "dolor"), 0);
	test_helper(fname, 13, pack_strs(big2, "dolor"), strlen(big2));
}

/* It's a common test case */
static void	test_helper(const char *fname, int ntest, char *strs, size_t len)
{
	t_char_c	format[] = "(\"%s\", \"%s\", %lu) = \"%p\"\n";
	char		big[MAX_STRNSTR_STR_LEN];
	char		little[MAX_STRNSTR_STR_LEN];
	char		*ret;
	
	unpack_strs(strs, big, little);
	if (strncmp(fname, "ft_strnstr", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_strnstr(big, little, len);
	else if (strncmp(fname, "strnstr", MAX_FUNC_NAME_LEN) == 0)
		ret = strnstr(big, little, len);
	else
		ret = ft_strnstr(big, little, len);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, big, little, len, ret);
}
