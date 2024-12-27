/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp_special.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:31:10 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:31:21 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/memcmp.h"

static void	special_test_1(t_char_c *fname, int ntest);
static void	special_test_2(t_char_c *fname, int ntest);
static void	special_test_3(t_char_c *fname, int ntest);

void	memcmp_special_tests(t_char_c *funcname)
{
	special_test_1(funcname, 7);
	special_test_2(funcname, 8);
	special_test_3(funcname, 9);
}

static void	special_test_1(t_char_c *fname, int ntest)
{
	size_t	i;
	char	data1[6];
	char	data2[6];

	i = 0;
	while (i < (sizeof (data1) / sizeof (char)))
	{
		data1[i] = 0x41 + i;
		data2[i] = 0x61 + i;
		i++;
	}
	printf("\t%d. ", ntest);
	memcmp_test_helper(fname, (void *)data1, (void *)data2, 6 * sizeof(char));
}

static void	special_test_2(t_char_c *fname, int ntest)
{
	int		arr1[5];
	int		arr2[5];

	fill_arr_int(arr1, 1, 1, sizeof (arr1) / sizeof (int));
	fill_arr_int(arr2, 1, 1, sizeof (arr2) / sizeof (int));
	printf("\t%d. ", ntest);
	arr2[4] = 6;
	memcmp_test_helper(fname, (void *)arr1, (void *)arr2, 5 * sizeof(int));
}

static void	special_test_3(t_char_c *fname, int ntest)
{
	int		arr1[5];
	int		arr2[5];

	fill_arr_int(arr1, 1, 1, sizeof (arr1) / sizeof (int));
	fill_arr_int(arr2, 1, 1, sizeof (arr2) / sizeof (int));
	printf("\t%d. ", ntest);
	arr1[4] = 6;
	arr2[4] = 5;
	memcmp_test_helper(fname, (void *)arr1, (void *)arr2, 5 * sizeof(int));
}
