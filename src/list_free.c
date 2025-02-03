/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:50 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/03 15:09:46 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

void	release_all_lst_tests(t_lst_test *tests)
{
	free_numeric_lst_tests(tests);
	free_non_numeric_lst_tests(tests);
}

void	free_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->shorts)
		free_shorts(tests);
	if (tests->ushorts)
		free_ushorts(tests);
	if (tests->ints)
		free_ints(tests);
	if (tests->uints)
		free_uints(tests);
	if (tests->longs)
		free_longs(tests);
	if (tests->ulongs)
		free_ulongs(tests);
	if (tests->lls)
		free_lls(tests);
	if (tests->ulls)
		free_ulls(tests);
	if (tests->floats)
		free_floats(tests);
	if (tests->doubles)
		free_doubles(tests);
	if (tests->ldoubles)
		free_ldoubles(tests);
}

void	free_non_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->chars)
		free_chars(tests);
	if (tests->uchars)
		free_uchars(tests);
	if (tests->strs)
		free_strings(tests);
	if (tests->voids)
		free_voids(tests);
}

void	free_list_debug(t_lst_d *list)
{
	if (list->types != NULL)
	{
		free(list->types);
		list->types = NULL;
	}
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}
