#include "../include/list.h"

/* l        - list;
 * t        - tests;
 * arg_type - argument type */
int	proc_cmd_new(t_lst_d *l, t_lst_test *t, char *arg, char *arg_type)
{
	printf("process_cmd_new()\n");
	t_cnt_type	data_type;

	data_type = determine_data_type(arg_type);
	if (data_type == CHAR)
	{
		if (create_lst_char(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == U_CHAR)
	{
		if (create_lst_uchar(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == SHORT)
	{
		if (create_lst_short(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == U_SHORT)
	{
		if (create_lst_ushort(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == INT)
	{
		if (create_lst_int(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == U_INT)
	{
		if (create_lst_uint(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == LONG)
	{
		if (create_lst_long(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == U_LONG)
	{
		if (create_lst_ulong(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == LONG_LONG)
	{
		if (create_lst_longlong(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == U_LONG_LONG)
	{
		if (create_lst_ulonglong(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == FLOAT)
	{
		if (create_lst_float(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == DOUBLE)
	{
		if (create_lst_double(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == LONG_DOUBLE)
	{
		if (create_lst_longdouble(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == STRING)
	{
		if (create_lst_string(l, t, arg) == ERROR)
			return (ERROR);
	}
	if (data_type == INVALID_TYPE)
	{
		printf("process_cmd_new(): You entered an invalid argument\n");
		return (ERROR);
	}
	return (SUCCESS);
}

int	proc_cmd_addfront(t_lst_d *l, t_lst_test *t, char *arg, char *arg_type)
{
	printf("process_cmd_addfront()\n");
	return (SUCCESS);
}

int	proc_cmd_size(t_lst_d *l, t_lst_test *t, char *arg, char *arg_type)
{
	printf("process_cmd_size()\n");
	return (SUCCESS);
}
