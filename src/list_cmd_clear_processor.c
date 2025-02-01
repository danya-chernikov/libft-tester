/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_clear_processor.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:19:34 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 19:44:23 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

int	process_cmd_clear(t_lst_d **list, t_lst_test *tests, t_cmd *cmd, bool *lcrt)
{
	t_list	*node;
	int		node_num;

	node_num = atoi(cmd->arg);
	if ((node_num < 0) || (node_num > lstsize(*list->head) - 1))
		return (ERROR);
	node = get_node(*list, node_num);
	if (node != NULL)
		lstclear_test(*list, &node, del, tests);
	if (node_num == 0)
		*lcrt = false;
	return (SUCCESS);
}
