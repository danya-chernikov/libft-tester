/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:52:06 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/24 15:00:07 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/memcmp.h"

void	memcmp_test()
{
	t_char_c	our_funcname[] = "ft_memcmp";
	t_char_c	orig_funcname[] = "memcmp";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	memcmp_regular_tests(our_funcname);
	memcmp_special_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	memcmp_regular_tests(orig_funcname);
	memcmp_special_tests(orig_funcname);
	print_test_footer();
}

void	memcmp_test_helper(t_char_c *fname, t_void_c *s1, t_void_c *s2, size_t n)
{
	t_char_c	format[] = "(\"%s\"|\"%s\",\n\"%s\"|\"%s\", %lu) = ";
	int			ret;
	char		bytes_s1[READ_MEM_LIMIT + 1];
	char		bytes_s2[READ_MEM_LIMIT + 1];

	strlcpy(bytes_s1, read_mem((void *)s1, n, "\\x", 8), READ_MEM_LIMIT);
	strlcpy(bytes_s2, read_mem((void *)s2, n, "\\x", 8), READ_MEM_LIMIT);
	cprintf(YELLOW, "%s", fname);
	printf(format, bytes_s1, (char *)s1, bytes_s2, (char *)s2, n);
	if (strncmp(fname, "ft_memcmp", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_memcmp(s1, s2, n);
	else if (strncmp(fname, "memcmp", MAX_FUNC_NAME_LEN) == 0)
		ret = memcmp(s1, s2, n);
	else
		ret = ft_memcmp(s1, s2, n);
	printf("%d\n", ret);
}
