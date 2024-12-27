#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

/* Writes the data (character, string, string with '\n' or a number)
 * into the temporary file. */
void	write_temp_file(t_char_c *fname, void **pack, int *fd)
{
	t_ps_tests	*tests;
	t_func_id	find;
	int			tnum;

	tests = (t_ps_tests *)pack[0];
	find = *(t_func_id *)pack[1];
	tnum = *(int *)pack[2];
	if (find == PUTCHAR_FD_ID)
	{
		putchar_fd_write(fname, tests, tnum, fd);
	}
	else if (find == PUTSTR_FD_ID)
	{
		putstr_fd_write(fname, tests, tnum, fd);
	}
	else if (find == PUTENDL_FD_ID)
	{
		putendl_fd_write(fname, tests, tnum, fd);
	}
	else if (find == PUTNBR_FD_ID)
	{
		putnbr_fd_write(fname, tests, tnum, fd);
	}
}

void	putchar_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd)
{
	char	format[MAX_FORMAT_STR_LEN + 1];

	strncpy(format, "\tWriting the character '%c'", MAX_FORMAT_STR_LEN);
	strncat(format, " into the %s using %s()\n", MAX_FORMAT_STR_LEN);
	printf(format, tests->first.symbol[tnum - 1], TEMP_FILE_NAME, fname);
	ft_putchar_fd(tests->first.symbol[tnum - 1], *fd);
}

void	putstr_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd)
{
	char	format[MAX_FORMAT_STR_LEN + 1];

	strncpy(format, "\tWriting the string \"%s\"", MAX_FORMAT_STR_LEN);
	strncat(format, " into the %s using %s()\n", MAX_FORMAT_STR_LEN);
	printf(format, tests->first.string[tnum - 1], TEMP_FILE_NAME, fname);
	ft_putstr_fd(tests->first.string[tnum - 1], *fd);
}

void	putendl_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd)
{
	char	format[MAX_FORMAT_STR_LEN + 1];

	strncpy(format, "\tWriting the string \"%s\"", MAX_FORMAT_STR_LEN);
	strncat(format, " with '\\n' symbol at the end", MAX_FORMAT_STR_LEN);
	strncat(format, " into the %s using %s()\n", MAX_FORMAT_STR_LEN);
	printf(format, tests->first.string[tnum - 1], TEMP_FILE_NAME, fname);
	ft_putendl_fd(tests->first.string[tnum - 1], *fd);
}

void	putnbr_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd)
{
	char	format[MAX_FORMAT_STR_LEN + 1];

	strncpy(format, "\tWriting the number %d", MAX_FORMAT_STR_LEN);
	strncat(format, " into the %s using %s()\n", MAX_FORMAT_STR_LEN);
	printf(format, tests->first.number[tnum - 1], TEMP_FILE_NAME, fname);
	ft_putnbr_fd(tests->first.number[tnum - 1], *fd);
}
