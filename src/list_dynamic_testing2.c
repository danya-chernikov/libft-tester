#include "../include/list.h"

int	proc_user_cmd5(t_cmd *c, t_lst_d **l)
{
	if (!strcmp(c->type, CMD_PRINT))
	{
		print_list(*l, 0);
	}
	if (!strcmp(c->type, CMD_QUIT))
	{
		return (SIGNAL_QUIT);
	}
	return (SUCCESS);
}
