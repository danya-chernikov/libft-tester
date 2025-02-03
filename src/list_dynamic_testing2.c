#include "../include/list.h"

int	proc_user_cmd5(t_cmd *cmd, t_lst_d **list)
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
