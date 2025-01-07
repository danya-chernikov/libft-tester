#include "../include/list.h"
#include "../include/libft_tester.h"

static t_list	*test_helper(t_char_c *fn, int nt, void *cnt, t_cnt_type type);

t_list	*lstnew_test(void *cnt, t_cnt_type type)
{
	t_list	*head_ptr;
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstnew", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	printf("%s():\n", fname);
	head_ptr = test_helper(fname, 1, cnt, type);
	print_test_footer();
	return (head_ptr);
}

/* cnt_str - list content represented as string */
static t_list	*test_helper(t_char_c *fn, int nt, void *cnt, t_cnt_type type)
{
	t_list	*lst;
	char	*format;
	char	cnt_str[MAX_CNT_STR_LEN];

	format = create_format_str(cnt, type);
	if (format == NULL)
		return (NULL);
	lst = ft_lstnew(cnt);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	printf(format, lst);
	printf("\t\tThe list `lst` was created\n");
	printf("\t\tThe list `lst` contains only one node\n");
	process_numeric_arg(cnt_str, lst->content, type);
	process_non_numeric_arg(cnt_str, lst->content, type);
	printf("\t\tlst->content: %s\n", cnt_str);
	print_list(lst, 2);
	free(format);
	return (lst);
}
