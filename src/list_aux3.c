#include "../include/list.h"

int	parse_cmd_type(char *buf, t_cmd *command, int *i)
{
	*i = 0;
	while ((*i < strlen(buf)) && (buf[*i] != ' ') && (*i < MAX_CMD_TYPE_LEN))
	{
		cmd->type[*i] = buf[*i];
		(*i)++;
	}
	cmd->type[*i] = '\0';
	if (*i == strlen(buf))
	{
		if ((strcmp(cmd->type, CMD_MAN) == 0)
			|| (strcmp(cmd->type, CMD_QUIT) == 0)
			|| (strcmp(cmd->type, CMD_SIZE) == 0)
			|| (strcmp(cmd->type, CMD_LAST) == 0)
			|| (strcmp(cmd->type, CMD_PRINT) == 0))
		{
			cmd->arg_type[0] = '\0';
			cmd->arg[0] = '\0';
			return (SUCCESS);
		}
		else
			return (ERROR);
	}
	return (SUCCESS);
}

/* The 'clear' command can accept only one argument without requiring
 * its type to be specified. If the command type is 'clear', this
 * function takes its argument (a node number indicating where to
 * start clearing the list) and returns 1, signaling to the caller
 * to terminate parsing successfully. Otherwise, it returns 0,
 * indicating to the caller to continue parsing. */
int	check_if_cmd_is_clear(char *buf, t_cmd *command, int *i, int *j)
{
	if (strcmp(cmd->type, CMD_CLEAR) == 0)
	{
		cmd->arg_type[0] = '\0';
		*j = 0;
		while ((*i < strlen(buf)) && (*j < MAX_CMD_ARG_LEN))
		{
			cmd->arg[*j] = buf[*i];
			(*i)++;
			(*j)++;
		}
		cmd->arg[*j] = '\0';
		return (1);
	}
	else
		return (0);	
}

void	split_string_by_spaces(char *str, char *substrs)
{
	int	i;
	int	j;

	i = 0;
	while ((str[i] != ' ') && (i < strlen(str)))
	{
		part1[i] = str[i];
		i++;
	}
	if (i == strlen(str))
	{
		part2[0] = '\0';
		part3[0] = '\0';
		return ;
	}
	while ((str[i] == ' ') && (i < strlen(str)))
		i++;
	if (i == strlen(str))
		return ;
	j = 0;
	while ((str[i] != ' ') && (i < strlen(str)))
	{
		part2[]
	}
}

/* It takes the full command entered by the
 * user and separates the command type from
 * its operand (argument), placing this data
 * into the corresponding arrays. If an error
 * occurs during the parsing process, the
 * function returns 0, meaning that the user
 * entered an invalid command or its format was
 * incorrect. A command may take these forms:
 * [COMMAND] [ARGUMENT] [ARGUMENT_TYPE]
 * or
 * [COMMAND] [ARGUMENT]
 * or just
 * [COMMAND] */
int	parse_user_input(char *buf, t_cmd *command)
{
	int	i;
	int	j;

	if (parse_cmd_type(buf, command, &i) == ERROR)
		return (ERROR);
	if (check_if_cmd_is_clear(buf, command, &i, &j))
		return (SUCCESS);

	if (cmd_type_is_valid())
	{

	}
	// Checking if command type is valid
	if ((strcmp(cmd->type, CMD_NEW) != 0)
		&& (strcmp(cmd->type, CMD_ADDFRONT) != 0)
		&& (strcmp(cmd->type, CMD_ADDBACK) != 0))
	{
		return (ERROR);
	}
	
	// If we are here the delimiter was a
	// space (or several consequtive spaces)
	while (buf[i] == ' ')
		i++;
	if (i == strlen(buf))
		return (ERROR);

	// Trying to determine the argument type
	j = 0;
	while (i < strlen(buf) && buf[i] != ' ' && j < MAX_CMD_ARG_TYPE_LEN)
	{
		cmd->arg_type[j] = buf[i];
		i++;
		j++;
	}
	cmd->arg_type[j] = '\0';

	while (buf[i] == ' ')
		i++;
	if (i == strlen(buf))
		return (ERROR);

	// Checking if the argument type is valid
	if ((strcmp(cmd->arg_type, AT_CHAR) != 0) &&
		(strcmp(cmd->arg_type, AT_UCHAR) != 0) &&
		(strcmp(cmd->arg_type, AT_SHORT) != 0) &&
		(strcmp(cmd->arg_type, AT_USHORT) != 0) &&
		(strcmp(cmd->arg_type, AT_INT) != 0) &&
		(strcmp(cmd->arg_type, AT_UINT) != 0) &&
		(strcmp(cmd->arg_type, AT_LONG) != 0) &&
		(strcmp(cmd->arg_type, AT_ULONG) != 0) &&
		(strcmp(cmd->arg_type, AT_LONGLONG) != 0) &&
		(strcmp(cmd->arg_type, AT_ULONGLONG) != 0) &&
		(strcmp(cmd->arg_type, AT_FLOAT) != 0) &&
		(strcmp(cmd->arg_type, AT_DOUBLE) != 0) &&
		(strcmp(cmd->arg_type, AT_LONGDOUBLE) != 0) &&
		(strcmp(cmd->arg_type, AT_STRING) != 0))
	{
		return (ERROR);
	}

	// Trying to determine the argument
	j = 0;
	while (i < strlen(buf) && j < MAX_CMD_ARG_LEN)
	{
		cmd->arg[j] = buf[i];
		i++;
		j++;
	}
	cmd->arg[j] = '\0';
	
	return (SUCCESS);
}

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
			break;
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
			break;
		}
		i++;
	}
	return (was_freed);
}

/* It just gets line from the
 * standard input and puts it
 * into `str` array */
void	get_line(char *str)
{
	int	ch;
	int	i;

	i = 0;
	while (i < MAX_USER_INPUT_BUF_LEN)
	{
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			break ;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
}
