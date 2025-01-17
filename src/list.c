#include "../include/list.h"

char	*create_format_str(void *cnt, t_cnt_type type)
{
	char	*arg;
	char	*fstr;

	arg = (char *)malloc((MAX_FORMAT_STR_LEN + 1) * sizeof (char));
	if (arg == NULL)
		return (NULL);
	fstr = (char *)malloc((MAX_FORMAT_STR_LEN + 1) * sizeof (char));
	if (fstr == NULL)
	{
		free(arg);
		return (NULL);
	}
	process_arg(arg, cnt, type);
	snprintf(fstr, MAX_FORMAT_STR_LEN, "(%s) = %%p\n", arg);
	free(arg);
	return (fstr);
}

void	process_arg(char *arg, void *cnt, t_cnt_type type)
{
	process_numeric_arg(arg, cnt, type);
	process_non_numeric_arg(arg, cnt, type);
}

/* It generates the textual representation of the `cnt` value of a
 * node based on its content type `type` and stores this representation
 * in the `arg` string. This version of the function implements the
 * described behavior for numeric data types */
void	process_numeric_arg(char *arg, void *cnt, t_cnt_type type)
{
	if (type == SHORT)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%hd", *(short *)cnt);
	if (type == U_SHORT)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%hu", *(u_short *)cnt);
	if (type == INT)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%d", *((int *)cnt));
	if (type == U_INT)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%u", *((u_int *)cnt));
	if (type == LONG)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%ld", *((long *)cnt));
	if (type == U_LONG)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%lu", *((t_ul *)cnt));
	if (type == LONG_LONG)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%lld", *((long long *)cnt));
	if (type == U_LONG_LONG)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%llu", *((t_ull *)cnt));
	if (type == FLOAT)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%f", *((float *)cnt));
	if (type == DOUBLE)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%f", *((double *)cnt));
	if (type == LONG_DOUBLE)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%Lf", *((long double *)cnt));
}

/* It performs the same operation as the process_numeric_arg() function
 * but handles non-numeric data types instead */
void	process_non_numeric_arg(char *arg, void *cnt, t_cnt_type type)
{
	if (type == CHAR)
		snprintf(arg, MAX_FORMAT_STR_LEN, "'%c'", *(char *)cnt);
	if (type == U_CHAR)
		snprintf(arg, MAX_FORMAT_STR_LEN, "'%c'", *(u_char *)cnt);
	if (type == STRING)
		snprintf(arg, MAX_FORMAT_STR_LEN, "\"%s\"", (char *)cnt);
	if (type == VOID)
		snprintf(arg, MAX_FORMAT_STR_LEN, "%p", cnt);
}

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

	lsize = lstsize(&list->head);
	arg = (char *)malloc((MAX_FORMAT_STR_LEN + 1) * sizeof (char));
	if (arg == NULL)
		return (ERROR);
	print_tabs(ntabs);
	process_arg(arg, list->head->content, list->types[lsize - 1]);
	printf("[ %p | %s ] -> ", list->head, arg);
	nptr = list->head->next;
	i = lsize - 2;
	while (nptr != NULL)
	{
		process_arg(arg, nptr->content, list->types[i]);
		printf("[ %p | %s ] -> ", nptr, arg);
		nptr = nptr->next;
		i--;
	}
	printf("NULL\n");
	free(arg);
	return (SUCCESS);
}
