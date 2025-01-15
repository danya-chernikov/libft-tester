#include "../include/list.h"

u_short	*alloc_ushort(u_short val)
{
	u_short	*ptr;

	ptr = (u_short *)malloc(1 * sizeof (u_short));
	*ptr = val;
	return (ptr);
}

int	*alloc_int(int val)
{
	int	*ptr;

	ptr = (int *)malloc(1 * sizeof (int));
	*ptr = val;
	return (ptr);
}

u_int	*alloc_uint(u_int val)
{
	u_int	*ptr;

	ptr = (u_int *)malloc(1 * sizeof (u_int));
	*ptr = val;
	return (ptr);
}

long	*alloc_long(long val)
{
	long	*ptr;

	ptr = (long *)malloc(1 * sizeof (long));
	*ptr = val;
	return (ptr);
}

t_ul	*alloc_ulong(t_ul val)
{
	t_ul	*ptr;

	ptr = (t_ul *)malloc(1 * sizeof (t_ul));
	*ptr = val;
	return (ptr);
}
