/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_testing_funcs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:31 by dchernik          #+#    #+#             */
/*   Updated: 2025/05/04 20:14:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* This function is used to test how
 * the ft_lstiter() function works */
void	lstiter_func1(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = toupper(((char *)node_cnt)[i]);
		i++;
	}
}

/* This function is used to test how
 * the ft_lstiter() function works */
void	lstiter_func2(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = tolower(((char *)node_cnt)[i]);
		i++;
	}
}

/* This function is used to test how
 * the ft_lstmap() function works */
void	*lstmap_func1(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = toupper(((char *)node_cnt)[i]);
		i++;
	}
	return (node_cnt);
}

/* This function is used to test how
 * the ft_lstiter() function works */
void	*lstmap_func2(void *node_cnt)
{
	size_t	i;

	i = 0;
	while (i < strlen((char *)node_cnt))
	{
		((char *)node_cnt)[i] = tolower(((char *)node_cnt)[i]);
		i++;
	}
	return (node_cnt);
}
