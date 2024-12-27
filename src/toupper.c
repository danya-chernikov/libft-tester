#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *funcname);
static void	test_helper(t_char_c *funcname, int ntest, int ch);

/* Main function that tests
 * ft_toupper(), launching
 * both tests of our own
 * implementation and the
 * same tests of the original
 * toupper() from Glibc, to be
 * able to compare their results */
void	toupper_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strncpy(our_funcname, "ft_toupper", MAX_FUNC_NAME_LEN);
	strncpy(orig_funcname, "toupper", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	test_helper(t_char_c *funcname, int ntest, int ch)
{
	char	format[MAX_FORMAT_STR_LEN];

	strncpy(format, "\t%d. %s%s%s('%c'(%d)) = ", MAX_FORMAT_STR_LEN);
	printf(format, ntest, YELLOW, funcname, WHITE, ch, ch);
	if (strncmp(funcname, "ft_toupper", MAX_FUNC_NAME_LEN) == 0)
		printf("%c", ft_toupper(ch));
	else if (strncmp(funcname, "toupper", MAX_FUNC_NAME_LEN) == 0)
		printf("%c", toupper(ch));
	else
		printf("%c", ft_toupper(ch));
	printf("\n");
}

static void	launch_tests(t_char_c *funcname)
{
	char	*cur_loc;

	cur_loc = setlocale(LC_ALL, NULL);
	printf("\tCurrent locale is %s\n", cur_loc);
	test_helper(funcname, 1, 'A');
	test_helper(funcname, 2, 'b');
	test_helper(funcname, 3, 'C');
	test_helper(funcname, 4, 'Z');
	test_helper(funcname, 5, 'z');
	test_helper(funcname, 6, EOF);
	test_helper(funcname, 7, '*');
	test_helper(funcname, 8, '1');
}
