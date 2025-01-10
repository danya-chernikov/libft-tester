#ifndef LIST_H
# define LIST_H

# include "libft_tester.h"

char	*create_format_str(void *cnt, t_cnt_type type);
void	process_numeric_arg(char *arg, void *cnt, t_cnt_type type);
void	process_non_numeric_arg(char *arg, void *cnt, t_cnt_type type);
int		print_list(t_list *head_ptr, t_cnt_type *types, int ntabs);
void	addfront_quick(t_list **head_ptr, void *cnt, t_cnt_type type);
int		lstsize(t_list **lst);
void	print_tabs(int n);
void	free_node(void *ptr);

#endif
