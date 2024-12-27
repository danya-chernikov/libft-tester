#include "../include/list.h"

void	print_list(t_list *head_ptr)
{	
	t_list	*nptr;

	printf("\n%p -> ", head_ptr);
	nptr = head_ptr->next;
	while (nptr != NULL)
	{
		printf("%p -> ", nptr);
		nptr = nptr->next;
	}
	printf("-> NULL\n");
}

void	free_node(void *ptr)
{
	free(ptr);
}
