#include "../include/list.h"

void	free_ldoubles(t_lst_test *tests)
{
	free(tests->ldoubles);
	tests->ldoubles = NULL;
}

void	free_chars(t_lst_test *tests)
{
	free(tests->chars);
	tests->chars = NULL;
}

void	free_uchars(t_lst_test *tests)
{
	free(tests->uchars);
	tests->uchars = NULL;
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
	tests->strs = NULL;
}

void	free_voids(t_lst_test *tests)
{
	free(tests->voids);
	tests->voids = NULL;
}
