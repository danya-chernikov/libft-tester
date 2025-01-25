#include "../include/list.h"

int	proc_cmd_print(t_lst_d *l, t_lst_test *t, char *arg, char *arg_type)
{
	printf("process_cmd_print()\n");
	return (SUCCESS);
}

int	proc_cmd_quit(t_lst_d *l, t_lst_test *t, char *arg, char *arg_type)
{
	printf("process_cmd_quit()\n");
	return (SUCCESS);
}
