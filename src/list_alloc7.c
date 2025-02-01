/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_alloc7.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:15:25 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:15:26 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

char	*alloc_string(char *val)
{
	return (strndup(val, MAX_LST_TEST_STR_LEN));
}
