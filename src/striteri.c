/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:58 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/25 20:51:02 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, char *str);
static void	func_for_striteri(u_int pos, char *ptr);

void	striteri_test(void)
{
	t_char_c	our_funcname[] = "ft_striteri";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	char	str[] = "euigheweruhqsa";

	test_helper(fname, 1, str);
}

static void	test_helper(t_char_c *fname, int ntest, char *str)
{
	t_char_c	format[] = "(\"%s\", func_for_striteri) = ";

	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str);
	ft_striteri(str, func_for_striteri);
	printf("\"%s\"\n", str);
}

/* We initialize and increment the 'pos' variable at the beginning
 * to avoid a compilation error caused by the unused parameter */
static void	func_for_striteri(u_int pos, char *ptr)
{
	pos = 0;
	pos++;
	if ((int)(*ptr) >= 0x61 && (int)(*ptr) <= 0x7A)
		(*ptr) = ((int)(*ptr)) - 0x20;
}
