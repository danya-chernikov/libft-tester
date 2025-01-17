#include "../include/list.h"

void	free_floats(t_lst_test *tests)
{
	int	i;

	if (tests->floats != NULL)
	{
		free(tests->floats);
		tests->floats = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->floats_ptrs[i] != NULL)
		{
			free(tests->floats_ptrs[i]);
			tests->floats_ptrs[i] = NULL;
		}
		i++;
	}
	if (tests->floats_ptrs != NULL)
	{
		free(tests->floats_ptrs);
		tests->floats_ptrs = NULL;
	}
}

void	free_doubles(t_lst_test *tests)
{
	int	i;

	if (tests->doubles != NULL)
	{
		free(tests->doubles);
		tests->doubles = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->dbls_ptrs[i] != NULL)
		{
			free(tests->dbls_ptrs[i]);
			tests->dbls_ptrs[i] = NULL;
		}
		i++;
	}
	if (tests->dbls_ptrs != NULL)
	{
		free(tests->dbls_ptrs);
		tests->dbls_ptrs = NULL;
	}
}

void	free_ldoubles(t_lst_test *tests)
{
	int	i;

	if (tests->ldoubles != NULL)
	{
		free(tests->ldoubles);
		tests->ldoubles = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ldbls_ptrs[i] != NULL)
		{
			free(tests->ldbls_ptrs[i]);
			tests->ldbls_ptrs[i] = NULL;
		}
		i++;
	}
	if (tests->ldbls_ptrs != NULL)
	{
		free(tests->ldbls_ptrs);
		tests->ldbls_ptrs = NULL;
	}
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
	if (tests->strs != NULL)
	{
		free(tests->strs);
		tests->strs = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->strs_ptrs[i] != NULL)
		{
			free(tests->strs_ptrs[i]);
			tests->strs_ptrs[i] = NULL;
		}
		i++;
	}
	if (tests->strs_ptrs != NULL)
	{
		free(tests->strs_ptrs);
		tests->strs_ptrs = NULL;
	}
}

void	free_voids(t_lst_test *tests)
{
	int	i;

	if (tests->voids != NULL)
	{
		free(tests->voids);
		tests->voids = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->voids_ptrs[i] != NULL)
		{
			free(tests->voids_ptrs[i]);
			tests->voids_ptrs[i] = NULL;
		}
		i++;
	}
	if (tests->voids_ptrs != NULL)
	{
		free(tests->voids_ptrs);
		tests->voids_ptrs = NULL;
	}
}
