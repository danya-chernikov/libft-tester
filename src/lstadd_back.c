#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **head, t_list *new);

void	lstadd_back_test(t_list **head, t_list *new)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstadd_back", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, head, new);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, t_list **head, t_list *new)
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	ft_lstadd_back(head, new);
	printf(format, *head, new);
}
