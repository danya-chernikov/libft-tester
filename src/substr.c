/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   substr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:57:28 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:56:08 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	form_second_args_arr(u_int *t);
static void	form_third_args_arr(size_t *l);
static void	launch_tests(t_char_c *fname);
static void	test_help(t_char_c *fname, int ntest, void **pack);

void	substr_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_substr", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

/*
 * It launches all the tests for ft_substr().
 *     s - strings used during testing (the
 *         first argument of ft_substr());
 *     t - the position from which to extract
 *         the substring (the second argument);
 *     l - the length of the substring being
 *         extracted.
 * We were forced to determine all the values
 * of the arguments for each test using arrays
 * because, in C, we can't get the address of
 * an r-value. For example, it is not possible
 * to call a test this way:
 * test_helper(..., pack_args(3, (void *)"str", (void *)&(2), (void *)&(4)); */
static void	launch_tests(t_char_c *fn)
{
	char	s[3][MAX_SUBSTR_STR_LEN];
	u_int	t[16];
	size_t	l[16];

	strncpy(s[0], "just a string to test", MAX_SUBSTR_STR_LEN);
	strncpy(s[1], "a", MAX_SUBSTR_STR_LEN);
	s[2][0] = '\0';
	form_second_args_arr(t);
	form_third_args_arr(l);
	test_help(fn, 1, pack_args(3, (void *)s[0], (void *)&t[0], (void *)&l[0]));
	test_help(fn, 2, pack_args(3, (void *)s[0], (void *)&t[1], (void *)&l[1]));
	test_help(fn, 3, pack_args(3, (void *)s[0], (void *)&t[2], (void *)&l[2]));
	test_help(fn, 4, pack_args(3, (void *)s[0], (void *)&t[3], (void *)&l[3]));
	test_help(fn, 5, pack_args(3, (void *)s[0], (void *)&t[4], (void *)&l[4]));
	test_help(fn, 6, pack_args(3, (void *)s[0], (void *)&t[5], (void *)&l[5]));
	test_help(fn, 7, pack_args(3, (void *)s[1], (void *)&t[6], (void *)&l[6]));
	test_help(fn, 8, pack_args(3, (void *)s[0], (void *)&t[7], (void *)&l[7]));
	test_help(fn, 9, pack_args(3, (void *)s[2], (void *)&t[8], (void *)&l[8]));
}

static void	test_help(t_char_c *fname, int ntest, void **pack)
{
	char	f[MAX_FORMAT_STR_LEN];
	char	*ret;
	char	*str;
	size_t	len;
	u_int	start;

	strncpy(f, "(\"%s\", \"%u\", \"%lu\") = %p -> \"%s\"", MAX_FORMAT_STR_LEN);
	str = (char *)pack[0];
	start = *(u_int *)pack[1];
	len = *(size_t *)pack[2];
	ret = ft_substr(str, start, len);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(f, str, start, len, ret, ret);
	printf("\n");
	free(ret);
}

static void	form_second_args_arr(u_int *t)
{
	t[0] = 2U;
	t[1] = 0U;
	t[2] = 0U;
	t[3] = 0U;
	t[4] = 14U;
	t[5] = 14U;
	t[6] = 0U;
	t[7] = 0U;
	t[8] = 0U;
}

static void	form_third_args_arr(size_t *l)
{
	l[0] = 4UL;
	l[1] = 13UL;
	l[2] = 1UL;
	l[3] = 0UL;
	l[4] = 6UL;
	l[5] = 7UL;
	l[6] = 1UL;
	l[7] = 5UL;
	l[8] = 1UL;
}
