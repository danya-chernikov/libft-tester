/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putchar_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:52:49 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 15:07:50 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

static void	form_tests(t_ps_tests *tests);
static void	add_test(t_ps_tests *tests, int test_ind, char symbol, int fd);

/*
 * It launches tests for the putchar_fd() function.
 * Description of local variables:
	   test_num - the number of tests to perform.
	   For example, test_num = 3 indicates two
	   regular tests and one special test;
	   args     - a member of the structure that
	   describes all the tests to be performed on
	   the tested function. */
void	putchar_fd_test(void)
{
	t_char_c	fname[] = "ft_putchar_fd";
	t_ps_tests	tests;
	int			tests_num;

	print_test_header(fname);
	tests_num = 3;
	form_tests(&tests);
	ps_test_helper(fname, &tests, PUTCHAR_FD_ID, tests_num);
	print_test_footer();
}

/*
 * It adds user-defined tests to the tests member
 * of the ps_tests structure.
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
	add_test(tests, 1, 'a', STDOUT);
	add_test(tests, 2, 'b', STDERR);
	add_test(tests, 3, 'c', NO_STD_STREAM);
}

/* It adds an individual test. The `symbol` represents the first
 * argument of the tested function, and `fd` represents the second. */
static void	add_test(t_ps_tests *tests, int test_ind, char symbol, int fd)
{
	tests->first.symbol[test_ind - 1] = symbol;
	tests->second.fd[test_ind - 1] = fd;
}
