#include "../include/list.h"

/* It prints the pointers representing all the nodes of the
 * singly linked list, starting from the head node that `head_ptr`
 * points to, in the form of a chain. The chain begins with tabs
 * number of '\t' symbols. The `types` array contains the data
 * types of the nodes in the list, beginning with the head node */
int	print_list(t_lst_d *list, int ntabs)
{
	t_list	*nptr;
	char	*arg;
	int		lsize;
	int		i;

	if (list->head == NULL)
		return (ERROR);
	lsize = lstsize(&list->head);
	arg = (char *)malloc((MAX_FORMAT_STR_LEN + 1) * sizeof (char));
	if (arg == NULL)
		return (ERROR);
	print_tabs(ntabs);
	process_arg(arg, list->head->content, list->types[0]);
	printf("[ %p | %s ] -> ", list->head, arg);
	nptr = list->head->next;
	i = 1;
	while (nptr != NULL)
	{
		process_arg(arg, nptr->content, list->types[i]);
		printf("[ %p | %s ] -> ", nptr, arg);
		nptr = nptr->next;
		i++;
	}
	printf("NULL\n");
	free(arg);
	return (SUCCESS);
}

/* It prints n tabs consecutively */
void	print_tabs(int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("\t");
		i++;
	}
}

/* It's the same function
 * as ft_lstsize(), but it
 * is used only for the
 * internal purposes of the
 * tester, specifically by
 * the print_list() function */
int	lstsize(t_list **lst)
{
	t_list	*nptr;
	int		size;

	if (*lst == NULL)
		return (0);
	size = 1;
	nptr = (*lst)->next;
	while (nptr != NULL)
	{
		nptr = nptr->next;
		size++;
	}
	return (size);
}

void	lst_ask_user(char *choice)
{
	printf("What kind of testing for linked lists you "
		"would prefer? (S - Static / D - Dynamic): ");
	scanf("%c", choice);
}

/* It inserts the `type` type at the beginning of the `types` array, which had
 * previously shifted all other elements to the right */
void	insert_type_at_begin(t_cnt_type *types, int type_cnt, t_cnt_type type)
{
	int	i;

	i = type_cnt;
	while (i > 0)
	{
		types[i] = types[i - 1];
		i--;
	}
	types[0] = type;
}
