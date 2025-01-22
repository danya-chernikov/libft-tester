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
			if (!cnt_was_freed(tests->floats_ptrs[i], tests))
			{
				free(tests->floats_ptrs[i]);
				tests->floats_ptrs[i] = NULL;
			}
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
			if (!cnt_was_freed(tests->dbls_ptrs[i], tests))
			{
				free(tests->dbls_ptrs[i]);
				tests->dbls_ptrs[i] = NULL;
			}
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
			if (!cnt_was_freed(tests->ldbls_ptrs[i], tests))
			{
				free(tests->ldbls_ptrs[i]);
				tests->ldbls_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->ldbls_ptrs != NULL)
	{
		free(tests->ldbls_ptrs);
		tests->ldbls_ptrs = NULL;
	}
}

void	free_strings(t_lst_test *tests)
{
	free_strs(tests);
	free_strs_ptrs(tests);
}

void	free_strs(t_lst_test *tests)
{
	int	i;

	i = 0;
	if (tests->strs != NULL)
	{
		while (i < MAX_LST_NODES_NUM)
		{
			free(tests->strs[i]);
			i++;
		}
		free(tests->strs);
		tests->strs = NULL;
	}
}
