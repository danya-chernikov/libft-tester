/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_dynamic_testing.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:48 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/03 15:52:29 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* It performs dynamic testing of singly linked lists. It means
 * the user will have ability to construct thier own list using
 * predefined command set, entering each command in the loop
 * manually.
 *     lcrt - a flag indicating whether a list was created or not */
void	linked_list_launch_dynamic_testing(t_lst_test *tests)
{
	char		cmd_buf[MAX_USER_INPUT_BUF_LEN];
	t_lst_d		*list;
	bool		lcrt;
	t_cmd		cmd;

	list = NULL;
	lcrt = false;
	fgets(cmd_buf, MAX_USER_INPUT_BUF_LEN, stdin);
	while (true)
	{
		get_user_command(cmd_buf);
		if (parse_user_input(cmd_buf, &cmd) == ERROR)
		{
			printf("You entered an incorrect command. Please try again.\n");
			continue ;
		}
		if ((proc_user_cmd1(&cmd, &list, tests, &lcrt) == ERROR)
			|| (proc_user_cmd2(&cmd, &list, tests, &lcrt) == ERROR)
			|| (proc_user_cmd3(&cmd, &list, tests, &lcrt) == ERROR)
			|| (proc_user_cmd4(&cmd, &list, tests, &lcrt) == ERROR))
			continue ;
		if (proc_user_cmd5(&cmd, &list) == SIGNAL_QUIT)
			break ;
	}
	if (lcrt)
		free_list_debug(list);
}

int	proc_user_cmd1(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if (strcmp(c->type, CMD_MAN) == 0)
	{
		lst_print_man();
	}
	if (strcmp(c->type, CMD_NEW) == 0)
	{
		if (*lcrt == true)
		{
			printf("A list had aleady been created.\n");
			return (ERROR);
		}
		else
		{
			if (process_cmd_new(l, t, c) == ERROR)
				return (ERROR);
			else
				*lcrt = true;
		}
	}
	return (SUCCESS);
}

int	proc_user_cmd2(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if (strcmp(c->type, CMD_ADDFRONT) == 0)
	{
		if (*lcrt == true)
		{
			if (process_cmd_addfront(l, t, c) == ERROR)
				return (ERROR);
		}
		else
		{
			printf("Before working with a list, it must be created.\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

int	proc_user_cmd3(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if ((!strcmp(c->type, CMD_SIZE)
			|| !strcmp(c->type, CMD_LAST)
			|| !strcmp(c->type, CMD_ADDBACK)) && (*lcrt == false))
	{
		printf("Before working with a list, it must be created.\n");
		return (ERROR);
	}
	if (!strcmp(c->type, CMD_SIZE))
	{
		lstsize_test(&(*l)->head);
	}
	if (!strcmp(c->type, CMD_LAST))
	{
		lstlast_test(*l);
	}
	if (!strcmp(c->type, CMD_ADDBACK))
	{
		if (process_cmd_addback(l, t, c) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

int	proc_user_cmd4(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if ((!strcmp(c->type, CMD_CLEAR) || !strcmp(c->type, CMD_DEL)
			|| !strcmp(c->type, CMD_PRINT) || !strcmp(c->type, CMD_ITER)
			|| !strcmp(c->type, CMD_MAP)) && (*lcrt == false))
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
	if (!strcmp(c->type, CMD_ITER))
	{
		lstiter_test((*l)->head, iter_func1);
	}
	return (SUCCESS);
}
