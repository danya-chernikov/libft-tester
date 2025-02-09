/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putendl_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:52:59 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:59:28 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

static void	form_tests(t_ps_tests *tests);
static void	add_test(t_ps_tests *tests, int test_ind, char *str, int fd);

/* It launches tests for the putendl_fd() function.
 * Description of local variables:
	   test_num - the number of tests to perform.
				  For example, test_num = 3
				  indicates two regular tests
				  and one special test;
	   args     - a member of the structure that
				  describes all the tests to be
				  performed on the tested function. */
void	putendl_fd_test(void)
{
	char		fname[MAX_FUNC_NAME_LEN];
	char		errbuf[MAX_ERR_BUF_SIZE + 1];
	int			tests_num;
	t_ps_tests	tests;

	strncpy(fname, "ft_putendl_fd", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	tests_num = 3;
	tests.first.string = alloc_str_2d(tests_num, MAX_TEST_STR_LEN + 1);
	if (tests.first.string == NULL)
	{
		form_common_err_msg(errbuf, fname, PUTSMTH_MEM_ERR_STRS);
		perror(errbuf);
		print_test_footer();
		return ;
	}
	form_tests(&tests);
	ps_test_help(fname, &tests, PUTENDL_FD_ID, tests_num);
	free_str_2d(tests.first.string, tests_num);
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
	add_test(tests, 1, "test_string with '\\n'", STDOUT);
	add_test(tests, 2, "blablabla", STDERR);
	add_test(tests, 3, "a string that is in the file", NO_STD_STREAM);
}

/* It adds an individual test. The `str` represents the first
 * argument of the tested function, and `fd` represents the second. */
static void	add_test(t_ps_tests *tests, int test_ind, char *str, int fd)
{
	strncpy(tests->first.string[test_ind - 1], str, MAX_TEST_STR_LEN);
	tests->second.fd[test_ind - 1] = fd;
}
