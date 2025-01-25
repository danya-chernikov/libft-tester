#include "../include/list.h"

/* It takes the full command entered by the user and separates the command
 * type from its operand (argument), placing this data into the corresponding
 * arrays. If an error occurs during the parsing process, the function returns
 * 0, meaning that the user entered an invalid command or its format was
 * incorrect */
int	parse_user_input(char *buf, char *cmd_type, char *arg_type, char *arg)
{
	int	i;
	int	j;

	// Trying to determine command type
	i = 0;
	while (i < strlen(buf) && buf[i] != ' ' && i < MAX_CMD_TYPE_LEN)
	{
		cmd_type[i] = buf[i];
		i++;
	}
	cmd_type[i] = '\0';
	if (i == strlen(buf))
	{
		// These commands do not require any argument
		if ((strcmp(cmd_type, CMD_MAN) == 0) ||
			(strcmp(cmd_type, CMD_QUIT) == 0) ||
			(strcmp(cmd_type, CMD_SIZE) == 0) ||
			(strcmp(cmd_type, CMD_LAST) == 0) ||
			(strcmp(cmd_type, CMD_PRINT) == 0))
		{
			arg_type[0] = '\0';
			arg[0] = '\0';
			return (SUCCESS);
		}
		else
			return (ERROR);
	}

	if (i == MAX_CMD_TYPE_LEN)
		return (ERROR);

	// Checking if command type is valid
	if ((strcmp(cmd_type, CMD_NEW) != 0) &&
		(strcmp(cmd_type, CMD_ADDFRONT) != 0) &&
		(strcmp(cmd_type, CMD_ADDBACK) != 0))
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
		arg_type[j] = buf[i];
		i++;
		j++;
	}
	arg_type[j] = '\0';

	while (buf[i] == ' ')
		i++;
	if (i == strlen(buf))
		return (ERROR);

	// Checking if the argument type is valid
	if ((strcmp(arg_type, AT_CHAR) != 0) &&
		(strcmp(arg_type, AT_UCHAR) != 0) &&
		(strcmp(arg_type, AT_SHORT) != 0) &&
		(strcmp(arg_type, AT_USHORT) != 0) &&
		(strcmp(arg_type, AT_INT) != 0) &&
		(strcmp(arg_type, AT_UINT) != 0) &&
		(strcmp(arg_type, AT_LONG) != 0) &&
		(strcmp(arg_type, AT_ULONG) != 0) &&
		(strcmp(arg_type, AT_LONGLONG) != 0) &&
		(strcmp(arg_type, AT_ULONGLONG) != 0) &&
		(strcmp(arg_type, AT_FLOAT) != 0) &&
		(strcmp(arg_type, AT_DOUBLE) != 0) &&
		(strcmp(arg_type, AT_LONGDOUBLE) != 0) &&
		(strcmp(arg_type, AT_STRING) != 0))
	{
		return (ERROR);
	}

	// Trying to determine the argument
	j = 0;
	while (i < strlen(buf) && j < MAX_CMD_ARG_LEN)
	{
		arg[j] = buf[i];
		i++;
		j++;
	}
	arg[j] = '\0';
	
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
