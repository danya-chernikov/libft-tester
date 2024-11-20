#include "common_tester.h"

void	print_bytes(void *ptr, int size)
{
	unsigned char	*p;
	int				i;

	p = (unsigned char *)ptr;
	i = 0;
	while (i < size)
	{
		printf("%02hhX ", p[i]);
		i++;
	}
	printf("\n");
}

void	print_arr_int(int *arr, int size)
{
	size_t	i;

	printf("{ ");
	i = 0;
	while (i < size)
	{
		printf("%d", arr[i++]);
		if (i < size - 1)
			printf(", ");
		else
			printf(" ");
	}
	puts("}\n");
}
