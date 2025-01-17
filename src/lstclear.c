#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **node, void (*del)(void *));

void	lstclear_test(t_list **node, void (*del)(void *))
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstclear", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, node, del);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, t_list **node, void (*del)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	ft_lstclear(node, del);
	printf(format, node, del);
}
