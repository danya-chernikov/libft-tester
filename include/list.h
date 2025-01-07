#ifndef LIST_H
# define LIST_H

# include "libft_tester.h"

char	*create_format_str(void *cnt, t_cnt_type type);
void	process_numeric_arg(char *fstr, void *cnt, t_cnt_type type);
void	process_non_numeric_arg(char *fstr, void *cnt, t_cnt_type type);
void	print_list(t_list *head_ptr, int tabs);
void	free_node(void *ptr);

#endif
