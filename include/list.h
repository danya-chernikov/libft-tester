/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:24:23 by dchernik          #+#    #+#             */
/*   Updated: 2025/05/06 17:26:20 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "../common_tester/common_tester.h"
# include "../../libft.h"

# include <ctype.h>
# include <stdbool.h>

/* MAX_LST_TEST_STR_LEN		is used in the files list_alloc3.c and
 *							list_alloc7.c */
# define MAX_LST_NODES_NUM		4096
# define MAX_LST_ATTEMPTS_NUM	8
# define MAX_USER_INPUT_BUF_LEN	8192
# define MAX_CMD_TYPE_LEN		16
# define MAX_CMD_ARG_TYPE_LEN	16
# define MAX_CMD_ARG_LEN		4096
# define MAX_CMD_SUBSTR_LEN		4096
# define MAX_LST_TEST_STR_LEN	4096
# define MAX_CMD_SUBSTR_NUM		3
# define LST_DATA_TYPES_NUM		15

/* SIGNAL_QUIT		is used by linked_list_launch_dynamic_testing();
 * NO_ARG_CMD		is used by check_no_arg_cmd(...);
 * SINGLE_ARG_CMD	single_arg_cmd_is_crt(...) */
# define SIGNAL_QUIT			2
# define NO_ARG_CMD				3
# define SINGLE_ARG_CMD			4

# define CHOICE_STATIC			"S"
# define CHOICE_DYNAMIC			"D"

# define CMD_MAN				"man"
# define CMD_NEW				"new"
# define CMD_ADDFRONT			"addfront"
# define CMD_SIZE				"size"
# define CMD_LAST				"last"
# define CMD_ADDBACK			"addback"
# define CMD_DEL				"del"
# define CMD_CLEAR				"clear"
# define CMD_ITER				"iter"
# define CMD_MAP				"map"
# define CMD_PRINT				"print"
# define CMD_QUIT				"quit"
# define CMD_REMOVE_IF			"remove"
# define CMD_SORT				"sort"

# define AT_CHAR				"CHAR"
# define AT_UCHAR				"U_CHAR"
# define AT_SHORT				"SHORT"
# define AT_USHORT				"U_SHORT"
# define AT_INT					"INT"
# define AT_UINT				"U_INT"
# define AT_LONG				"LONG"
# define AT_ULONG				"U_LONG"
# define AT_LONGLONG			"LONG_LONG"
# define AT_ULONGLONG			"U_LONG_LONG"
# define AT_FLOAT				"FLOAT"
# define AT_DOUBLE				"DOUBLE"
# define AT_LONGDOUBLE			"LONG_DOUBLE"
# define AT_STRING				"STRING"
# define AT_VOID				"VOID"

/* The type of a list's content */
typedef enum list_cnt_type
{
	CHAR,
	U_CHAR,
	SHORT,
	U_SHORT,
	INT,
	U_INT,
	LONG,
	U_LONG,
	LONG_LONG,
	U_LONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	STRING,
	VOID,
	INVALID_TYPE
}	t_cnt_type;

/* This structure represents a command
 * entered by the user. Each command
 * has a type (e.g., 'man', 'new',
 * 'addfront', ...). A command may also
 * have an argument, in which case the
 * type of the argument must be specified */
typedef struct cmd
{
	char	type[MAX_CMD_TYPE_LEN];
	char	arg_type[MAX_CMD_ARG_TYPE_LEN];
	char	arg[MAX_CMD_ARG_LEN];
}	t_cmd;

/* This structure is designed to
 * store data used by the testing
 * component of a singly linked list.
 * Single pointers represent arrays
 * that store static (real) values
 * entered by the user via the
 * add_list_tests() function. Double
 * pointers represent arrays that
 * store other pointers, requiring
 * the user to allocate dynamic memory
 * before using them. The difference
 * between strs and strs_ptrs is that
 * the cells in the latter are filled
 * with NULL pointers*/
typedef struct lst_test
{
	int			nodes_num_to_free;
	void		*nodes_to_free[MAX_LST_NODES_NUM];
	void		*cnts_to_free[MAX_LST_NODES_NUM];
	int			counters[LST_DATA_TYPES_NUM * 2];

	char		*chars;
	u_char		*uchars;
	short		*shorts;
	u_short		*ushorts;
	int			*ints;
	u_int		*uints;
	long		*longs;
	t_ul		*ulongs;
	long long	*lls;
	t_ull		*ulls;
	float		*floats;
	double		*doubles;
	t_ld		*ldoubles;
	char		**strs;
	void		*voids;
	char		**chars_ptrs;
	u_char		**uchars_ptrs;
	short		**shorts_ptrs;
	u_short		**ushorts_ptrs;
	int			**ints_ptrs;
	u_int		**uints_ptrs;
	long		**longs_ptrs;
	t_ul		**ulongs_ptrs;
	long long	**lls_ptrs;
	t_ull		**ulls_ptrs;
	float		**floats_ptrs;
	double		**dbls_ptrs;
	t_ld		**ldbls_ptrs;
	char		**strs_ptrs;
	void		**voids_ptrs;
}	t_lst_test;

