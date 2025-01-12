#ifndef LIST_H
# define LIST_H

# include "libft_tester.h"

char	*create_format_str(void *cnt, t_cnt_type type);
void	process_arg(char *arg, void *cnt, t_cnt_type type);
void	process_numeric_arg(char *arg, void *cnt, t_cnt_type type);
void	process_non_numeric_arg(char *arg, void *cnt, t_cnt_type type);
int		print_list(t_list *head_ptr, t_cnt_type *types, int ntabs);
void	addfront_quick(t_list **head_ptr, void *cnt, t_cnt_type type);
int		lstsize(t_list **lst);
void	print_tabs(int n);
void	free_node(void *ptr);

void	init_lst_tests(t_lst_test *tests);

int		alloc_lst_test_chars(t_lst_test *tests);
int		alloc_lst_test_uchars(t_lst_test *tests);
int		alloc_lst_test_shorts(t_lst_test *tests);
int		alloc_lst_test_ushorts(t_lst_test *tests);
int		alloc_lst_test_ints(t_lst_test *tests);
int		alloc_lst_test_uints(t_lst_test *tests);
int		alloc_lst_test_longs(t_lst_test *tests);
int		alloc_lst_test_ulongs(t_lst_test *tests);
int		alloc_lst_test_lls(t_lst_test *tests);
int		alloc_lst_test_ulls(t_lst_test *tests);
int		alloc_lst_test_floats(t_lst_test *tests);
int		alloc_lst_test_doulbes(t_lst_test *tests);
int		alloc_lst_test_ldoulbes(t_lst_test *tests);
int		alloc_lst_test_strs(t_lst_test *tests);
int		alloc_lst_test_voids(t_lst_test *tests);

void	free_lst_test_strs(t_lst_test *tests);
void	free_numeric_lst_tests(t_lst_test *tests);
void	free_non_numeric_lst_tests(t_lst_test *tests);
void	free_all_lst_tests(t_lst_test *tests);

void	add_list_tests(t_lst_test *tests);
void	test_linked_list_1(t_lst_test *tests);

#endif
