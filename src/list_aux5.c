#include "../include/list.h"

int	alloc_lst_test_ulls(t_lst_test *tests)
{
	tests->ulls = (t_ull *)malloc(MAX_LST_NODES_NUM * sizeof (t_ull));
	if (tests->ulls == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_floats(t_lst_test *tests)
{
	tests->floats = (float *)malloc(MAX_LST_NODES_NUM * sizeof (float));
	if (tests->floats == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_doulbes(t_lst_test *tests)
{
	tests->doubles = (double *)malloc(MAX_LST_NODES_NUM * sizeof (double));
	if (tests->doubles == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_ldoulbes(t_lst_test *tests)
{
	tests->ldoubles = (t_ld *)malloc(MAX_LST_NODES_NUM * sizeof (t_ld));
	if (tests->ldoubles == NULL)
		return (0);
	return (1);
}

int	alloc_lst_test_strs(t_lst_test *tests)
{
	int	i;

	tests->strs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (tests->strs == NULL)
		return (0);
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->strs[i] = (char *)malloc(MAX_TEST_STR_LEN * sizeof (char));
		if (tests->strs[i] == NULL)
		{
			i--;
			while (i >= 0)
			{
				free(tests->strs[i]);
				i--;
			}
			free(tests->strs);
			return (0);
		}
		i++;
	}
	return (1);
}
