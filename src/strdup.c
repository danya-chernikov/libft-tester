/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:53 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/24 18:41:38 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *s);

void	strdup_test()
{
	t_char_c	our_funcname[] = "ft_strdup";
	t_char_c	orig_funcname[] = "strdup";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	char	str[MAX_STRDUP_STR_LEN + 1];

	strlcpy(str, "My uncle's goodness is extreme, ", MAX_STRDUP_STR_LEN);
	strlcat(str, "If seriously he hath disease;", MAX_STRDUP_STR_LEN);
	test_helper(fname, 1, str);
}

/* It's a common test case */
static void	test_helper(t_char_c *fname, int ntest, t_char_c *s) 
{
	t_char_c	format[] = "(\"%s\") = %p -> \"%s\"\n";
	char		*ret;
	
	if (strncmp(fname, "ft_strdup", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_strdup(s);
	else if (strncmp(fname, "strdup", MAX_FUNC_NAME_LEN) == 0)
		ret = strdup(s);
	else
		ret = ft_strdup(s);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, s, ret, ret);
	free(ret);
}
