/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:11 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/11 18:55:39 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tester.h"

void	print_test_header(const char *funcname)
{
	int	i;

	i = 0;
	putchar('\n');
	while (i < TEST_HD_FT_LEN)
	{
		putchar(TEST_HD_FT_SYM);
		i++;
	}
	putchar('\n');
	cprintf(GREEN, "TEST OF %s()\n\n", funcname);
}

void	print_test_footer(void)
{
	int	i;

	i = 0;
	putchar('\n');
	while (i < TEST_HD_FT_LEN)
	{
		putchar(TEST_HD_FT_SYM);
		i++;
	}
	printf("\n\n");
}

/* It gets the size of the file represented by the fd
 * file descriptor. First, the lseek() system call
 * sets the file position indicator to the end of the
 * file (adding 0 to SEEK_END). Then, the next lseek()
 * invocation retrieves the file size in bytes, which
 * is the current value of the file position indicator.
 * Finally, the third lseek() call sets the file position
 * indicator to the beginning of the file, allowing it t
 * be read from the start */
long	get_filesize(int fd)
{
	long	size;

	lseek(fd, 0, SEEK_END);
	size = lseek(fd, 0, SEEK_CUR);
	lseek(fd, 0, SEEK_SET);
	return (size);
}
