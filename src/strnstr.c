/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strnstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:07 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 19:24:32 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, char *strs, size_t len);

void	strnstr_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strlcpy(our_funcname, "ft_strnstr", MAX_FUNC_NAME_LEN);
	strlcpy(orig_funcname, "strnstr", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

/* It launches all the ft_strnstr() tests we have */
static void	launch_tests(t_char_c *fname)
{
	char	big[32];
	char	big2[64];

	strlcpy(big, "abc def ghi jkl", 32);
	strlcpy(big2, "lorem ipsum dolor sit amet", 64);
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
static void	test_helper(t_char_c *fname, int ntest, char *strs, size_t len)
{
	char	f[MAX_FORMAT_STR_LEN];
	char	big[MAX_STRNSTR_STR_LEN];
	char	little[MAX_STRNSTR_STR_LEN];
	char	*ret;

	strlcpy(format, "(\"%s\", \"%s\", %lu) = %p\n", MAX_FORMAT_STR_LEN);
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
