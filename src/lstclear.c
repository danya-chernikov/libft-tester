#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest, t_list **node, void (*del)(void *));

/* It's very important to write the chunk of code from line 16 to line 23
 * only after calling test_helper()*/
void	lstclear_test(t_list **node, void (*del)(void *), t_lst_test *tests)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstclear", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	detect_nodes_to_free(node, tests);
	test_helper(fname, 1, node, del);
	print_test_footer();
}

/* It sets NULL in the cells of types that contain pointers to the contents of nodes
 * traversed from *node to the tail of the list*/
static void	test_helper(t_char_c *fname, int ntest, t_list **node, void (*del)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	ft_lstclear(node, del);
	printf(format, node, del);
}
