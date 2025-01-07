/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat_regular.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:54:20 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/07 18:50:18 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/strlcat.h"

static void	regular_test(t_char_c *fn, int ntest, t_char_c *src, size_t size);

void	strlcat_regular_tests(t_char_c *funcname)
{
	char	src[256];
	char	src2[256];

	strncpy(src, " of the muse of the dark", 255);
	strncpy(src2, " of the muse of the dark. L touch your ear?", 255);
	strncat(src2, " Do you understand the soul of the humble ", 255);
	strncat(src2, "The desire of my heart?", 255);
	regular_test(funcname, 1, src, 64);
	regular_test(funcname, 2, src2, 64);
	regular_test(funcname, 3, src, 0);
	regular_test(funcname, 4, src, 1);
	regular_test(funcname, 5, src, 2);
	regular_test(funcname, 6, src, 17);
	regular_test(funcname, 7, src, 18);
	regular_test(funcname, 8, src, 19);
	regular_test(funcname, 9, src, 20);
	regular_test(funcname, 10, src, 44);
	regular_test(funcname, 11, src, 40);
}

static void	regular_test(t_char_c *fn, int ntest, t_char_c *src, size_t size)
{
	char	dst[64];

	strncpy(dst, "You - but the voice", 63);
	printf("\t%d. ", ntest);
	strlcat_test_helper(fn, dst, src, size);
}
