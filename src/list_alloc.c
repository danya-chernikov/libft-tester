#include "../include/list.h"

/* It reserves memory for the array storing
 * static values and the array storing pointers.
 * Additionally, it fills the pointer array with
 * NULL to identify later which cells need to be
 * released (only non-NULL cells will be released) */
int	alloc_lst_test_chars(t_lst_test *tests)
{
	char	**chars_ptrs;
	char	*chars;
	int		i;

	chars = (char *)malloc(MAX_LST_NODES_NUM * sizeof (char));
	if (chars == NULL)
		return (ERROR);
	tests->chars = chars;
	chars_ptrs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (chars_ptrs == NULL)
	{
		free(tests->chars);
		return (ERROR);
	}
	tests->chars_ptrs = chars_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->chars_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_uchars(t_lst_test *tests)
{
	u_char	**uchars_ptrs;
	u_char	*uchars;
	int		i;

	uchars = (u_char *)malloc(MAX_LST_NODES_NUM * sizeof (u_char));
	if (uchars == NULL)
		return (ERROR);
	tests->uchars = uchars;
	uchars_ptrs = (u_char **)malloc(MAX_LST_NODES_NUM * sizeof (u_char *));
	if (uchars_ptrs == NULL)
	{
		free(tests->uchars);
		return (ERROR);
	}
	tests->uchars_ptrs = uchars_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->uchars_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_shorts(t_lst_test *tests)
{
	short	**shorts_ptrs;
	short	*shorts;
	int		i;

	shorts = (short *)malloc(MAX_LST_NODES_NUM * sizeof (short));
	if (shorts == NULL)
		return (ERROR);
	tests->shorts = shorts;
	shorts_ptrs = (short **)malloc(MAX_LST_NODES_NUM * sizeof (short *));
	if (shorts_ptrs == NULL)
	{
		free(tests->shorts);
		return (ERROR);
	}
	tests->shorts_ptrs = shorts_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->shorts_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_ushorts(t_lst_test *tests)
{
	u_short	**ushorts_ptrs;
	u_short	*ushorts;
	int		i;

	ushorts = (u_short *)malloc(MAX_LST_NODES_NUM * sizeof (u_short));
	if (ushorts == NULL)
		return (ERROR);
	tests->ushorts = ushorts;
	ushorts_ptrs = (u_short **)malloc(MAX_LST_NODES_NUM * sizeof (u_short *));
	if (ushorts_ptrs == NULL)
	{
		free(tests->ushorts);
		return (ERROR);
	}
	tests->ushorts_ptrs = ushorts_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ushorts_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_ints(t_lst_test *tests)
{
	int	**ints_ptrs;
	int	*ints;
	int	i;

	ints = (int *)malloc(MAX_LST_NODES_NUM * sizeof (int));
	if (ints == NULL)
		return (ERROR);
	tests->ints = ints;
	ints_ptrs = (int **)malloc(MAX_LST_NODES_NUM * sizeof (int *));
	if (ints_ptrs == NULL)
	{
		free(tests->ints);
		return (ERROR);
	}
	tests->ints_ptrs = ints_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->ints_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}
