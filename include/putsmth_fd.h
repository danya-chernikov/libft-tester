#ifndef PUTSMTH_FD_H
# define PUTSMTH_FD_H

/* putsmth_fd_aux.c */
void	ps_test_helper(t_char_c *fn, t_ps_tests *tests, t_func_id find, int tn);
int		ps_alloc_mem(t_char_c *fname, char **readbuf, char **errbuf);
void	ps_free_mem(char **readbuf, char **errbuf);
int		delete_temp_file(t_char_c *fname, char **errbuf);

/* putsmth_fd_regular.c */
void	ps_regular_tests(t_char_c *fn, t_ps_tests *tests, t_func_id fi, int tn);
void	call_putchar_fd(t_char_c *fname, t_ps_tests *tests, int test_ind);
void	call_putstr_fd(t_char_c *fname, t_ps_tests *tests, int test_ind);
void	call_putendl_fd(t_char_c *fname, t_ps_tests *tests, int test_ind);
void	call_putnbr_fd(t_char_c *fname, t_ps_tests *tests, int test_ind);

/* putsmth_fd_special.c */
int		ps_special_test(t_char_c *fn, void **pack, char **rbuf, char **errbuf);
int		create_temp_file(t_char_c *fname, int *fd, char **rbuf, char **errbuf);
int		open_temp_file(t_char_c *fname, int *fd, char **readbuf, char **errbuf);
int		read_temp_file(t_char_c *fname, int *fd, char **readbuf, char **errbuf);

/* putsmth_fd_write.c */
void	write_temp_file(t_char_c *fname, void **pack, int *fd);
void	putchar_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd);
void	putstr_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd);
void	putendl_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd);
void	putnbr_fd_write(t_char_c *fname, t_ps_tests *tests, int tnum, int *fd);

/* putsmth_fd_print.c */
void	print_special_test_res(t_char_c *fname, void **pack, char **readbuf);
void	print_putchar_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rb);
void	print_putstr_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rb);
void	print_putendl_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rb);
void	print_putnbr_res(t_char_c *fn, t_ps_tests *tests, int tnum, char **rb);

/* putsmth_fd_errors.c */
void	form_common_err_msg(char *buf, t_char_c *fname, t_char_c *msg);
void	form_common_file_err_msg(char *buf, t_char_c *fname, t_char_c *msg);

#endif
