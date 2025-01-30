#include "../include/list.h"

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
int single_arg_cmd_is_crt(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{
	if ((strcmp(cmd->type, CMD_CLEAR) == 0)
		|| (strcmp(cmd->type, CMD_DEL) == 0))
	{
		if (strlen(substrs[1]) > MAX_CMD_ARG_LEN)
		{
			printf("parse_user_input(): This value can not be a node number\n");
			return (ERROR);
		}
		if (substrs[1][0] == '\0')
		{
			printf("parse_user_input(): You forgot to specify a node number\n");
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
