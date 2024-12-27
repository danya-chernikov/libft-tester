/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putsmth_fd_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:16 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:31:21 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"

/*
 * This test is referred to as 'special' and is common
 * to each tested function.
 *
 * This test performs the following steps:
 *     1. Creates a temporary file;
 *     2. Writes the argument passed to the tested
 *        function into the file;
 *     3. Closes the temporary file;
 *     4. Reads the argument back from the file;
 *     5. Closes the file;
 *     6. Prints the read data (argument value) to the
 *        standard output;
 *     7. Deletes the temporary file.
 *
 * Description of Local Variables:
 *     tests - An array of arguments describing each test;
 *     fd:   - The file descriptor used in the final
 *             "special" test.
 *
 * Function Arguments:
 * This function accepts six arguments: fn, tests, find,
 * tnum, readbuf, and errbuf. However, to comply with the
 * rule that no more than four arguments can be passed to
 * a function, three of these arguments (tests, find, and
 * tnum) are packed into a structure called pack. Inside
 * this function, the pack is unpacked to access these
 * variables, allowing them to be used without issues.
 * The same pack is later passed to the read_temp_file()
 * function using the same mechanism.
 *
 * We pass readbuf to the create_temp_file() and
 * open_temp_file() functions solely to ensure that the
 * memory allocated for it can be freed in case of an error. */
int	ps_special_test(t_char_c *fname, void **pack, char **readbuf, char **errbuf)
{
	t_ps_tests	*tests;
	t_func_id	find;
	int			tnum;
	int			fd;

	tests = (t_ps_tests *)pack[0];
	find = *(t_func_id *)pack[1];
	tnum = *(int *)pack[2];
	if (!create_temp_file(fname, &fd, readbuf, errbuf))
		return (ERROR);
	write_temp_file(fname, pack, &fd);
	close(fd);
	if (!open_temp_file(fname, &fd, readbuf, errbuf))
		return (ERROR);
	if (!read_temp_file(fname, &fd, readbuf, errbuf))
		return (ERROR);
	close(fd);
	print_special_test_res(fname, pack, readbuf);
	if (delete_temp_file(fname, errbuf))
		return (ERROR);
	return (SUCCESS);
}

/* It creates a temporary file to be used later during
 * the special test. */
int	create_temp_file(t_char_c *fname, int *fd, char **readbuf, char **errbuf)
{
	printf("\n\tCreating a file %s\n", TEMP_FILE_NAME);
	*fd = open(TEMP_FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*fd < 0)
	{
		form_common_file_err_msg(*errbuf, fname, FILE_CREAT_ERR_MSG);
		perror(*errbuf);
		ps_free_mem(readbuf, errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}

/* It opens the created temporary file */
int	open_temp_file(t_char_c *fname, int *fd, char **readbuf, char **errbuf)
{
	*fd = open(TEMP_FILE_NAME, O_RDONLY);
	if (*fd < 0)
	{
		form_common_file_err_msg(*errbuf, fname, FILE_OPEN_ERR_MSG);
		perror(*errbuf);
		delete_temp_file(fname, errbuf);
		ps_free_mem(readbuf, errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}

/* It reads the content of the temporary file.
 *     rb - number of read bytes from the file. */
int	read_temp_file(t_char_c *fname, int *fd, char **readbuf, char **errbuf)
{
	long	file_size;
	int		rb;

	printf("\tReading file content\n");
	file_size = get_filesize(*fd);
	rb = read(*fd, *readbuf, file_size);
	if (rb == -1)
	{
		form_common_file_err_msg(*errbuf, fname, FILE_READ_ERR_MSG);
		perror(*errbuf);
		close(*fd);
		delete_temp_file(fname, errbuf);
		ps_free_mem(readbuf, errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}
