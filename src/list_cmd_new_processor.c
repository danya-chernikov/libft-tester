#include "../include/list.h"

static int	proc_cmd_new1(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new2(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new3(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new4(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type);

int	process_cmd_new(t_lst_d **list, t_lst_test *tests, t_cmd *command)
{
	t_cnt_type	data_type;

	data_type = determine_data_type(command->arg_type);
	if (proc_cmd_new1(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_new2(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_new3(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_new4(list, tests, command, data_type) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	proc_cmd_new1(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == CHAR)
	{
		if (lstnew_char(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_CHAR)
	{
		if (lstnew_uchar(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == SHORT)
	{
		if (lstnew_short(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_SHORT)
	{
		if (lstnew_ushort(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new2(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == INT)
	{
		if (lstnew_int(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_INT)
	{
		if (lstnew_uint(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == LONG)
	{
		if (lstnew_long(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG)
	{
		if (lstnew_ulong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new3(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_LONG)
	{
		if (lstnew_longlong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG_LONG)
	{
		if (lstnew_ulonglong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == FLOAT)
	{
		if (lstnew_float(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == DOUBLE)
	{
		if (lstnew_double(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new4(t_lst_d **l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_DOUBLE)
	{
		if (lstnew_longdouble(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == STRING)
	{
		if (lstnew_string(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == INVALID_TYPE)
	{
		printf("process_cmd_new(): You entered an invalid argument\n");
		return (ERROR);
	}
	return (SUCCESS);
}
