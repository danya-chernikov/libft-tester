#include "../include/list.h"
#include <limits.h>
#include <stdlib.h>

int	lstaddfront_uint(t_lst_d *list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > UINT_MAX)
	{
		printf("lstaddfront_uint(): The passed argument is not an u_int\n");
		return (ERROR);
	}
	pos = counters[(int)U_INT];
	tests->uints_ptrs[pos] = alloc_uint((u_int)lst_data);
	addfront_quick(list, (u_int *)tests->uints_ptrs[pos], U_INT, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_INT]++;
	return (SUCCESS);
}
