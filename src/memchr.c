/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:51:54 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/07 18:51:06 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, void **pack);
static void	launch_tests(t_char_c *fname);

void	memchr_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_memchr", MAX_FUNC_NAME_LEN);
	strncpy(orig_funcname, "memchr", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

/* It accepts a pack of arguments and then unpacks them to pass
 * these arguments to the tested function. The pack contains
 * three arguments:
 *     str - a pointer to the memory area in which to search;
 *     c   - the symbol to search for in the string str;
 *     n   - the number of bytes to search. */
static void	test_helper(t_char_c *fname, int ntest, void **pack)
{
	void	*ret;
	char	*str;
	int		c;
	size_t	n;

	str = (char *)pack[0];
	c = *(int *)pack[1];
	n = *(size_t *)pack[2];
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf("(%p, '%c', %lu) = ", str, c, n);
	if (strncmp(fname, "ft_memchr", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_memchr(str, c, n);
	else if (strncmp(fname, "memchr", MAX_FUNC_NAME_LEN) == 0)
		ret = memchr(str, c, n);
	else
		ret = ft_memchr(str, c, n);
	printf("%p\n", ret);
	free(pack);
}

static void	launch_tests(t_char_c *fn)
{
	char	s[MAX_MEMCHR_STR_LEN + 1];
	size_t	slen;
	char	c[3];
	int		n[2];

	c[0] = ';';
	c[1] = ' ';
	c[2] = 'Y';
	c[0] = 0;
	c[1] = 1;
	strncpy(s, "Peter, I have been sent as punishment;", MAX_MEMCHR_STR_LEN);
	strncat(s, " I turn to the pages of his crown:", MAX_MEMCHR_STR_LEN);
	slen = strlen(s);
	printf("\ts = \"%s\"\n", s);
	printf("\t&s[0] = %p\n", &s[0]);
	test_helper(fn, 1, pack_args(3, (void *)s, (void *)&c[0], (void *)&slen));
	test_helper(fn, 2, pack_args(3, (void *)s, (void *)&c[1], (void *)&slen));
	test_helper(fn, 3, pack_args(3, (void *)s, (void *)&c[0], (void *)&n[1]));
	test_helper(fn, 4, pack_args(3, (void *)s, (void *)&c[0], (void *)&n[0]));
	test_helper(fn, 5, pack_args(3, (void *)s, (void *)&c[2], (void *)&slen));
}
