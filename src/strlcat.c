/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:14 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:47:00 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/strlcat.h"

void	strlcat_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_strlcat", MAX_FUNC_NAME_LEN);
	strncpy(orig_funcname, "strlcat", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	strlcat_regular_tests(our_funcname);
	strlcat_special_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	strlcat_regular_tests(orig_funcname);
	strlcat_special_tests(orig_funcname);
	print_test_footer();
}

/* It's a common test case */
void	strlcat_test_helper(t_char_c *fn, char *dst, t_char_c *src, size_t size)
{
	size_t	ret;

	cprintf(YELLOW, "%s", fn);
	printf("(\"%s\", \"%s\", %lu) = ", dst, src, size);
	if (strncmp(fn, "ft_strlcat", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_strlcat(dst, src, size);
	else if (strncmp(fn, "strlcat", MAX_FUNC_NAME_LEN) == 0)
		ret = strlcat(dst, src, size);
	else
		ret = ft_strlcat(dst, src, size);
	printf("%lu\n", ret);
	printf("\t\tdestination buffer is: \"%s\"\n", dst);
	printf("\t\t");
	print_bytes(dst, 64);
	printf("\t\tstrlen(dst) = %lu\n", strlen(dst));
}
