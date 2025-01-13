#include "../include/list.h"

/* It reserves memory for the array storing
 * static values and the array storing pointers.
 * Additionally, it fills the pointer array with
 * NULL to identify later which cells need to be
 * released (only non-NULL cells will be released) */
int	alloc_lst_test_chars(t_lst_test *tests)
{
	int	i;

	tests->chars = (char *)malloc(MAX_LST_NODES_NUM * sizeof (char));
	if (tests->chars == NULL)
		return (0);
	tests->chars_ptrs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (tests->chars_ptrs == NULL)
	{
		free(tests->chars);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		chars_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_uchars(t_lst_test *tests)
{
	int	i;

	tests->uchars = (u_char *)malloc(MAX_LST_NODES_NUM * sizeof (u_char));
	if (tests->uchars == NULL)
		return (0);
	tests->uchars_ptrs = (u_char **)malloc(MAX_LST_NODES_NUM * sizeof (u_char *));
	if (tests->uchars_ptrs == NULL)
	{
		free(tests->uchars);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		uchars_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_shorts(t_lst_test *tests)
{
	int	i;

	tests->shorts = (short *)malloc(MAX_LST_NODES_NUM * sizeof (short));
	if (tests->shorts == NULL)
		return (0);
	tests->shorts_ptrs = (short **)malloc(MAX_LST_NODES_NUM * sizeof (short *));
	if (tests->shorts_ptrs == NULL)
	{
		free(tests->shorts);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		shorts_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_ushorts(t_lst_test *tests)
{
	int	i;

	tests->ushorts = (u_short *)malloc(MAX_LST_NODES_NUM * sizeof (u_short));
	if (tests->ushorts == NULL)
		return (0);
	tests->ushorts_ptrs = (u_short **)malloc(MAX_LST_NODES_NUM * sizeof (u_short *));
	if (tests->ushorts_ptrs == NULL)
	{
		free(tests->ushorts);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		ushorts_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_ints(t_lst_test *tests)
{
	int	i;

	tests->ints = (int *)malloc(MAX_LST_NODES_NUM * sizeof (int));
	if (tests->ints == NULL)
		return (0);
	tests->ints_ptrs = (int **)malloc(MAX_LST_NODES_NUM * sizeof (int *));
	if (tests->ints_ptrs == NULL)
	{
		free(tests->ints);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		ints_ptrs[i] = NULL;
		i++;
	}
	return (1);
}
