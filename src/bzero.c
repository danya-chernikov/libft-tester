/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:41:33 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:34:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	bzero_our(void);
static void	bzero_orig(void);

/* Main function that tests ft_bzero(). As usual, it prints the standard
 * test header, then launches tests of our implementation of the bzero()
 * function, followed by the same tests for the original bzero() function
 * from Glibc, to be able to compare their results. Finally, it prints the
 * standard footer stub that visually indicates the end of testing */
void	bzero_test(void)
{
	char	funcname[MAX_FUNC_NAME_LEN];

	strncpy(funcname, "ft_bzero", MAX_FUNC_NAME_LEN);
	print_test_header(funcname);
	printf("ft_bzero():\n");
	bzero_our();
	printf("true bzero() from LibC:\n");
	bzero_orig();
	print_test_footer();
}

/* It launches tests of our own bzero() implementation. We color
 * function name yellow to make it visually more noticeable */
static void	bzero_our(void)
{
	char	buf[32];

	printf("\t1. %sft_bzero%s(buf, 32):\n", YELLOW, WHITE);
	ft_bzero(buf, 32);
	printf("\t\t");
	print_bytes(buf, 40);
}

/* It launches tests of the original bzero() function */
static void	bzero_orig(void)
{
	char	buf[32];

	printf("\t1. %sbzero%s(buf, 32):\n", YELLOW, WHITE);
	bzero(buf, 32);
	printf("\t\t");
	print_bytes(buf, 40);
}
