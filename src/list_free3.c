#include "../include/list.h"

void	free_uints(t_lst_test *tests)
{
	int	i;

	free(tests->uints);
	tests->uints = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->uints_ptrs[i] != NULL)
		{
			free(tests->uints_ptrs[i]);
			tests->uints_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->uints_ptrs);
	tests->uints_ptrs = NULL;
}

void	free_longs(t_lst_test *tests)
{
	int	i;

	free(tests->longs);
	tests->longs = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->longs_ptrs[i] != NULL)
		{
			free(tests->longs_ptrs[i]);
			tests->longs_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->longs_ptrs);
	tests->longs_ptrs = NULL;
}

void	free_ulongs(t_lst_test *tests)
{
	int	i;

	free(tests->ulongs);
	tests->ulongs = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ulongs_ptrs[i] != NULL)
		{
			free(tests->ulongs_ptrs[i]);
			tests->ulongs_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->ulongs_ptrs);
	tests->ulongs_ptrs = NULL;
}

void	free_lls(t_lst_test *tests)
{
	int	i;

	free(tests->lls);
	tests->lls = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->lls_ptrs[i] != NULL)
		{
			free(tests->lls_ptrs[i]);
			tests->lls_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->lls_ptrs);
	tests->lls_ptrs = NULL;
}

void	free_ulls(t_lst_test *tests)
{
	int	i;

	free(tests->ulls);
	tests->ulls = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ulls_ptrs[i] != NULL)
		{
			free(tests->ulls_ptrs[i]);
			tests->ulls_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->ulls_ptrs);
	tests->ulls_ptrs = NULL;
}
