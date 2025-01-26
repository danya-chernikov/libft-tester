#include "../include/list.h"

static int	proc_cmd_af1(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_af2(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_af3(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_af4(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);

int	process_cmd_addfront(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_addfront()\n");
	t_cnt_type	data_type;

	data_type = determine_data_type(command->arg_type);
	if (proc_cmd_af1(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_af2(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_af3(list, tests, command, data_type) == ERROR)
		return (ERROR);
	if (proc_cmd_af4(list, tests, command, data_type) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

static int	proc_cmd_af1(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == CHAR)
	{
		if (lstaddfront_char(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_CHAR)
	{
		if (lstaddfront_uchar(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == SHORT)
	{
		if (lstaddfront_short(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_SHORT)
	{
		if (lstaddfront_ushort(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af2(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == INT)
	{
		if (lstaddfront_int(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_INT)
	{
		if (lstaddfront_uint(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == LONG)
	{
		if (lstaddfront_long(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG)
	{
		if (lstaddfront_ulong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af3(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_LONG)
	{
		if (lstaddfront_longlong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG_LONG)
	{
		if (lstaddfront_ulonglong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == FLOAT)
	{
		if (lstaddfront_float(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == DOUBLE)
	{
		if (lstaddfront_double(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af4(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_DOUBLE)
	{
		if (lstaddfront_longdouble(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == STRING)
	{
		if (lstaddfront_string(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == INVALID_TYPE)
	{
		printf("process_cmd_addfront(): You entered an invalid argument\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	process_cmd_last(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_last()\n");
	return (SUCCESS);
}

int	process_cmd_addback(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_addback()\n");
	return (SUCCESS);
}

int	process_cmd_clear(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_clear()\n");
	return (SUCCESS);
}
