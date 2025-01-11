#include "../include/list.h"

int		alloc_lst_test_voids(t_lst_test *tests)
{
	tests->voids = (void *)malloc(MAX_LST_NODES_NUM * sizeof (void));
	if (tests->voids == NULL)
		return (0);
	return (1);
}

void	free_lst_test_strs(t_lst_test *tests)
{
	int	i;

	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		free(tests->strs[i]);
		i++;
	}
	free(tests->strs);
}

void	free_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->shorts)
		free(tests->shorts);
	if (tests->ushorts)
		free(tests->ushorts);
	if (tests->ints)
		free(tests->ints);
	if (tests->uints)
		free(tests->uints);
	if (tests->longs)
		free(tests->longs);
	if (tests->ulongs)
		free(tests->ulongs);
	if (tests->lls)
		free(tests->lls);
	if (tests->ulls)
		free(tests->ulls);
	if (tests->floats)
		free(tests->floats);
	if (tests->doubles)
		free(tests->doubles);
	if (tests->ldoubles)
		free(tests->ldoubles);
}

void	free_non_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->chars)
		free(tests->chars);
	if (tests->uchars)
		free(tests->uchars);
	if (tests->strs)
		free_lst_test_strs(tests);
	if (tests->voids)
		free(tests->voids);
}

void	free_all_lst_tests(t_lst_test *tests)
{
	free_numeric_lst_tests(tests);
	free_non_numeric_lst_tests(tests);
}
