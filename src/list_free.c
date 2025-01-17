#include "../include/list.h"

void	delete_all_lst_tests(t_lst_test *tests)
{
	free_numeric_lst_tests(tests);
	free_non_numeric_lst_tests(tests);
}

void	free_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->shorts)
		free_shorts(tests);
	printf("after free_shorts()\n");
	if (tests->ushorts)
		free_ushorts(tests);
	printf("after free_ushorts()\n");
	if (tests->ints)
		free_ints(tests);
	printf("after free_ints()\n");
	if (tests->uints)
		free_uints(tests);
	printf("after free_uints()\n");
	if (tests->longs)
		free_longs(tests);
	printf("after free_long()\n");
	if (tests->ulongs)
		free_ulongs(tests);
	printf("after free_ulong()\n");
	if (tests->lls)
		free_lls(tests);
	printf("after free_lls()\n");
	if (tests->ulls)
		free_ulls(tests);
	printf("after free_ulls()\n");
	if (tests->floats)
		free_floats(tests);
	printf("after free_floats()\n");
	if (tests->doubles)
		free_doubles(tests);
	printf("after free_doubles()\n");
	if (tests->ldoubles)
		free_ldoubles(tests);
	printf("after free_ldoubles()\n");
}

void	free_non_numeric_lst_tests(t_lst_test *tests)
{
	if (tests->chars)
		free_chars(tests);
	printf("after free_chars()\n");
	if (tests->uchars)
		free_uchars(tests);
	printf("after free_uchars()\n");
	if (tests->strs)
		free_lst_test_strs(tests);
	printf("after free_lst_test_strs()\n");
	if (tests->voids)
		free_voids(tests);
	printf("after free_voids()\n");
}

void	free_list_debug(t_lst_d *list)
{
	if (list->types != NULL)
	{
		free(list->types);
		list->types = NULL;
	}
	if (list != NULL)
	{
		free(list);
		list = NULL;
	}
}

/* This function is used to test
 * how the ft_lstdelone() works */
void	del(void *node_cnt)
{
	printf("del() says hello!\n");
	printf("node_cnt = %p\n", node_cnt);
	if (node_cnt != NULL)
	{
		free(node_cnt);
	}
}
