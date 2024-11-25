#include "../include/libft_tester.h"

static void	launch_tests(char const *funcname);
static void	test_helper(char const *funcname, int ntest, int ch);

/* Main function that tests ft_toupper(), launching both tests of our own
 * implementation and the same tests of the original toupper() from Glibc,
 * to be able to compare their results */
void	toupper_test()
{
	char const	our_funcname[] = "ft_toupper";
	char const	orig_funcname[] = "toupper";

	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

static void	test_helper(char const *funcname, int ntest, int ch)
{
	char const	format[] = "\t%d. %s%s%s('%c'(%d)) = ";

	printf(format, ntest, YELLOW, funcname, WHITE, ch, ch);
	if (strncmp(funcname, "ft_toupper", MAX_FUNC_NAME_LEN) == 0)
		printf("%c", ft_toupper(ch));
	else if (strncmp(funcname, "toupper", MAX_FUNC_NAME_LEN) == 0)
		printf("%c", toupper(ch));
	else
		printf("%c", ft_toupper(ch));
	printf("\n");
}

static void	launch_tests(char const *funcname)
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