/* It represents a singly
 * linked list in a more
 * convenient format for
 * working with and debugging */
typedef struct list_debug
{
	t_cnt_type	*types;
	t_list		*head;
	int			type_cnt;
}	t_lst_d;

/* Main functions */
t_list		*lstnew_test(void *cnt, t_cnt_type type);
void		lstadd_front_test(t_list **head, t_list *new);
void		lstsize_test(t_list *head);
void		lstlast_test(t_lst_d *list);
void		lstadd_back_test(t_list **head, t_list *new);
void		lstdelone_test(t_list *n, t_lst_test *t, void (*f)(void *));

void		lstclear_test(t_lst_d *l,
				t_list **n,
				t_lst_test *t,
				void (*f)(void *));

void		lstiter_test(t_list *head, void (*test_func)(void *));

t_list		*lstmap_test(t_list *node,
				void *(*test_func)(void *), void (*del_func)(void *));

void		list_remove_if_test(t_list **head);

/* Auxiliary functions */

/* list_testing_funcs.c */
void		lstiter_func1(void *node_cnt);
void		lstiter_func2(void *node_cnt);
void		*lstmap_func1(void *node_cnt);
void		*lstmap_func2(void *node_cnt);

/* list_testing_funcs2.c */
void		del(void *node_cnt);
int			cmp(void *data1, void *data2);

/* list_aux.c */
int			print_list(t_lst_d *list, int ntabs);
void		insert_type_at_begin(t_cnt_type *t, int type_cnt, t_cnt_type type);
void		delete_type(t_cnt_type *types, int type_cnt, int type_pos);
int			lstsize(t_list *lst);
void		print_tabs(int n);

/* list_aux2.c */
void		addfront_quick(t_lst_d *list, void *cnt, t_cnt_type type, bool dbg);
void		addback_quick(t_lst_d *list, void *cnt, t_cnt_type type, bool dbg);
t_lst_d		*update_list(t_lst_d **old_list, t_list *new_list_head);
t_list		*get_node(t_lst_d *list, int node_ind);

/* list_aux3.c */
bool		cnt_was_freed(void *cnt, t_lst_test *tests);
bool		node_was_freed(void *node, t_lst_test *tests);
void		get_user_command(char *buf);
void		ask_user_test_type(char *choice);

/* list_aux4.c */
char		*create_format_str(void *cnt, t_cnt_type type);
void		process_arg(char *arg, void *cnt, t_cnt_type type);
void		process_numeric_arg(char *arg, void *cnt, t_cnt_type type);
void		process_non_numeric_arg(char *arg, void *cnt, t_cnt_type type);
void		print_parsed_cmd_args(t_cmd *command);

/* list_aux5.c */
t_cnt_type	determine_data_type(char *type);
t_cnt_type	check_numeric_data_types(char *type);
t_cnt_type	check_non_numeric_data_types(char *type);

/* list_cmd_parser.c */
int			parse_user_input(char *buf, t_cmd *cmd);
int			check_single_arg(t_cmd *cmd, char (*substrs)[MAX_CMD_SUBSTR_LEN]);
void		split_string_by_spaces(char *str, char (*subs)[MAX_CMD_SUBSTR_LEN]);
int			check_no_arg_cmd(char (*substrs)[MAX_CMD_SUBSTR_LEN]);
int			multi_arg_cmd(t_cmd *cmd);

/* list_cmd_parser2.c */
int			user_passed_args_crtly(t_cmd *c, char (*subs)[MAX_CMD_SUBSTR_LEN]);
int			arg_type_is_valid(t_cmd *cmd);
int			single_arg_cmd_is_crt(t_cmd *cmd, char (*subs)[MAX_CMD_SUBSTR_LEN]);
void		nullify_cmd_fields(t_cmd *cmd);

/* list_init.c */
t_lst_d		*list_debug_init(void *cnt, t_cnt_type type, bool debug);
void		init_list_tests(t_lst_test *tests);
void		nullify_static_list_tests(t_lst_test *tests);
void		nullify_heap_list_tests(t_lst_test *tests);

/* list_tests.c */
void		linked_list_launch_tests(t_lst_test *tests);
int			alloc_mem_for_tests(t_lst_test *tests);

/* list_tests2.c */
void		lst_print_man(void);

/* list_static_testing.c */
void		linked_list_launch_static_testing(t_lst_test *tests);
void		add_static_list_tests(t_lst_test *tests);

