/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:48 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tester.h"

/* It prints n bytes starting from the ptr address in memory.
 * It uses a space as a delimiter between the bytes printed.
 * If a caller wants to print a too long peace of memory the
 * function does nothing */
void	print_bytes(void *ptr, int n)
{
	u_char	*p;
	int		i;

	if (n > READ_MEM_LIMIT)
		return ;
	p = (u_char *)ptr;
	i = 0;
	while (i < n)
	{
		printf("%02hhX ", p[i]);
		i++;
	}
	printf("\n");
}

/* It behaves the same as print_bytes(), but accepts a delimiter string
 * and returns the string of bytes instead of printing it */
char	*read_mem(void *ptr, int n, t_char_c *delim, int height)
{
	static char	bstr[READ_MEM_LIMIT + 1];
	char		one_byte[DELIM_BYTES_LIMIT + 2 + 1];
	u_char		*p;
	int			i;

	if (n > READ_MEM_LIMIT)
		return (NULL);
	if (strlen(delim) > DELIM_BYTES_LIMIT)
		return (NULL);
	if (n * (strlen(delim) + 2) > READ_MEM_LIMIT)
		return (NULL);
	bstr[0] = '\0';
	p = (u_char *)ptr;
	i = 0;
	while (i < n)
	{
		snprintf(one_byte, DELIM_BYTES_LIMIT + 2, "%s%02hhX", delim, p[i]);
		strlcat(bstr, one_byte, READ_MEM_LIMIT);
		if (i % height == 0 && i >= height)
			strlcat(bstr, "\n", READ_MEM_LIMIT);
		i++;
	}
	return (bstr);
}

void	print_arr_int(int *arr, size_t size)
{
	size_t	i;

	printf("{ ");
	i = 0;
	while (i < size)
	{
		printf("%d", arr[i++]);
		if (i < size - 1)
			printf(", ");
		else
			printf(" ");
	}
	puts("}\n");
}
