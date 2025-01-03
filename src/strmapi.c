/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmapi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:56:57 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:52:27 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *str);
static char	func_for_strmapi(u_int pos, char symbol);

void	strmapi_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_strmapi", MAX_FUNC_NAME_LEN);
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
	char	f[MAX_FORMAT_STR_LEN];
	char	*ret;

	strncpy(f, "(\"%s\", func_for_strmapi) = \"%s\"\n", MAX_FORMAT_STR_LEN);
	ret = ft_strmapi(str, func_for_strmapi);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(f, str, ret);
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
