#include "../include/list.h"

void	free_chars(t_lst_test *tests)
{
	int	i;

	if (tests->chars != NULL)
	{
		free(tests->chars);
		tests->chars = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->chars_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->chars_ptrs[i], tests))
			{
				free(tests->chars_ptrs[i]);
				tests->chars_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->chars_ptrs != NULL)
	{
		free(tests->chars_ptrs);
		tests->chars_ptrs = NULL;
	}
}

void	free_uchars(t_lst_test *tests)
{
	int	i;

	if (tests->uchars != NULL)
	{
		free(tests->uchars);
		tests->uchars = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->uchars_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->uchars_ptrs[i], tests))
			{
				free(tests->uchars_ptrs[i]);
				tests->uchars_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->uchars_ptrs != NULL)
	{
		free(tests->uchars_ptrs);
		tests->uchars_ptrs = NULL;
	}
}

void	free_shorts(t_lst_test *tests)
{
	int	i;

	if (tests->shorts != NULL)
	{
		free(tests->shorts);
		tests->shorts = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->shorts_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->shorts_ptrs[i], tests))
			{
				free(tests->shorts_ptrs[i]);
				tests->shorts_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->shorts_ptrs != NULL)
	{
		free(tests->shorts_ptrs);
		tests->shorts_ptrs = NULL;
	}
}

void	free_ushorts(t_lst_test *tests)
{
	int	i;

	if (tests->ushorts != NULL)
	{
		free(tests->ushorts);
		tests->ushorts = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ushorts_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->ushorts_ptrs[i], tests))
			{
				free(tests->ushorts_ptrs[i]);
				tests->ushorts_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->shorts_ptrs != NULL)
	{
		free(tests->shorts_ptrs);
		tests->shorts_ptrs = NULL;
	}
}

void	free_ints(t_lst_test *tests)
{
	int	i;

	if (tests->ints != NULL)
	{
		free(tests->ints);
		tests->ints = NULL;
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		if (tests->ints_ptrs[i] != NULL)
		{
			if (!cnt_was_freed(tests->ints_ptrs[i], tests))
			{
				free(tests->ints_ptrs[i]);
				tests->ints_ptrs[i] = NULL;
			}
		}
		i++;
	}
	if (tests->ints_ptrs != NULL)
	{
		free(tests->ints_ptrs);
		tests->ints_ptrs = NULL;
	}
}
