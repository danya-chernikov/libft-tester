/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_parser2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:47 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 18:37:25 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* It checks if the user specified the arguments correctly when the command
 * type belongs to the group of commands that require two arguments */
int	user_passed_args_crtly(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	if (!strcmp(cmd->type, CMD_NEW) || !strcmp(cmd->type, CMD_ADDFRONT)
		|| !strcmp(cmd->type, CMD_ADDBACK))
	{
		if (substrs[1][0] == '\0')
		{
			printf("parse_user_input(): You must specify an argument type\n");
			return (ERROR);
		}
		if (substrs[2][0] == '\0')
		{
			printf("parse_user_input(): You forgot to specify an argument\n");
			return (ERROR);
		}
		if (strlen(substrs[1]) > MAX_CMD_ARG_TYPE_LEN)
		{
			printf("parse_user_input(): The argument type is invaild\n");
			return (ERROR);
		}
		if (strlen(substrs[2]) > MAX_CMD_ARG_LEN)
		{
			printf("parse_user_input(): The argument exceeds maximum length\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

/* It checks if the argument type
 * specified by the user is correct */
int	arg_type_is_valid(t_cmd *cmd)
{
	if (strcmp(cmd->arg_type, AT_CHAR)
		&& strcmp(cmd->arg_type, AT_UCHAR)
		&& strcmp(cmd->arg_type, AT_SHORT)
		&& strcmp(cmd->arg_type, AT_USHORT)
		&& strcmp(cmd->arg_type, AT_INT)
		&& strcmp(cmd->arg_type, AT_UINT)
		&& strcmp(cmd->arg_type, AT_LONG)
		&& strcmp(cmd->arg_type, AT_ULONG)
		&& strcmp(cmd->arg_type, AT_LONGLONG)
		&& strcmp(cmd->arg_type, AT_ULONGLONG)
		&& strcmp(cmd->arg_type, AT_FLOAT)
		&& strcmp(cmd->arg_type, AT_DOUBLE)
		&& strcmp(cmd->arg_type, AT_LONGDOUBLE)
		&& strcmp(cmd->arg_type, AT_STRING))
	{
		printf("parse_user_input(): Argument type is invalid\n");
		return (ERROR);
	}
	return (SUCCESS);
}

/* If the user entered a command that require only one argument (an argument
 * value which represents a node number) this function checks if this its
 * value has the correct form or not */
int	single_arg_cmd_is_crt(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	if ((strcmp(cmd->type, CMD_CLEAR) == 0)
		|| (strcmp(cmd->type, CMD_DEL) == 0))
	{
		if (strlen(substrs[1]) > MAX_CMD_ARG_LEN)
		{
			printf("parse_user_input(): This value can "
				"not be a node number or an address\n");
			return (ERROR);
		}
		if (substrs[1][0] == '\0')
		{
			printf("parse_user_input(): You forgot to "
				" specify either a node number or an address\n");
			return (ERROR);
		}
		else
			return (SINGLE_ARG_CMD);
	}
	return (SUCCESS);
}

void	nullify_cmd_fields(t_cmd *cmd)
{
	cmd->type[0] = '\0';
	cmd->arg[0] = '\0';
	cmd->arg_type[0] = '\0';
}
