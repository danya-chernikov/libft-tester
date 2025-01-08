#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **head);

void	lstsize_test(t_list **head)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstsize", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	printf("%s():\n", fname);
	test_helper(fname, 1, head);
	print_test_footer();
}

/* cnt_str - list content represented as string */
static void	test_helper(t_char_c *fname, int ntest, t_list **head)
{
	char	format[MAX_FORMAT_STR_LEN];
	int		size;

	strncpy(format, "(%p) = %d\n", MAX_FORMAT_STR_LEN);
	size = ft_lstsize(head);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, *head, size);
}
