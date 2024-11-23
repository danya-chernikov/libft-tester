#ifndef MEMCMP_H
# define MEMCMP_H

#include <stddef.h>

void	memcmp_regular_tests(t_char_c *fname);
void	memcmp_special_tests(t_char_c *fcname);
void	memcmp_test_helper(t_char_c *fname, t_void_c *s1, t_void_c *s2, size_t n);

#endif
