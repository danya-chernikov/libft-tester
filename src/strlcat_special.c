/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_special.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:26 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 19:01:07 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/strlcat.h"

static void	special_test_1(t_char_c *fn, int ntest, t_char_c *src, size_t size);
static void	special_test_2(t_char_c *fn, int ntest, t_char_c *src, size_t size);
static void	special_test_3(t_char_c *fn, int ntest, t_char_c *src, size_t size);
static void	special_test_4(t_char_c *fn, int ntest, t_char_c *src, size_t size);

void	strlcat_special_tests(t_char_c *funcname)
{
	char	src[32];

	strlcpy(src, " of the muse of the dark", 32);
	special_test_1(funcname, 12, src, 10);
	special_test_2(funcname, 13, src, strlen(src) + 1);
	special_test_3(funcname, 14, src, strlen(src) + 1);
	special_test_4(funcname, 15, src, strlen(src) + 1);
}

static void	special_test_1(t_char_c *fn, int ntest, t_char_c *src, size_t size)
{
	char	dst[64];

	printf("\n\tLet's see what will happen if the original"
		"dst string is longer than dstsize\n");
	strlcpy(dst, "You - but the voice", 64);
	printf("\t%d. ", ntest);
	strlcat_test_helper(fn, dst, src, size);
}

static void	special_test_2(t_char_c *fn, int ntest, t_char_c *src, size_t size)
{
	char	dst[64];

	printf("\n\tLet's see what will happen if"
		"the original dst buffer is empty\n");
	bzero((void *)dst, 64);
	printf("\t%d. ", ntest);
	strlcat_test_helper(fn, dst, src, size);
}

static void	special_test_3(t_char_c *fn, int ntest, t_char_c *src, size_t size)
{
	char	dst[64];

	printf("\n\tLet's see what will happen if"
		"the original src buffer is empty\n");
	bzero((void *)src, strlen(src));
	strlcpy(dst, "You - but the voice", 64);
	printf("\t%d. ", ntest);
	strlcat_test_helper(fn, dst, src, size);
}

static void	special_test_4(t_char_c *fn, int ntest, t_char_c *src, size_t size)
{
	char	dst[64];

	bzero((void *)src, strlen(src));
	strlcpy(dst, "You - but the voice", 64);
	printf("\n\tLet's see what will happen if the original src buffer"
		"is empty and dstsize is greater than length of dst\n");
	printf("\t%d. ", ntest);
	strlcat_test_helper(fn, dst, src, size);
}
