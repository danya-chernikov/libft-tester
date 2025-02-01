/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_alloc6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:15:22 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:15:26 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

t_ll	*alloc_longlong(t_ll val)
{
	t_ll	*ptr;

	ptr = (t_ll *)malloc(1 * sizeof (t_ll));
	*ptr = val;
	return (ptr);
}

t_ull	*alloc_ulonglong(t_ull val)
{
	t_ull	*ptr;

	ptr = (t_ull *)malloc(1 * sizeof (t_ull));
	*ptr = val;
	return (ptr);
}

float	*alloc_float(float val)
{
	float	*ptr;

	ptr = (float *)malloc(1 * sizeof (float));
	*ptr = val;
	return (ptr);
}

double	*alloc_double(double val)
{
	double	*ptr;

	ptr = (double *)malloc(1 * sizeof (double));
	*ptr = val;
	return (ptr);
}

t_ld	*alloc_ldouble(t_ld val)
{
	t_ld	*ptr;

	ptr = (t_ld *)malloc(1 * sizeof (t_ld));
	*ptr = val;
	return (ptr);
}
