/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:29:58 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/11 19:11:14 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/memcmp.h"

void	memcmp_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_memcmp", MAX_FUNC_NAME_LEN);
	strncpy(orig_funcname, "memcmp", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	memcmp_regular_tests(our_funcname);
	memcmp_special_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	memcmp_regular_tests(orig_funcname);
	memcmp_special_tests(orig_funcname);
	print_test_footer();
}

void	memcmp_test_helper(t_char_c *fn, t_void_c *s1, t_void_c *s2, size_t n)
{
	char	f[MAX_FORMAT_STR_LEN];
	char	bytes_s1[READ_MEM_LIMIT + 1];
	char	bytes_s2[READ_MEM_LIMIT + 1];
	int		ret;

	strncpy(f, "(\"%s\"|\"%s\",\n\"%s\"|\"%s\", %lu) = ", MAX_FORMAT_STR_LEN);
	strncpy(bytes_s1, read_mem((void *)s1, n, "\\x", 8), READ_MEM_LIMIT);
	strncpy(bytes_s2, read_mem((void *)s2, n, "\\x", 8), READ_MEM_LIMIT);
	cprintf(YELLOW, "%s", fn);
	printf(f, bytes_s1, (char *)s1, bytes_s2, (char *)s2, n);
	if (strncmp(fn, "ft_memcmp", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_memcmp(s1, s2, n);
	else if (strncmp(fn, "memcmp", MAX_FUNC_NAME_LEN) == 0)
		ret = memcmp(s1, s2, n);
	else
		ret = ft_memcmp(s1, s2, n);
	printf("%d\n", ret);
}
