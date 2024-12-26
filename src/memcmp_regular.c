#include "../include/libft_tester.h"
#include "../include/memcmp.h"

static void	regular_test(t_char_c *fname, int ntest, int n);
static void	regular_test_strs(t_char_c *fname, int ntest, char *strs, int n);

void	memcmp_regular_tests(t_char_c *fname)
{
	regular_test(fname, 1, 5 * sizeof(int));
	regular_test(fname, 2, 0);
	regular_test_strs(fname, 3, pack_strs("ß¶©", "ß¶©"), strlen("ß¶©"));
	regular_test_strs(fname, 4, pack_strs("ß¶®", "ß¶©"), strlen("ß¶®"));
	regular_test_strs(fname, 5, pack_strs("ß¶©", "ß¶®"), strlen("ß¶©"));
	regular_test_strs(fname, 6, pack_strs("ß¶©Ø", "ß¶©  "), strlen("ß¶©Ø"));
}

static void	regular_test(t_char_c *fname, int ntest, int n)
{
	int		arr1[5];
	int		arr2[5];

	fill_arr_int(arr1, 1, 1, sizeof (arr1) / sizeof (int));
	fill_arr_int(arr2, 1, 1, sizeof (arr2) / sizeof (int));
	printf("\t%d. ", ntest);
	memcmp_test_helper(fname, (void *)arr1, (void *)arr2, n);
}

static void	regular_test_strs(t_char_c *fname, int ntest, char *strs, int n)
{
	char	s1[MAX_STRNCMP_STR_LEN];
	char	s2[MAX_STRNCMP_STR_LEN];

	printf("\t%d. ", ntest);
	unpack_strs(strs, s1, s2);
	memcmp_test_helper(fname, s1, s2, n);
}
