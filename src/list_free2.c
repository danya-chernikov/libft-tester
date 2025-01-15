#include "../include/list.h"

void	free_chars(t_lst_test *tests)
{
	int	i;

	free(tests->chars);
	tests->chars = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->chars_ptrs[i] != NULL)
		{
			free(tests->chars_ptrs[i]);
			tests->chars_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->chars_ptrs);
	tests->chars_ptrs = NULL;
}

void	free_uchars(t_lst_test *tests)
{
	int	i;

	free(tests->uchars);
	tests->uchars = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->uchars_ptrs[i] != NULL)
		{
			free(tests->uchars_ptrs[i]);
			tests->uchars_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->uchars_ptrs);
	tests->uchars_ptrs = NULL;
}

void	free_shorts(t_lst_test *tests)
{
	int	i;

	free(tests->shorts);
	tests->shorts = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->shorts_ptrs[i] != NULL)
		{
			free(tests->shorts_ptrs[i]);
			tests->shorts_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->shorts_ptrs);
	tests->shorts_ptrs = NULL;
}

void	free_ushorts(t_lst_test *tests)
{
	int	i;

	free(tests->ushorts);
	tests->ushorts = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ushorts_ptrs[i] != NULL)
		{
			free(tests->ushorts_ptrs[i]);
			tests->ushorts_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->shorts_ptrs);
	tests->shorts_ptrs = NULL;
}

void	free_ints(t_lst_test *tests)
{
	int	i;

	free(tests->ints);
	tests->ints = NULL;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ints_ptrs[i] != NULL)
		{
			free(tests->ints_ptrs[i]);
			tests->ints_ptrs[i] = NULL;
		}
		i++;
	}
	free(tests->ints_ptrs);
	tests->ints_ptrs = NULL;
}
