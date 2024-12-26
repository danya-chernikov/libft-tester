/* ************************************************************************** */ /*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:07 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/30 20:26:05 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

static void	form_tests(t_ps_tests *tests);
static void	add_test(t_ps_tests *tests, int test_ind, int number, int fd);

/*
 * It launches tests for the putnbr_fd() function.
 * Description of local variables:
	   test_num - the number of tests to perform.
	   For example, test_num = 3 indicates two
	   regular tests and one special test;
	   args     - a member of the structure that
	   describes all the tests to be performed on
	   the tested function. */
void	putnbr_fd_test(void)
{
	t_char_c	fname[] = "ft_putnbr_fd";
	t_ps_tests	tests;
	int			tests_num;

	print_test_header(fname);
	tests_num = 5;
	form_tests(&tests);
	ps_test_helper(fname, &tests, PUTNBR_FD_ID, tests_num);
	print_test_footer();
}

/*
 * It adds user-defined tests to the tests member
 * of the t_ps_tests structure.
 * Constants explanation:
 *     STDOUT = 1        - equivalent to stdout;
 *     STDERR = 2        - equivalent to stderr;
 *     NO_STD_STREAM = 0 - this indicates that it is not necessary
 *						   to determine a file descriptor for the
 *						   last special test because a temporary file
 *						   will be used.
 * */
static void	form_tests(t_ps_tests *tests)
{
	add_test(tests, 1, 2757, STDOUT);
	add_test(tests, 2, 0, STDERR);
	add_test(tests, 3, -8235749, STDERR);
	add_test(tests, 4, 5757400, NO_STD_STREAM);
	add_test(tests, 5, -2147483648, NO_STD_STREAM);
}

/* It adds an individual test. The `number` represents the first
 * argument of the tested function, and `fd` represents the second. */
static void	add_test(t_ps_tests *tests, int test_ind, int number, int fd)
{
	tests->first.number[test_ind - 1] = number;
	tests->second.fd[test_ind - 1] = fd;
}
