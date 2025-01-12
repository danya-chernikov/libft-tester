#include "../include/list.h"
#include "../include/libft_tester.h"

static void	test_helper(t_char_c *fn, int nt, t_list *head, t_cnt_type type);

void	lstlast_test(t_list *head, t_cnt_type type)
{
	char	fname[MAX_FUNC_NAME_LEN];

	strncpy(fname, "ft_lstlast", MAX_FUNC_NAME_LEN);
	print_test_header(fname);
	test_helper(fname, 1, head, type);
	print_test_footer();
}

static void	test_helper(t_char_c *fn, int nt, t_list *head, t_cnt_type type)
{
	char	format[MAX_FORMAT_STR_LEN];
	char	cnt_str[MAX_CNT_STR_LEN];
	t_list	*last;

	strncpy(format, "(%p) = [ %p | %s ]\n", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", nt);
	cprintf(YELLOW, "%s", fn);
	last = ft_lstlast(head);
	process_arg(cnt_str, last->content, type);
	printf(format, head, last, cnt_str);
}
