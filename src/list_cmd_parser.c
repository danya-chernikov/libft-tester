/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:20:45 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/03 14:52:44 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* It takes the full command entered by the
 * user and separates the command type from
 * its operand (argument), placing this data
 * into the corresponding arrays. If an error
 * occurs during the parsing process, the
 * function returns 0, meaning that the user
 * entered an invalid command or its format was
 * incorrect. A command may take these forms:
 *
 * substrs[0]   substrs[1]         substrs[2]
 * [COMMAND]    [ARGUMENT_TYPE]    [ARGUMENT]
 *     new          CHAR		       a
 *     addfront     U_CHAR             'b'
 *     addback      SHORT              128
 *					...
 *					STRING			   justastring
 *					STRING             "lol kek cheburek"
 *
 * or
 *
 * substrs[0]   substrs[1]
 * [COMMAND]    [ARGUMENT]
 *     clear        5
 *     del          6
 *     clear		0x555555575730
 *     del			0x555555575a10
 *
 *
 * or just
 *
 * substrs[0]
 * [COMMAND]
 *     man
 *     quit
 *     size
 *     last
 *     iter
 *     map
 *     print
 * */
int	parse_user_input(char *buf, t_cmd *cmd)
{
	char	substrs[MAX_CMD_SUBSTR_NUM][MAX_CMD_SUBSTR_LEN];
	int		res;

	nullify_cmd_fields(cmd);
	split_string_by_spaces(buf, substrs);
	res = check_no_arg_cmd(substrs);
	if (res == ERROR)
		return (ERROR);
	else
	{
		strncpy(cmd->type, substrs[0], MAX_CMD_TYPE_LEN - 1);
		if (res == NO_ARG_CMD)
			return (SUCCESS);
	}
	if (!multi_arg_cmd(cmd))
		return (ERROR);
	if (!user_passed_args_crtly(cmd, substrs))
		return (ERROR);
	strncpy(cmd->arg_type, substrs[1], MAX_CMD_ARG_TYPE_LEN - 1);
	strncpy(cmd->arg, substrs[2], MAX_CMD_ARG_LEN - 1);
	if (check_single_arg(cmd, substrs) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	check_single_arg(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	int	res;

	res = single_arg_cmd_is_crt(cmd, substrs);
	if (res == ERROR)
		return (ERROR);
	else if (res == SINGLE_ARG_CMD)
	{
		cmd->arg_type[0] = '\0';
		strncpy(cmd->arg, substrs[1], MAX_CMD_ARG_LEN - 1);
	}
	else
	{
		if (!arg_type_is_valid(cmd))
			return (ERROR);
	}
	return (SUCCESS);
}

/* It splits the string str by spaces and stores each substring in the
 * array of pointers to substrings, substrs. It splits only the first
 * three substrings found. If the original string str contains fewer
 * than three space-separated substrings, the remaining cells of the
 * substrs array will contain empty strings */
void	split_string_by_spaces(char *str, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	int		si;
	int		j;
	size_t	i;

	substrs[0][0] = '\0';
	substrs[1][0] = '\0';
	substrs[2][0] = '\0';
	si = 0;
	i = 0;
	while (si < 3)
	{
		j = 0;
		while ((str[i] != ' ') && (i < strlen(str)))
		{
			substrs[si][j] = str[i];
			i++;
			j++;
		}
		substrs[si][j] = '\0';
		while ((str[i] == ' ') && (i < strlen(str)))
			i++;
		if (i == strlen(str))
			break ;
		si++;
	}
}

/* It checks if the entered command belongs to the type of commands
 * that do not require arguments. If so, it checks whether any
 * arguments were specified and, if so, returns an error */
int	check_no_arg_cmd(char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	if (substrs[0][0] == '\0' || strlen(substrs[0]) > MAX_CMD_TYPE_LEN)
	{
		printf("parse_user_input(): Unknown command\n");
		return (ERROR);
	}
	if (!strcmp(substrs[0], CMD_MAN)
		|| !strcmp(substrs[0], CMD_QUIT)
		|| !strcmp(substrs[0], CMD_SIZE)
		|| !strcmp(substrs[0], CMD_LAST)
		|| !strcmp(substrs[0], CMD_PRINT)
		|| !strcmp(substrs[0], CMD_ITER)
		|| !strcmp(substrs[0], CMD_MAP))
	{
		if ((substrs[1][0] != '\0') || (substrs[2][0] != '\0'))
		{
			printf("parse_user_input(): This command does"
				" not require any arguments\n");
			return (ERROR);
		}
		else
		{
			return (NO_ARG_CMD);
		}
	}
	return (SUCCESS);
}

/* It checks if the entered
 * command cmd belongs to the
 * group of commands that
 * require at least one argument
 * to work correctly. If cmd
 * does not belong to this group,
 * it returns an error */
int	multi_arg_cmd(t_cmd *cmd)
{
	if ((strcmp(cmd->type, CMD_NEW) != 0)
		&& (strcmp(cmd->type, CMD_ADDFRONT) != 0)
		&& (strcmp(cmd->type, CMD_ADDBACK) != 0)
		&& (strcmp(cmd->type, CMD_CLEAR) != 0)
		&& (strcmp(cmd->type, CMD_DEL) != 0))
	{
		printf("parse_user_input(): Unknown command\n");
		return (ERROR);
	}
	return (SUCCESS);
}
