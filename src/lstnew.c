#include "../include/list.h"
#include "../include/libft_tester.h"

static t_list	*test_helper(t_char_c *fn, int nt, void *cnt, t_cnt_type type);

t_list	*lstnew_test(void *cnt, t_cnt_type type)
{
	char	fname[MAX_FUNC_NAME_LEN];
	t_list	*head_ptr;

	strncpy(fname, "ft_lstnew", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
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
	printf("\t\tThe list [ %p | %p ] was created\n", lst, cnt);
	process_arg(cnt_str, lst->content, type);
	printf("\t\t(%p)->content: %s\n", lst, cnt_str);
	free(format);
	return (lst);
}
