/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isprint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:43:45 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:36:33 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

/* It prints the ASCII table in
 * two columns so we can see which
 * symbols are printable and which
 * not. The left column shows the
 * output of the implementation of
 * our isprint() function, and the
 * right column shows the output
 * of the original isprint() function
 * from Glibc */
void	isprint_test(void)
{
	char	funcname[MAX_FUNC_NAME_LEN];
	int		i;

	strncpy(funcname, "ft_isprint", MAX_FUNC_NAME_LEN);
	print_test_header(funcname);
	printf("ft_isprint()\t\t\ttrue isprint() from LibC\n");
	i = 0;
	while (i < 256)
	{
		cprintf(YELLOW, "\t%s", funcname);
		printf("('%c'(%d)) = %d\t\t", i, i, ft_isprint(i));
		cprintf(YELLOW, "\t%s", "isprint");
		printf("('%c'(%d)) = %d\n", i, i, isprint(i));
		i++;
	}
	print_test_footer();
}