/* list_dynamic_testing.c */
void		linked_list_launch_dynamic_testing(t_lst_test *tests);
int			process_user_cmd(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
int			proc_user_cmd1(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
int			proc_user_cmd2(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
int			proc_user_cmd3(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);

/* list_dynamic_testing2.c */
int			proc_user_cmd4(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
int			proc_user_cmd5(t_cmd *c, t_lst_d **l);
int			proc_user_cmd6(t_cmd *cmd, t_lst_d **list);

/* list_cmd_new_processor.c */
int			process_cmd_new(t_lst_d **list, t_lst_test *tests, t_cmd *command);

/* list_cmd_new.c */
int			lstnew_char(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_uchar(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_short(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_ushort(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_int(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_new2.c */
int			lstnew_uint(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_long(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_ulong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_longlong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_ulonglong(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_new3.c */
int			lstnew_float(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_double(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_longdouble(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstnew_string(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addfront_processor.c */
int			process_cmd_addfront(t_lst_d **list, t_lst_test *tests, t_cmd *cmd);

/* list_cmd_addfront.c */
int			lstaddfront_char(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_uchar(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_short(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_ushort(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_int(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addfront2.c */
int			lstaddfront_uint(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_long(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_ulong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_longlong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_ulonglong(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addfront3.c */
int			lstaddfront_float(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_double(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddfront_longdouble(t_lst_d **list, t_lst_test *t, char *arg);
int			lstaddfront_string(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addback_processor.c */
int			process_cmd_addback(t_lst_d **list, t_lst_test *tests, t_cmd *cmd);

/* list_cmd_addback.c */
int			lstaddback_char(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_uchar(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_short(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_ushort(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_int(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addback2.c */
int			lstaddback_uint(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_long(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_ulong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_longlong(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_ulonglong(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_addback3.c */
int			lstaddback_float(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_double(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_longdouble(t_lst_d **list, t_lst_test *tests, char *arg);
int			lstaddback_string(t_lst_d **list, t_lst_test *tests, char *arg);

/* list_cmd_clear_processor.c */
int			process_cmd_clear(t_lst_d **l, t_lst_test *t, t_cmd *c, bool *lcrt);

/* list_cmd_del_processor.c */
int			process_cmd_del(t_lst_d **l, t_lst_test *t, t_cmd *c, bool *lcrt);

/* list_cmd_map_processor.c */
int			process_cmd_map(t_lst_d **list);

/* list_alloc.c */
int			alloc_lst_test_chars(t_lst_test *tests);
int			alloc_lst_test_uchars(t_lst_test *tests);
int			alloc_lst_test_shorts(t_lst_test *tests);
int			alloc_lst_test_ushorts(t_lst_test *tests);
int			alloc_lst_test_ints(t_lst_test *tests);

/* list_alloc2.c */
int			alloc_lst_test_uints(t_lst_test *tests);
int			alloc_lst_test_longs(t_lst_test *tests);
int			alloc_lst_test_ulongs(t_lst_test *tests);
int			alloc_lst_test_lls(t_lst_test *tests);
int			alloc_lst_test_ulls(t_lst_test *tests);

/* list_alloc3.c */
int			alloc_lst_test_floats(t_lst_test *tests);
int			alloc_lst_test_doubles(t_lst_test *tests);
int			alloc_lst_test_ldoubles(t_lst_test *tests);
int			alloc_lst_test_strings(t_lst_test *tests);
int			alloc_lst_test_strs(t_lst_test *tests);

/* list_alloc4.c */
int			alloc_lst_test_strs_ptrs(t_lst_test *tests);
int			alloc_lst_test_voids(t_lst_test *tests);
char		*alloc_char(char val);
u_char		*alloc_uchar(u_char val);
short		*alloc_short(short val);

/* list_alloc5.c */
u_short		*alloc_ushort(u_short val);
int			*alloc_int(int val);
u_int		*alloc_uint(u_int val);
long		*alloc_long(long val);
t_ul		*alloc_ulong(t_ul val);

/* list_alloc6.c */
t_ll		*alloc_longlong(t_ll val);
t_ull		*alloc_ulonglong(t_ull val);
float		*alloc_float(float val);
double		*alloc_double(double val);
t_ld		*alloc_ldouble(t_ld val);

/* list_alloc7.c */
char		*alloc_string(char *val);

/* list_free.c */
void		release_all_lst_tests(t_lst_test *tests);
void		free_numeric_lst_tests(t_lst_test *tests);
void		free_non_numeric_lst_tests(t_lst_test *tests);
void		free_list_debug(t_lst_d *list);

/* list_free2.c */
void		free_chars(t_lst_test *tests);
void		free_uchars(t_lst_test *tests);
void		free_shorts(t_lst_test *tests);
void		free_ushorts(t_lst_test *tests);
void		free_ints(t_lst_test *tests);

/* list_free3.c */
void		free_uints(t_lst_test *tests);
void		free_longs(t_lst_test *tests);
void		free_ulongs(t_lst_test *tests);
void		free_lls(t_lst_test *tests);
void		free_ulls(t_lst_test *tests);

/* list_free4.c */
void		free_floats(t_lst_test *tests);
void		free_doubles(t_lst_test *tests);
void		free_ldoubles(t_lst_test *tests);
void		free_strings(t_lst_test *tests);
void		free_strs(t_lst_test *tests);

/* list_free5.c */
void		free_strs_ptrs(t_lst_test *tests);
void		free_voids(t_lst_test *tests);

#endif
