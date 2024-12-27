/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:58 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 15:02:30 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	strlen_our(void);
static void	strlen_orig(void);

/* Main function that tests
 * ft_strlen(), launching
 * both tests of our own
 * implementation and the
 * same tests of the original
 * strlen() from Glibc, to be
 * able to compare their results */
void	strlen_test(void)
{
	char	funcname[MAX_FUNC_NAME_LEN];

	strncpy(funcname, "ft_strlen", MAX_FUNC_NAME_LEN);
	print_test_header(funcname);
	printf("ft_strlen():\n");
	strlen_our();
	printf("true strlen() from LibC:\n");
	strlen_orig();
	print_test_footer();
}

/* It launches tests of our
 * own strlen() implementation.
 * We color function name
 * yellow to make it visually
 * more noticeable */
static void	strlen_our(void)
{
	char	str1[256];
	char	str2[256];
	char	str3[32];

	strncpy(str1, "urhg r849(Hht49t#*%   hr", 256);
	strncpy(str2, "Farewell, thou pathway of the free,\n", 256);
	strncat(str2, "For the last time thy waves I view", 256);
	strncat(str2, "\nBefore me roll disdainfully,\n", 256);
	strncat(str2, "Brilliantly beautiful and blue.", 256);
	str3[0] = '\0';
	printf("\t1. %sft_strlen%s(str1) = %lu\n", YELLOW, WHITE, strlen(str1));
	printf("\t2. %sft_strlen%s(str2) = %lu\n", YELLOW, WHITE, strlen(str2));
	printf("\t3. %sft_strlen%s(str3) = %lu\n", YELLOW, WHITE, strlen(str3));
}

/* It launches tests of the
 * original strlen() function */
static void	strlen_orig(void)
{
	char	str1[256];
	char	str2[256];
	char	str3[32];

	strncpy(str1, "urhg r849(Hht49t#*%   hr", 256);
	strncpy(str2, "Farewell, thou pathway of the free,\n", 256);
	strncat(str2, "For the last time thy waves I view", 256);
	strncat(str2, "\nBefore me roll disdainfully,\n", 256);
	strncat(str2, "Brilliantly beautiful and blue.", 256);
	str3[0] = '\0';
	printf("\t1. %sstrlen%s(str1) = %lu\n", YELLOW, WHITE, strlen(str1));
	printf("\t2. %sstrlen%s(str2) = %lu\n", YELLOW, WHITE, strlen(str2));
	printf("\t3. %sstrlen%s(str3) = %lu\n", YELLOW, WHITE, strlen(str3));
}
