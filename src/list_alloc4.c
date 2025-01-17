#include "../include/list.h"

int	alloc_lst_test_strs_ptrs(t_lst_test *tests)
{
	char	**strs_ptrs;
	int		i;

	strs_ptrs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (strs_ptrs == NULL)
		return (ERROR);
	tests->strs_ptrs = strs_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->strs_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

int	alloc_lst_test_voids(t_lst_test *tests)
{
	void	**voids_ptrs;
	void	*voids;
	int		i;

	voids = (void *)malloc(MAX_LST_NODES_NUM * sizeof (void));
	if (voids == NULL)
		return (ERROR);
	tests->voids = voids;
	voids_ptrs = (void **)malloc(MAX_LST_NODES_NUM * sizeof (void *));
	if (voids_ptrs == NULL)
	{
		free(tests->voids);
		return (ERROR);
	}
	tests->voids_ptrs = voids_ptrs;
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->voids_ptrs[i] = NULL;
		i++;
	}
	return (SUCCESS);
}

/* It allocates memory for a char
 * value `val`, stores `val` in
 * it, and returns a pointer to
 * the allocated memory */
char	*alloc_char(char val)
{
	char	*ptr;

	ptr = (char *)malloc(1 * sizeof (char));
	*ptr = val;
	return (ptr);
}

u_char	*alloc_uchar(u_char val)
{
	u_char	*ptr;

	ptr = (u_char *)malloc(1 * sizeof (u_char));
	*ptr = val;
	return (ptr);
}

short	*alloc_short(short val)
{
	short	*ptr;

	ptr = (short *)malloc(1 * sizeof (short));
	*ptr = val;
	return (ptr);
}
