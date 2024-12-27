#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fname, int ntest);

void	lstnew_test(void)
{
	char	fname[MAX_FUNC_NAME_LEN];
	
	strncpy(fname, "ft_lstnew", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	printf("%s():\n", fname);
	launch_tests(fname);
	print_test_footer();
}

static void	test_helper(t_char_c *fname, int ntest, void *cnt, t_cnt_type type)
{
	char	format[MAX_FORMAT_STR_LEN];
	t_list	*lst;

	strncpy(format, "(\"%s\", \"%u\", \"%lu\") = %p -> \"%s\"", MAX_FORMAT_STR_LEN);

	lst = ft_lstnew(cnt);

	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str, start, len, ret, ret);
	printf("\t\tThe list `lst` was created\n");
	printf("\t\ttNow the list `lst` contains only one node\n");
	printf("\t\tlst->content: %s\n", (char *)lst->content);
	printf("\t\tft_lstsize(lst): %d\n", ft_lstsize(&lst));

	print_list(head_ptr);
}

static void	print_node_cnt(t_list *lst)
{

}
