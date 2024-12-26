#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

/* It displays to the user the content read from the temporary file,
 * i.e., the result of the special test */
void	print_special_test_res(t_char_c *fname, void **pack, char **readbuf)
{
	t_ps_tests	*tests;
	t_func_id	find;
	int			tnum;

	tests = (t_ps_tests *)pack[0];
	find = *(t_func_id *)pack[1];
	tnum = *(int *)pack[2];
	if (find == PUTCHAR_FD_ID)
	{
		print_putchar_res(fname, tests, tnum, readbuf);
	}
	else if (find == PUTSTR_FD_ID)
	{
		print_putstr_res(fname, tests, tnum, readbuf);
	}
	else if (find == PUTENDL_FD_ID)
	{
		print_putendl_res(fname, tests, tnum, readbuf);
	}
	else if (find == PUTNBR_FD_ID)
	{
		print_putnbr_res(fname, tests, tnum, readbuf);
	}
}

void	print_putchar_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rbuf)
{
	printf("\t%d. ", tnum);
	cprintf(YELLOW, "%s", fn);
	printf(PUTCHAR_FORMAT, tests->first.symbol[tnum - 1], *rbuf);
}

void	print_putstr_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rbuf)
{
	printf("\t%d. ", tnum);
	cprintf(YELLOW, "%s", fn);
	printf(PUTSTR_FORMAT, tests->first.string[tnum - 1], *rbuf);
}

void	print_putendl_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rbuf)
{
	printf("\t%d. ", tnum);
	cprintf(YELLOW, "%s", fn);
	printf(PUTENDL_FORMAT, tests->first.string[tnum - 1], *rbuf);
}

void	print_putnbr_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rbuf)
{
	printf("\t%d. ", tnum);
	cprintf(YELLOW, "%s", fn);
	printf(PUTNBR_FORMAT, tests->first.number[tnum - 1], *rbuf);
}
