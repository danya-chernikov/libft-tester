/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_free5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:21:29 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:21:36 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

void	free_strs_ptrs(t_lst_test *tests)
{
	int	i;

	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->strs_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->strs_ptrs[i], tests))
			{
				free(tests->strs_ptrs[i]);
				tests->strs_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->strs_ptrs != NULL)
	{
		free(tests->strs_ptrs);
		tests->strs_ptrs = NULL;
	}
}

void	free_voids(t_lst_test *tests)
{
	int	i;

	if (tests->voids != NULL)
	{
		free(tests->voids);
		tests->voids = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->voids_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->voids_ptrs[i], tests))
			{
				free(tests->voids_ptrs[i]);
				tests->voids_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->voids_ptrs != NULL)
	{
		free(tests->voids_ptrs);
		tests->voids_ptrs = NULL;
	}
}
