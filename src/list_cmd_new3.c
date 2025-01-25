#include "../include/list.h"
#include <stdlib.h>

int	create_lst_float(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stop_str;
	int		pos;
	t_ld	lst_data;

	lst_data = strtold(arg, stop_str);
	pos = counters[(int)FLOAT];
	tests->floats_ptrs[pos] = alloc_float((float)lst_data);
	list = list_debug_init((float *)tests->floats_ptrs[pos], FLOAT);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)FLOAT]++;
	return (SUCCESS);
}

int	create_lst_double(t_lst_d *list, t_lst_test *tests, char *arg)
{
	int		pos;
	t_ld	lst_data;

	lst_data = strtold(arg);
	pos = counters[(int)U_LONG_LONG];
	tests->ulls_ptrs[pos] = alloc_ulonglong((u_ll)lst_data);
	list = list_debug_init((u_ll *)tests->ulls_ptrs[pos], U_LONG_LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_LONG_LONG]++;
	return (SUCCESS);
}

int	create_lst_ldouble(t_lst_d *list, t_lst_test *tests, char *arg)
{
	int		pos;
	t_ld	lst_data;

	lst_data = str_to_ull(arg);
	pos = counters[(int)U_LONG_LONG];
	tests->ulls_ptrs[pos] = alloc_ulonglong((u_ll)lst_data);
	list = list_debug_init((u_ll *)tests->ulls_ptrs[pos], U_LONG_LONG);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_LONG_LONG]++;
	return (SUCCESS);
}
