#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int ntest, t_list **node, void (*del)(void *));

/* l - Pointer to the structure that represents the list;
 * n - Double pointer to the node from which we start clearing the list;
 * f - Function that deletes the content of each node in the list;
 * t - Pointer to the structure that stores pointers to the content of each node. */
void	lstclear_test(t_lst_d *l, t_list **n, void (*f)(void *), t_lst_test *t)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstclear", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	nullify_node_ptr(l, n);
	detect_nodes_to_free(l, n, t);
	//print_list2(l, 0);
	test_helper(fname, 1, n, f);
	print_test_footer();
}

/* It sets NULL in the cells of types that contain pointers to the contents of nodes
 * traversed from *node to the tail of the list*/
static void	test_helper(t_char_c *fn, int ntest, t_list **node, void (*del)(void *))
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "(%p, %p)\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fn);
	ft_lstclear(node, del);
	printf(format, node, del);
}
