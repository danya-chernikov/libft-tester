#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

/* 
 * It launches all the tests (both regular and one special)
 * for a function determined by the find argument.
 * Description of the arguments this function accepts:
 *     fn     - The name of the function (passed without
 *				parentheses) that will be tested;
 *     t:     - An array of arguments to pass to the tested
 *				function, indexed by find. Each element of
 *				this array corresponds to a regular test;
 *     find   - The index of the tested function: 
 *	       find = PUTCHAR_FD_ID = 0: ft_putchar_fd();
 *         find = PUTSTR_FD_ID  = 1: ft_putstr_fd();
 *         find = PUTENDL_FD_ID = 2: ft_putendl_fd();
 *         find = PUTNBR_FD_ID  = 3: ft_putnbr_fd().
 *     tnum   - The total number of tests to be performed
 *				on the tested function for the given find
 *				index. This includes the regular tnum - 1
 *				tests and one special test, where a temporary
 *				file is used. It is possible to pass 0 to
 *				perform only the special test without launching
 *				regular tests. */
void	ps_test_helper(t_char_c *fn, ps_tests *tests, func_id find, int tnum)
{
	char	*errbuf;
	char	*readbuf;
	void	**pack;

	errbuf = NULL;
	readbuf = NULL;
	if(!ps_alloc_mem(fn, &readbuf, &errbuf))
		return;
	ps_regular_tests(fn, tests, find, tnum);
	pack = pack_args(3, (void *)tests, (void *)&find, (void *)&tnum);
	if (!ps_special_test(fn, pack, &readbuf, &errbuf))
		return;
	ps_free_mem(&readbuf, &errbuf);
}

/*
 * It allocates memory for the error buffer and the read buffer.
 * Description of the arguments:
 *     readbuf    - A buffer used to store the content read
 *					from a file;
 *     errbuf     - The main buffer used to store an error
 *					message.
 * Description of the local variables:
 *     res_errbuf - A reserve error buffer used to indicate a
 *					potential memory allocation error for the 
 *					main error buffer. */
int	ps_alloc_mem(t_char_c *fname, char **readbuf, char **errbuf)
{
	char	res_errbuf[MAX_ERR_BUF_SIZE + 1];

	*errbuf = (char *)calloc((MAX_ERR_BUF_SIZE + 1), sizeof(char));
	if (*errbuf == NULL)
	{
		form_alloc_errbuf_err_msg(fname, res_errbuf);
		perror(res_errbuf);
		return (ERROR);
	}
	*readbuf = (char *)calloc((FILE_READ_BUF_SIZE + 1), sizeof(char));
	if (*readbuf == NULL)
	{
		form_alloc_readbuf_err_msg(fname, *errbuf);
		perror(*errbuf);
		free(*errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}

void	ps_free_mem(char **readbuf, char **errbuf)
{
	free(*readbuf);
	free(*errbuf);
}

/* It deletes our temporary file */
int	delete_temp_file(t_char_c *fname, char **errbuf)
{
	printf("\tDeleting file content\n");
	if (unlink(TEMP_FILE_NAME) == -1)
	{
		form_delete_temp_file_err_msg(fname, *errbuf);
		perror(*errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}
