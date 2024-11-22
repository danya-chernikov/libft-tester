/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:11 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/22 15:46:49 by dchernik         ###   ########.fr       */
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
