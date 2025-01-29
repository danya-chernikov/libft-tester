#include "../include/list.h"

int	arg_type_is_valid(t_cmd *cmd)
{
	if ((strcmp(cmd->arg_type, AT_CHAR) != 0)
		&& (strcmp(cmd->arg_type, AT_UCHAR) != 0)
		&& (strcmp(cmd->arg_type, AT_SHORT) != 0)
		&& (strcmp(cmd->arg_type, AT_USHORT) != 0)
		&& (strcmp(cmd->arg_type, AT_INT) != 0)
		&& (strcmp(cmd->arg_type, AT_UINT) != 0)
		&& (strcmp(cmd->arg_type, AT_LONG) != 0)
		&& (strcmp(cmd->arg_type, AT_ULONG) != 0)
		&& (strcmp(cmd->arg_type, AT_LONGLONG) != 0)
		&& (strcmp(cmd->arg_type, AT_ULONGLONG) != 0)
		&& (strcmp(cmd->arg_type, AT_FLOAT) != 0)
		&& (strcmp(cmd->arg_type, AT_DOUBLE) != 0)
		&& (strcmp(cmd->arg_type, AT_LONGDOUBLE) != 0)
		&& (strcmp(cmd->arg_type, AT_STRING) != 0))
	{
		printf("parse_user_input(): Argument type is invalid\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	one_arg_cmd_is_correct(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN])
{

	if ((strcmp(cmd->type, CMD_CLEAR) == 0)
		|| (strcmp(cmd->type, CMD_DEL) == 0))
	{
		if (strlen(substrs[1][0]) > MAX_CMD_ARG_LEN)
		{
			printf("parse_user_input(): This value can not be a node number\n");
			return (ERROR);
		}
		if (substrs[1][0] == '\0')
		{
			printf("parse_user_input(): You forgot to specify a node number\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}
