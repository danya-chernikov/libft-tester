#include "../include/libft_tester.h"
#include "../include/memcmp.h"

static void	special_test_1(char const *fname, int ntest);
static void	special_test_2(char const *fname, int ntest);
static void	special_test_3(char const *fname, int ntest);

void	memcmp_special_tests(char const *funcname)
{
	special_test_1(funcname, 7);
	special_test_2(funcname, 8);
	special_test_3(funcname, 9);
}

static void	special_test_1(char const *fname, int ntest)
{
	char data1[6] = {'a', 'b', 'c', 'd', 'e', 'f'};
	char data2[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

	printf("\t%d. ", ntest);
	memcmp_test_helper(fname, (void *)data1, (void *)data2, 6 * sizeof(char));
}

static void	special_test_2(char const *fname, int ntest)
{
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {1, 2, 3, 4, 5};

	printf("\t%d. ", ntest);
	arr2[4] = 6;
	memcmp_test_helper(fname, (void *)arr1, (void *)arr2, 5 * sizeof(int));
}

static void	special_test_3(char const *fname, int ntest)
{
	int arr1[5] = {1, 2, 3, 4, 5};
	int arr2[5] = {1, 2, 3, 4, 5};

	printf("\t%d. ", ntest);
	arr1[4] = 6;
	arr2[4] = 5;
	memcmp_test_helper(fname, (void *)arr1, (void *)arr2, 5 * sizeof(int));
}
