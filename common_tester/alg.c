/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:46 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tester.h"

void	fill_arr_int(int *arr, size_t start, size_t step, size_t size)
{
	size_t	i;
	size_t	val;

	i = 0;
	val = start;
	while (i < size)
	{
		arr[i] = val;
		val += step;
		i++;
	}
}

int	max(int v1, int v2)
{
	if (v1 >= v2)
		return (v1);
	return (v2);
}

int	min(int v1, int v2)
{
	if (v1 >= v2)
		return (v2);
	return (v1);
}
