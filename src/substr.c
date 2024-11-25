/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:28 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/25 16:37:16 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, void **pack);

void	substr_test(void)
{
	t_char_c	our_funcname[] = "ft_substr";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

/*
 * It launches all the tests for ft_substr().
 * s - strings used during testing (the first argument of ft_substr());
 * t - the position from which to extract the substring (the second argument);
 * l - the length of the substring being extracted.
 * We were forced to determine all the values of the arguments for each test
 * using arrays because, in C, we can't get the address of an r-value.
 * For example, it is not possible to call a test this way:
 * test_helper(..., pack_args(3, (void *)"str", (void *)&(2), (void *)&(4));
 * I SHOULD TRY TO USE COMPOUND LITERALS HERE!!! */
static void	launch_tests(t_char_c *fname)
{
	t_char_c	s[][MAX_SUBSTR_STR_LEN] = { "just a string to test", "a", "" };
	u_int		t[] = { 2, 0, 0, 0, 14, 14, 0, 0, 0 };
	size_t		l[] = { 4, 13, 1, 0, 6, 7, 1, 5, 1 };

	test_helper(fname, 1, pack_args(3, (void *)s[0], (void *)&t[0], (void *)&l[0]));
	test_helper(fname, 2, pack_args(3, (void *)s[0], (void *)&t[1], (void *)&l[1]));
	test_helper(fname, 3, pack_args(3, (void *)s[0], (void *)&t[2], (void *)&l[2]));
	test_helper(fname, 4, pack_args(3, (void *)s[0], (void *)&t[3], (void *)&l[3]));
	test_helper(fname, 5, pack_args(3, (void *)s[0], (void *)&t[4], (void *)&l[4]));
	test_helper(fname, 6, pack_args(3, (void *)s[0], (void *)&t[5], (void *)&l[5]));
	test_helper(fname, 7, pack_args(3, (void *)s[1], (void *)&t[6], (void *)&l[6]));
	test_helper(fname, 8, pack_args(3, (void *)s[0], (void *)&t[7], (void *)&l[7]));
	test_helper(fname, 9, pack_args(3, (void *)s[2], (void *)&t[8], (void *)&l[8]));
}

static void	test_helper(t_char_c *fname, int ntest, void **pack)
{
	t_char_c	format[] = "(\"%s\", \"%u\", \"%lu\") = %p -> \"%s\"\n";
	char		*ret;
	char		*str;
	u_int		start;
	size_t		len;

	str = (char *)pack[0];
	start = *(u_int *)pack[1];
	len =  *(size_t *)pack[2];
	ret = ft_substr(str, start, len);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str, start, len, ret, ret);
	free(ret);
}
