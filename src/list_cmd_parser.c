#include "../include/list.h"

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
int	parse_user_input(char *buf, t_cmd *cmd)
{
	char	substrs[MAX_CMD_SUBSTR_NUM][MAX_CMD_SUBSTR_LEN];

	split_string_by_spaces(buf, substrs);
	if (!check_no_arg_cmd(substrs))
		return (ERROR);
	strncpy(cmd->type, substrs[0], MAX_CMD_TYPE_LEN - 1);
	if (!cmd_type_is_valid(cmd))
		return (ERROR);
	if (!user_passed_args_crtly(cmd, substrs))
		return (ERROR);
	strncpy(cmd->arg_type, substrs[1], MAX_CMD_ARG_TYPE_LEN - 1);
	strncpy(cmd->arg, substrs[2], MAX_CMD_ARG_LEN - 1);
	if (!arg_type_is_valid(cmd))
		return (ERROR);
	if (!one_arg_cmd_is_correct(cmd, substrs))
		return (ERROR);
	strncpy(cmd->arg, substrs[1], MAX_CMD_ARG_LEN - 1);
	return (SUCCESS);
}

void    split_string_by_spaces(char *str, char (*substrs)[MAX_CMD_SUBSTR_LEN])
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
	if (substrs[0][0] == '\0')
	{
		printf("parse_user_input(): You have to enter a command\n");
		return (ERROR);
	}
	if (strlen(substrs[0]) > MAX_CMD_TYPE_LEN)
	{
		printf("parse_user_input(): Unknown command\n");
		return (ERROR);
	}
	if ((strcmp(substrs[0], CMD_MAN) == 0)
		|| (strcmp(substrs[0], CMD_QUIT) == 0)
		|| (strcmp(substrs[0], CMD_SIZE) == 0)
		|| (strcmp(substrs[0], CMD_LAST) == 0)
		|| (strcmp(substrs[0], CMD_PRINT) == 0))
	{
		if ((substrs[1][0] != '\0') || (substrs[2][0] != '\0'))
		{
			printf("parse_user_input(): This command does"
				" not require any argument\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

/* It checks if the entered command type
 * is valid. If not, it returns an error */
int	cmd_type_is_valid(t_cmd *cmd)
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
