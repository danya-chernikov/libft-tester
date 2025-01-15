#include "../include/list.h"

int	alloc_lst_test_strs_ptrs(t_lst_test *tests)
{
	int	i;

	tests->strs_ptrs = (char **)malloc(MAX_LST_NODES_NUM * sizeof (char *));
	if (tests->strs_ptrs == NULL)
		return (0);
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->strs_ptrs[i] = NULL;
		i++;
	}
	return (1);
}

int	alloc_lst_test_voids(t_lst_test *tests)
{
	int	i;

	tests->voids = (void *)malloc(MAX_LST_NODES_NUM * sizeof (void));
	if (tests->voids == NULL)
		return (0);
	tests->voids_ptrs = (void **)malloc(MAX_LST_NODES_NUM * sizeof (void *));
	if (tests->voids_ptrs == NULL)
	{
		free(tests->voids);
		return (0);
	}
	i = 0;
	while (i < MAX_LST_NODES_NUM)
	{
		tests->voids_ptrs[i] = NULL;
		i++;
	}
	return (1);
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
