#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

/*
 * It launches regular tests based on the function index find passed
 * into this function, the appropriate function is called for testing.
 * The condition while (test_ind < tnum - 1) is used because the last
 * test is a special test. */
void	ps_regular_tests(t_char_c *fn, ps_tests *tests, func_id find, int tnum)
{
	int	test_ind;

	test_ind = 0;
	while (test_ind < tnum - 1)
	{
		if (find == PUTCHAR_FD_ID)
		{
			call_putchar_fd(fn, tests, test_ind);
		}
		else if (find == PUTSTR_FD_ID)
		{
			call_putstr_fd(fn, tests, test_ind);
		}
		else if (find == PUTENDL_FD_ID)
		{
			call_putendl_fd(fn, tests, test_ind);
		}
		else if (find == PUTNBR_FD_ID)
		{
			call_putnbr_fd(fn, tests, test_ind);
		}
		test_ind++;
	}
}

/*
 * It launches the putchar_fd() function and displays the
 * result of its execution */
void	call_putchar_fd(t_char_c *fname, ps_tests *tests, int test_ind)
{
	t_char_c	format[] = "('%c', %d): ";

	printf("\t%d. ", test_ind + 1);
	cprintf(YELLOW, "%s", fname);
	printf(format, tests->first.symbol[test_ind], tests->second.fd[test_ind]);
	fflush(NULL);
	ft_putchar_fd(tests->first.symbol[test_ind], tests->second.fd[test_ind]);
	printf("\n");
}

void	call_putstr_fd(t_char_c *fname, ps_tests *tests, int test_ind)
{
	t_char_c	format[] = "(\"%s\", %d): ";

	printf("\t%d. ", test_ind + 1);
	cprintf(YELLOW, "%s", fname);
	printf(format, tests->first.string[test_ind], tests->second.fd[test_ind]);
	fflush(NULL);
	ft_putstr_fd(tests->first.string[test_ind], tests->second.fd[test_ind]);
	printf("\n");
}

void	call_putendl_fd(t_char_c *fname, ps_tests *tests, int test_ind)
{
	t_char_c	format[] = "(\"%s\", %d): ";

	printf("\t%d. ", test_ind + 1);
	cprintf(YELLOW, "%s", fname);
	printf(format, tests->first.string[test_ind], tests->second.fd[test_ind]);
	fflush(NULL);
	ft_putendl_fd(tests->first.string[test_ind], tests->second.fd[test_ind]);
	printf("\n");
}

void	call_putnbr_fd(t_char_c *fname, ps_tests *tests, int test_ind)
{
	t_char_c	format[] = "(%d, %d): ";

	printf("\t%d. ", test_ind + 1);
	cprintf(YELLOW, "%s", fname);
	printf(format, tests->first.number[test_ind], tests->second.fd[test_ind]);
	fflush(NULL);
	ft_putnbr_fd(tests->first.number[test_ind], tests->second.fd[test_ind]);
	printf("\n");
}
