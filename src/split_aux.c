/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:30:06 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:30:08 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/split.h"
#include <stddef.h>
#include <stdlib.h>

void	split_free(char ***res)
{
	size_t	i;

	i = 0;
	while ((*res)[i])
	{
		free((*res)[i]);
		i++;
	}
	free(*res);
}
