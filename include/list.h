#ifndef LIST_H
# define LIST_H

# include "libft_tester.h"

/* list.c */
char	*create_format_str(void *cnt, t_cnt_type type);
void	process_arg(char *arg, void *cnt, t_cnt_type type);
void	process_numeric_arg(char *arg, void *cnt, t_cnt_type type);
void	process_non_numeric_arg(char *arg, void *cnt, t_cnt_type type);
int		print_list(t_lst_d *list, int ntabs);

/* list2.c */
void	print_tabs(int n);
int		lstsize(t_list **lst);
void	init_list_tests(t_lst_test *tests);
void	init_static_list_tests(t_lst_test *tests);
void	init_heap_list_tests(t_lst_test *tests);

/* list3.c */
void	linked_list_launch_tests(t_lst_test *tests);
int		create_list_tests(t_lst_test *tests);
void	add_list_tests(t_lst_test *tests);
t_lst_d	*list_debug_init(void *cnt, t_cnt_type type);
void	addfront_test_type(t_cnt_type *types, int type_cnt, t_cnt_type type);

/* list4.c */
void	addfront_quick(t_lst_d *list, void *cnt, t_cnt_type type);
void	addback_quick(t_lst_d *list, void *cnt, t_cnt_type type);
t_list	*get_node(t_lst_d *list, int node_num);
bool	cnt_was_freed(void *cnt, t_lst_test *tests);
bool	node_was_freed(void *node, t_lst_test *tests);

/* list_alloc.c */
int		alloc_lst_test_chars(t_lst_test *tests);
int		alloc_lst_test_uchars(t_lst_test *tests);
int		alloc_lst_test_shorts(t_lst_test *tests);
int		alloc_lst_test_ushorts(t_lst_test *tests);
int		alloc_lst_test_ints(t_lst_test *tests);

/* list_alloc2.c */
int		alloc_lst_test_uints(t_lst_test *tests);
int		alloc_lst_test_longs(t_lst_test *tests);
int		alloc_lst_test_ulongs(t_lst_test *tests);
int		alloc_lst_test_lls(t_lst_test *tests);
int		alloc_lst_test_ulls(t_lst_test *tests);

/* list_alloc3.c */
int		alloc_lst_test_floats(t_lst_test *tests);
int		alloc_lst_test_doulbes(t_lst_test *tests);
int		alloc_lst_test_ldoulbes(t_lst_test *tests);
int		alloc_lst_test_strings(t_lst_test *tests);
int		alloc_lst_test_strs(t_lst_test *tests);

/* list_alloc4.c */
int		alloc_lst_test_strs_ptrs(t_lst_test *tests);
int		alloc_lst_test_voids(t_lst_test *tests);
char	*alloc_char(char val);
u_char	*alloc_uchar(u_char val);
short	*alloc_short(short val);

/* list_alloc5.c */
u_short	*alloc_ushort(u_short val);
int		*alloc_int(int val);
u_int	*alloc_uint(u_int val);
long	*alloc_long(long val);
t_ul	*alloc_ulong(t_ul val);

/* list_alloc6.c */
t_ll	*alloc_longlong(t_ll val);
t_ull	*alloc_ulonglong(t_ull val);
float	*alloc_float(float val);
double	*alloc_double(double val);
t_ld	*alloc_ldouble(t_ld val);

/* list_alloc7.c */
char	*alloc_string(char *val);

/* list_free.c */
void	delete_all_lst_tests(t_lst_test *tests);
void	free_numeric_lst_tests(t_lst_test *tests);
void	free_non_numeric_lst_tests(t_lst_test *tests);
void	free_list_debug(t_lst_d *list);
void	del(void *node_cnt);

/* list_free2.c */
void	free_chars(t_lst_test *tests);
void	free_uchars(t_lst_test *tests);
void	free_shorts(t_lst_test *tests);
void	free_ushorts(t_lst_test *tests);
void	free_ints(t_lst_test *tests);

/* list_free3.c */
void	free_uints(t_lst_test *tests);
void	free_longs(t_lst_test *tests);
void	free_ulongs(t_lst_test *tests);
void	free_lls(t_lst_test *tests);
void	free_ulls(t_lst_test *tests);

/* list_free4.c */
void	free_floats(t_lst_test *tests);
void	free_doubles(t_lst_test *tests);
void	free_ldoubles(t_lst_test *tests);
void	free_lst_test_strs(t_lst_test *tests);
void	free_voids(t_lst_test *tests);

#endif
