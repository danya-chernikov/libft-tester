#include "../include/list.h"
#include <limits.h>
#include <stdlib.h>

int	lstaddback_uint(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > UINT_MAX)
	{
		printf("lstaddback_uint(): The passed argument is not an u_int\n");
		return (ERROR);
	}
	pos = counters[(int)U_INT];
	tests->uints_ptrs[pos] = alloc_uint((u_int)lst_data);
	addback_quick(list, (u_int *)tests->uints_ptrs[pos], U_INT, false);
	tests->counters[(int)U_INT]++;
	return (SUCCESS);
}

int	lstaddback_long(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > LONG_MAX || lst_data < LONG_MIN)
	{
		printf("lstaddback_long(): The passed argument is not a long\n");
		return (ERROR);
	}
	pos = counters[(int)LONG];
	tests->longs_ptrs[pos] = alloc_long((long)lst_data);
	addback_quick(list, (long *)tests->longs_ptrs[pos], LONG, false);
	tests->counters[(int)LONG]++;
	return (SUCCESS);
}

int	lstaddback_ulong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > ULONG_MAX)
	{
		printf("lstaddback_ulong(): The passed argument is not an u_long\n");
		return (ERROR);
	}
	pos = counters[(int)U_LONG];
	tests->ulongs_ptrs[pos] = alloc_ulong((u_long)lst_data);
	addback_quick(list, (u_long *)tests->ulongs_ptrs[pos], U_LONG, false);
	tests->counters[(int)U_LONG]++;
	return (SUCCESS);
}

int	lstaddback_longlong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	pos = counters[(int)LONG_LONG];
	tests->lls_ptrs[pos] = alloc_longlong((t_ll)lst_data);
	addback_quick(list, (t_ll *)tests->lls_ptrs[pos], LONG_LONG, false);
	tests->counters[(int)LONG_LONG]++;
	return (SUCCESS);
}

int	lstaddback_ulonglong(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	pos = counters[(int)U_LONG_LONG];
	tests->ulls_ptrs[pos] = alloc_ulonglong((t_ull)lst_data);
	addback_quick(list, (t_ull *)tests->ulls_ptrs[pos], U_LONG_LONG, false);
	tests->counters[(int)U_LONG_LONG]++;
	return (SUCCESS);
}
