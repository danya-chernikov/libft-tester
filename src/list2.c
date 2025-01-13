#include "../include/list.h"
#include "../include/putsmth_fd.h"

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

int	lstsize(t_list **lst)
{
	t_list	*nptr;
	int		size;

	size = 1;
	nptr = (*lst)->next;
	while (nptr != NULL)
	{
		nptr = nptr->next;
		size++;
	}
	return (size);
}

void	init_list_tests(t_lst_test *tests)
{
	tests->chars = NULL;
	tests->uchars = NULL;
	tests->shorts = NULL;
	tests->ushorts = NULL;
	tests->ints = NULL;
	tests->uints = NULL;
	tests->longs = NULL;
	tests->ulongs = NULL;
	tests->lls = NULL;
	tests->ulls = NULL;
	tests->floats = NULL;
	tests->doubles = NULL;
	tests->ldoubles = NULL;
	tests->strs = NULL;
	tests->voids = NULL;
}

/* It inserts the `type` type at the beginning of the `types` array, which had
 * previously shifted all other elements to the right */
void	addfront_test_type(t_cnt_type *types, int type_cnt, t_cnt_type type)
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

int	create_list_tests(t_lst_test *tests)
{
	char	fname[MAX_FUNC_NAME_LEN];
	char	errbuf[MAX_ERR_BUF_SIZE];

	strncpy(fname, "create_list_tests", MAX_FUNC_NAME_LEN);
	init_list_tests(tests);
	if (!alloc_lst_test_strs(tests)
		|| !alloc_lst_test_ints(tests)
		|| !alloc_lst_test_floats(tests)
		|| !alloc_lst_test_chars(tests)
		|| !alloc_lst_test_shorts(tests))
	{
		form_common_err_msg(errbuf, fname, MEM_ERR_MSG);
		perror(errbuf);
		return (0);
	}
	add_list_tests(tests);
	return (1);
}
