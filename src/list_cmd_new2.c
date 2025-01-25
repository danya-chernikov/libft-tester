#include "../include/list.h"
#include <limits.h>

int	create_lst_uint(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	int		pos;
	t_ull	lst_data;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > UINT_MAX)
	{
		printf("create_lst_uint(): The passed argument is not an u_int\n");
		return (ERROR);
	}
	pos = counters[(int)U_INT];
	tests->uints_ptrs[pos] = alloc_uint((u_int)lst_data);
	list = list_debug_init((u_int *)tests->uints_ptrs[pos], U_INT);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_INT]++;
	return (SUCCESS);
}

int	create_lst_long(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	int		pos;
	t_ll	lst_data;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > LONG_MAX || lst_data < LONG_MIN)
	{
		printf("create_lst_long(): The passed argument is not a long\n");
		return (ERROR);
	}
	pos = counters[(int)LONG];
	tests->longs_ptrs[pos] = alloc_long((long)lst_data);
	list = list_debug_init((long *)tests->longs_ptrs[pos], LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)LONG]++;
	return (SUCCESS);
}

int	create_lst_ulong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	int		pos;
	t_ull	lst_data;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > ULONG_MAX)
	{
		printf("create_lst_ulong(): The passed argument is not an u_long\n");
		return (ERROR);
	}
	pos = counters[(int)U_LONG];
	tests->ulongs_ptrs[pos] = alloc_ulong((u_long)lst_data);
	list = list_debug_init((u_long *)tests->ulongs_ptrs[pos], U_LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_LONG]++;
	return (SUCCESS);
}

int	create_lst_longlong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	int		pos;
	t_ll	lst_data;

	lst_data = strtoll(arg, &stopstr, 10);
	pos = counters[(int)LONG_LONG];
	tests->lls_ptrs[pos] = alloc_longlong((t_ll)lst_data);
	list = list_debug_init((t_ll *)tests->lls_ptrs[pos], LONG_LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)LONG_LONG]++;
	return (SUCCESS);
}

int	create_lst_ulonglong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	int		pos;
	t_ull	lst_data;

	lst_data = strtoull(arg, &stopstr, 10);
	pos = counters[(int)U_LONG_LONG];
	tests->ulls_ptrs[pos] = alloc_ulonglong((u_ll)lst_data);
	list = list_debug_init((u_ll *)tests->ulls_ptrs[pos], U_LONG_LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_LONG_LONG]++;
	return (SUCCESS);
}
