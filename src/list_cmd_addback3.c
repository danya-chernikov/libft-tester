#include "../include/list.h"
#include <stdlib.h>

int	lstaddback_float(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)FLOAT];
	tests->floats_ptrs[pos] = alloc_float((float)lst_data);
	addback_quick(*list, (float *)tests->floats_ptrs[pos], FLOAT, false);
	tests->counters[(int)FLOAT]++;
	return (SUCCESS);
}

int	lstaddback_double(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)DOUBLE];
	tests->dbls_ptrs[pos] = alloc_double((double)lst_data);
	addback_quick(*list, (double *)tests->dbls_ptrs[pos], DOUBLE, false);
	tests->counters[(int)DOUBLE]++;
	return (SUCCESS);
}

int	lstaddback_longdouble(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ld	lst_data;
	int		pos;

	lst_data = strtold(arg, &stopstr);
	pos = tests->counters[(int)LONG_DOUBLE];
	tests->ldbls_ptrs[pos] = alloc_ldouble((t_ld)lst_data);
	addback_quick(*list, (t_ld *)tests->ldbls_ptrs[pos], LONG_DOUBLE, false);
	tests->counters[(int)LONG_DOUBLE]++;
	return (SUCCESS);
}

int	lstaddback_string(t_lst_d **list, t_lst_test *tests, char *arg)
{
	int	pos;

	pos = tests->counters[(int)STRING];
	tests->strs_ptrs[pos] = alloc_string(arg);
	addback_quick(*list, (char *)tests->strs_ptrs[pos], STRING, false);
	tests->counters[(int)STRING]++;
	return (SUCCESS);
}
