#include "../include/list.h"
#include <limits.h>
#include <stdlib.h>

int	lstaddfront_char(t_lst_d **list, t_lst_test *tests, char *arg)
{
	int	pos;
	
	pos = tests->counters[(int)CHAR];
	if (strlen(arg) > 1)
	{
		printf("lstaddfront_char(): The passed argument is not a char\n");
		return (ERROR);
	}
	tests->chars_ptrs[pos] = alloc_char(arg[0]);
	addfront_quick(*list, (char *)tests->chars_ptrs[pos], CHAR, false);
	tests->counters[(int)CHAR]++;
	return (SUCCESS);
}

int	lstaddfront_uchar(t_lst_d **list, t_lst_test *tests, char *arg)
{
	int	pos;

	pos = tests->counters[(int)U_CHAR];
	if (strlen(arg) > 1)
	{
		printf("lstaddfront_uchar(): The passed argument is not an u_char\n");
		return (ERROR);
	}
	tests->uchars_ptrs[pos] = alloc_uchar(arg[0]);
	addfront_quick(*list, (u_char *)tests->uchars_ptrs[pos], U_CHAR, false);
	tests->counters[(int)U_CHAR]++;
	return (SUCCESS);
}

int	lstaddfront_short(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > SHRT_MAX || lst_data < SHRT_MIN)
	{
		printf("lstaddfront_short(): The passed argument is not a short\n");
		return (ERROR);
	}
	pos = tests->counters[(int)SHORT];
	tests->shorts_ptrs[pos] = alloc_short((short)lst_data);
	addfront_quick(*list, (short *)tests->shorts_ptrs[pos], SHORT, false);
	tests->counters[(int)SHORT]++;
	return (SUCCESS);
}

int	lstaddfront_ushort(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > USHRT_MAX)
	{
		printf("lstaddfront_ushort(): The passed argument is not an u_short\n");
		return (ERROR);
	}
	pos = tests->counters[(int)U_SHORT];
	tests->ushorts_ptrs[pos] = alloc_ushort((u_short)lst_data);
	addfront_quick(*list, (u_short *)tests->ushorts_ptrs[pos], U_SHORT, false);
	tests->counters[(int)U_SHORT]++;
	return (SUCCESS);
}

int	lstaddfront_int(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > INT_MAX || lst_data < INT_MIN)
	{
		printf("lstaddfront_int(): The passed argument is not an int\n");
		return (ERROR);
	}
	pos = tests->counters[(int)INT];
	tests->ints_ptrs[pos] = alloc_int((int)lst_data);
	addfront_quick(*list, (int *)tests->ints_ptrs[pos], INT, false);
	tests->counters[(int)INT]++;
	return (SUCCESS);
}
