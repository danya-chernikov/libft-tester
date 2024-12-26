/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striteri.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:58 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 18:19:51 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, char *str);
static void	func_for_striteri(u_int pos, char *ptr);

void	striteri_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strlcpy(our_funcname, "ft_striteri", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

static void	launch_tests(t_char_c *fname)
{
	char	str[32];

	strlcpy(str, "euigheweruhqsa", 32);
	test_helper(fname, 1, str);
}

static void	test_helper(t_char_c *fname, int ntest, char *str)
{
	char	format[MAX_FORMAT_STR_LEN];

	strlcpy(format, "(\"%s\", func_for_striteri) = ", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str);
	ft_striteri(str, func_for_striteri);
	printf("\"%s\"\n", str);
}

/* We initialize and increment the 'pos' variable
 * at the beginning to avoid a compilation error
 * caused by the unused parameter */
static void	func_for_striteri(u_int pos, char *ptr)
{
	pos = 0;
	pos++;
	if ((int)(*ptr) >= 0x61 && (int)(*ptr) <= 0x7A)
		(*ptr) = ((int)(*ptr)) - 0x20;
}
