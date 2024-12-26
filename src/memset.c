/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:52:35 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 17:08:11 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

static void	launch_tests(t_char_c *funcname);
static void	test_array(t_char_c *funcname, int ntest, int c);
static void	test_helper(t_char_c *funcname, int ntest, int c, int n);

/* Main function that tests ft_memset().
 * As usual, it prints the standar test
 * header, then launches tests of our
 * implementation of the memset() function,
 * followed by the same tests for the
 * original memset() function from Glibc,
 * to be able to compare their results.
 * Finally, it prints the standard footer
 * stub that visually indicates the end
 * of testing */
void	memset_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];
	char	orig_funcname[MAX_FUNC_NAME_LEN];

	strlcpy(our_funcname, "ft_memset", MAX_FUNC_NAME_LEN);
	strlcpy(orig_funcname, "memset", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	printf("true %s() from LibC:\n", orig_funcname);
	launch_tests(orig_funcname);
	print_test_footer();
}

/* It launches all the memset() tests we have:
 * both the common tests and the special test */
static void	launch_tests(t_char_c *funcname)
{
	test_helper(funcname, 1, '\0', 64);
	test_helper(funcname, 2, 0x41, 63);
	test_helper(funcname, 3, 0x42, 1);
	test_array(funcname, 4, 0x01);
}

/* It's a common test case */
static void	test_helper(t_char_c *funcname, int ntest, int c, int n)
{
	char		buf[64];
	char		*ptr;
	
	if (strncmp(funcname, "ft_memset", MAX_FUNC_NAME_LEN) == 0)
		ptr = ft_memset(buf, c, n);
	else if (strncmp(funcname, "memset", MAX_FUNC_NAME_LEN) == 0)
		ptr = memset(buf, c, n);
	else
		ptr = ft_memset(buf, c, n);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", funcname);
	printf("(buf, %d, %d) = \"%p\"\n", c, n, ptr);
	printf("\t\t");
	print_bytes(buf, 70);
}

/* It's a special case where we are
 * testing memset with an integer array */
static void	test_array(t_char_c *funcname, int ntest, int c)
{
	int			arr[10];
	char		buf[64];
	int			*ptr;

	fill_arr_int(arr, 1, 1, sizeof (arr) / sizeof (int));
	ptr = arr;
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", funcname);
	printf("(arr, %d, %lu) = \"%p\"\n", c, sizeof(arr), ptr);
	printf("\t\tarr before ft_memset: ");
	print_arr_int(arr, sizeof(arr) / sizeof(int));
	printf("\t\t");
	print_bytes(arr, sizeof(arr) + 5);
	if (strncmp(funcname, "ft_memset", MAX_FUNC_NAME_LEN) == 0)
		ptr = ft_memset(buf, c, sizeof(arr));
	else if (strncmp(funcname, "memset", MAX_FUNC_NAME_LEN) == 0)
		ptr = memset(buf, c, sizeof(arr));
	else
		ptr = ft_memset(buf, c, sizeof(arr));
	printf("\t\tarr after ft_memset: ");
	print_arr_int(arr, sizeof(arr) / sizeof(int));
	printf("\t\t");
	print_bytes(arr, sizeof(arr) + 5);
}
