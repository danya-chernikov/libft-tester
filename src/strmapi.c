/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:56:57 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/25 19:59:05 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *str);
static char	func_for_strmapi(u_int pos, char symbol);

void	strmapi_test(void)
{
	t_char_c	our_funcname[] = "ft_strmapi";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, "euigheweruhqsa");
}

static void	test_helper(t_char_c *fname, int ntest, t_char_c *str)
{
	t_char_c	format[] = "(\"%s\", func_for_strmapi) = \"%s\"\n";
	char		*ret;

	ret = ft_strmapi(str, func_for_strmapi);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str, ret);
    free(ret);
}

/* We initialize and increment the 'pos' variable at the beginning
 * to avoid a compilation error caused by the unused parameter */
static char	func_for_strmapi(u_int pos, char symbol)
{
	pos = 0;
	pos++;
	if ((int)symbol >= 0x61 && (int)symbol <= 0x7A)
		return ((int)symbol - 0x20);
	return (symbol);
}
