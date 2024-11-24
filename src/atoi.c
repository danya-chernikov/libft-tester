/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:41:21 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/24 20:23:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *fname);
static void launch_tests_part_2(t_char_c *fname);
static void	test_helper(t_char_c *fname, int ntest, char *s);

void	atoi_test(void)
{
	t_char_c	our_funcname[] = "ft_atoi";
	t_char_c	orig_funcname[] = "atoi";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	launch_tests_part_2(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	launch_tests_part_2(orig_funcname);
	print_test_footer();
}

/* It launches the first 25 tests of ft_atoi() */
static void	launch_tests(t_char_c *fname)
{
	test_helper(fname, 1, "574209");
	test_helper(fname, 2, "2147483647");
	test_helper(fname, 3, "0");
	test_helper(fname, 4, "-37528");
	test_helper(fname, 5, "-2147483647");
	test_helper(fname, 6, "-2147483648");
	test_helper(fname, 7, "+1");
	test_helper(fname, 8, "  1");
	test_helper(fname, 9, "  100eurgh");
	test_helper(fname, 10, "100  ");
	test_helper(fname, 11, "  erg1004rf  ");
	test_helper(fname, 12, "345t4");
	test_helper(fname, 13, "r4993");
	test_helper(fname, 14, "   r4993");
	test_helper(fname, 15, "-5764fr  ");
	test_helper(fname, 16, "-5764   fr  ");
	test_helper(fname, 17, "    +1000000");
	test_helper(fname, 18, "    ++1");
	test_helper(fname, 19, "++10");
	test_helper(fname, 20, "01");
	test_helper(fname, 21, "-02");
	test_helper(fname, 22, "0004");
	test_helper(fname, 23, "-0004");
	test_helper(fname, 24, "--10");
	test_helper(fname, 25, "8");
}

/* It launches the last 17 tests of ft_atoi() */
static void launch_tests_part_2(t_char_c *fname)
{
	test_helper(fname, 26, "12");
	test_helper(fname, 27, "+12");
	test_helper(fname, 28, "  12");
	test_helper(fname, 29, "+2");
	test_helper(fname, 30, "  2");
	test_helper(fname, 31, "");
	test_helper(fname, 32, "      ");
	test_helper(fname, 33, "eriughwUEH");
	test_helper(fname, 34, "                      1eu rg h  ");
	test_helper(fname, 35, "+47+5");
	test_helper(fname, 36, "-47-5");
	test_helper(fname, 37, "+47+-5");
	test_helper(fname, 38, "-47--5");
	test_helper(fname, 39, "+47+-5 --1--");
	test_helper(fname, 40, "-45++   ");
	test_helper(fname, 41, "\t\n\r\v\f  469 \n");
	test_helper(fname, 42, "\n\n\n  -46\b9 \n5d6");
}

/* It's a common test case */
static void	test_helper(t_char_c *fname, int ntest, char *s)
{
	t_char_c	format[] = "(\"%s\") = %d\n";
	int			ret;
	
	if (strncmp(fname, "ft_atoi", MAX_FUNC_NAME_LEN) == 0)
		ret = ft_atoi(s);
	else if (strncmp(fname, "atoi", MAX_FUNC_NAME_LEN) == 0)
		ret = atoi(s);
	else
		ret = ft_atoi(s);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, s, ret);
}
