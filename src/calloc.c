/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:41:52 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 15:48:39 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, size_t nmemb, size_t size);

void	calloc_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strlcpy(our_funcname, "ft_calloc", MAX_FUNC_NAME_LEN);
	strlcpy(orig_funcname, "calloc", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, 32, sizeof(u_char));
	test_helper(fname, 2, 0, sizeof(u_char));
}

/* It's a common test case */
static void	test_helper(t_char_c *fname, int ntest, size_t nmemb, size_t size)
{
	t_char_c	format[] = "(%lu, %lu) = %p\n";
	u_char		*ret;
	
	if (strncmp(fname, "ft_calloc", MAX_FUNC_NAME_LEN) == 0)
		ret = (u_char *)ft_calloc(nmemb, size);
	else if (strncmp(fname, "calloc", MAX_FUNC_NAME_LEN) == 0)
		ret = (u_char *)calloc(nmemb, size);
	else
		ret = (u_char *)ft_calloc(nmemb, size);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, nmemb, size, ret);
	printf("\t");
	print_bytes(ret, (nmemb * size) + 10);
}
