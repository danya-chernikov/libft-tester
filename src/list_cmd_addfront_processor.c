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
		printf("type = CHAR\n");
		if (lstaddfront_char(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_CHAR)
	{
		printf("type = U_CHAR\n");
		if (lstaddfront_uchar(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == SHORT)
	{
		printf("type = SHORT\n");
		if (lstaddfront_short(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_SHORT)
	{
		printf("type = U_SHORT\n");
		if (lstaddfront_ushort(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af2(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == INT)
	{
		printf("type = INT\n");
		if (lstaddfront_int(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_INT)
	{
		printf("type = U_INT\n");
		if (lstaddfront_uint(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == LONG)
	{
		printf("type = LONG\n");
		if (lstaddfront_long(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG)
	{
		printf("type = U_LONG\n");
		if (lstaddfront_ulong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af3(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_LONG)
	{
		printf("type = LONG_LONG\n");
		if (lstaddfront_longlong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == U_LONG_LONG)
	{
		printf("type = U_LONG_LONG\n");
		if (lstaddfront_ulonglong(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == FLOAT)
	{
		printf("type = FLOAT\n");
		if (lstaddfront_float(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == DOUBLE)
	{
		printf("type = DOUBLE\n");
		if (lstaddfront_double(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_cmd_af4(t_lst_d *l, t_lst_test *t, t_cmd *c, t_cnt_type type)
{
	if (type == LONG_DOUBLE)
	{
		printf("type = LONG_DOUBLE\n");
		if (lstaddfront_longdouble(l, t, c->arg) == ERROR)
			return (ERROR);
	}
	if (type == STRING)
	{
		printf("type = STRING\n");
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
