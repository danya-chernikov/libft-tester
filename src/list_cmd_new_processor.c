#include "../include/list.h"

static int	proc_cmd_new1(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new2(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new3(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);
static int	proc_cmd_new4(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type);

int	process_cmd_new(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_new()\n");
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

static int	proc_cmd_new1(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == CHAR)
	{
		printf("type = CHAR\n");
		if (lstnew_char(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_CHAR)
	{
		printf("type = U_CHAR\n");
		if (lstnew_uchar(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == SHORT)
	{
		printf("type = SHORT\n");
		if (lstnew_short(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_SHORT)
	{
		printf("type = U_SHORT\n");
		if (lstnew_ushort(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new2(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == INT)
	{
		printf("type = INT\n");
		if (lstnew_int(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_INT)
	{
		printf("type = U_INT\n");
		if (lstnew_uint(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == LONG)
	{
		printf("type = LONG\n");
		if (lstnew_long(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG)
	{
		printf("type = U_LONG\n");
		if (lstnew_ulong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new3(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_LONG)
	{
		printf("type = LONG_LONG\n");
		if (lstnew_longlong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG_LONG)
	{
		printf("type = U_LONG_LONG\n");
		if (lstnew_ulonglong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == FLOAT)
	{
		printf("type = FLOAT\n");
		if (lstnew_float(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == DOUBLE)
	{
		printf("type = DOUBLE\n");
		if (lstnew_double(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_new4(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_DOUBLE)
	{
		printf("type = LONG_DOUBLE\n");
		if (lstnew_longdouble(l, t c->arg) == ERROR)
			return (ERROR);
	}
	if (type == STRING)
	{
		printf("type = STRING\n");
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
