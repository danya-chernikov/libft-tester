#include "../include/list.h"
#include <stdlib.h>

int	lstnew_float(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)FLOAT];
	tests->floats_ptrs[pos] = alloc_float((float)lst_data);
	list = list_debug_init((float *)tests->floats_ptrs[pos], FLOAT, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)FLOAT]++;
	return (SUCCESS);
}

int	lstnew_double(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)DOUBLE];
	tests->dbls_ptrs[pos] = alloc_double((double)lst_data);
	list = list_debug_init((double *)tests->dbls_ptrs[pos], DOUBLE, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)DOUBLE]++;
	return (SUCCESS);
}

int	lstnew_longdouble(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)LONG_DOUBLE];
	tests->ldbls_ptrs[pos] = alloc_ldouble((t_ld)lst_data);
	list = list_debug_init((t_ld *)tests->ldbls_ptrs[pos], LONG_DOUBLE, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)LONG_DOUBLE]++;
	return (SUCCESS);
}

int	lstnew_string(t_lst_d *list, t_lst_test *tests, char *arg)
{
	int	pos;

	pos = tests->counters[(int)STRING];
	tests->strs_ptrs[pos] = alloc_string(arg);
	list = list_debug_init((char *)tests->strs_ptrs[pos], STRING, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)STRING]++;
	return (SUCCESS);
}
