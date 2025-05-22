#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **head);

void	list_remove_if_test(t_list **head)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_list_remove_if", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, head);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, t_list **head)
{
	char	format[MAX_FORMAT_STR_LEN];
	int		test_data = 14;

	strncpy(format, "(%p) = %d\n", MAX_FORMAT_STR_LEN);
	ft_list_remove_if(head, (void *)&test_data, cmp);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
}
