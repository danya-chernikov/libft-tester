/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dynamic_testing2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:36:29 by dchernik          #+#    #+#             */
/*   Updated: 2025/05/04 22:00:11 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* lcrt - list creation flag */
int	proc_user_cmd4(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if ((!strcmp(c->type, CMD_CLEAR) || !strcmp(c->type, CMD_DEL)
			|| !strcmp(c->type, CMD_PRINT) || !strcmp(c->type, CMD_ITER)
			|| !strcmp(c->type, CMD_MAP) || !strcmp(c->type, CMD_REMOVE_IF)
			|| !strcmp(c->type, CMD_SORT)) && (*lcrt == false))
	{
		printf("Before working with a list, it must be created.\n");
		return (ERROR);
	}
	if (!strcmp(c->type, CMD_CLEAR))
	{
		if (process_cmd_clear(l, t, c, lcrt) == ERROR)
			return (ERROR);
	}
	if (!strcmp(c->type, CMD_DEL))
	{
		if (process_cmd_del(l, t, c, lcrt) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	proc_user_cmd5(t_cmd *c, t_lst_d **l)
{
	if (!strcmp(c->type, CMD_REMOVE_IF))
	{
		list_remove_if_test(&(*l)->head);
	}
	if (!strcmp(c->type, CMD_SORT))
	{
		//list_sort_test();
	}
	return (SUCCESS);
}

int	proc_user_cmd6(t_cmd *cmd, t_lst_d **list)
{
	if (!strcmp(cmd->type, CMD_ITER))
	{
		lstiter_test((*list)->head, lstiter_func1);
	}
	if (!strcmp(cmd->type, CMD_MAP))
	{
		process_cmd_map(list);
	}
	if (!strcmp(cmd->type, CMD_PRINT))
	{
		print_list(*list, 0);
	}
	if (!strcmp(cmd->type, CMD_QUIT))
	{
		return (SIGNAL_QUIT);
	}
	return (SUCCESS);
}
