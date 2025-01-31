#include "../include/list.h"

static int	proc_cmd_ab1(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_ab2(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_ab3(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_ab4(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);

int	process_cmd_addback(t_lst_d **list, t_lst_test *tests, t_cmd *command)
{
	t_cnt_type	data_type;

	data_type = determine_data_type(command->arg_type);
	if (proc_cmd_ab1(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_ab2(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_ab3(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_ab4(list, tests, command, data_type) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	proc_cmd_ab1(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == CHAR)
	{
		if (lstaddback_char(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_CHAR)
	{
		if (lstaddback_uchar(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == SHORT)
	{
		if (lstaddback_short(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_SHORT)
	{
		if (lstaddback_ushort(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_ab2(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == INT)
	{
		if (lstaddback_int(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_INT)
	{
		if (lstaddback_uint(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == LONG)
	{
		if (lstaddback_long(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG)
	{
		if (lstaddback_ulong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_ab3(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_LONG)
	{
		if (lstaddback_longlong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG_LONG)
	{
		if (lstaddback_ulonglong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == FLOAT)
	{
		if (lstaddback_float(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == DOUBLE)
	{
		if (lstaddback_double(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_ab4(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_DOUBLE)
	{
		if (lstaddback_longdouble(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == STRING)
	{
		if (lstaddback_string(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == INVALID_TYPE)
	{
		printf("process_cmd_addback(): You entered an invalid argument\n");
		return (ERROR);
	}
	return (SUCCESS);
}
