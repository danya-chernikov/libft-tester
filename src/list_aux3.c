/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_aux3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:16:09 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 16:31:52 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

bool	cnt_was_freed(void *cnt, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = false;
	while (i < tests->nodes_num_to_free)
	{
		if (cnt == tests->cnts_to_free[i])
		{
			was_freed = true;
			break ;
		}
		i++;
	}
	return (was_freed);
}

bool	node_was_freed(void *node, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = false;
	while (i < tests->nodes_num_to_free)
	{
		if (node == tests->nodes_to_free[i])
		{
			was_freed = true;
			break ;
		}
		i++;
	}
	return (was_freed);
}

/* It just gets line from the
 * standard input and puts it
 * into `str` array */
void	get_user_command(char *buf)
{
	printf("\nEnter command ('man' for help): ");
	fgets(buf, MAX_USER_INPUT_BUF_LEN, stdin);
	printf("\n");
	buf[strcspn(buf, "\n")] = '\0';
}
