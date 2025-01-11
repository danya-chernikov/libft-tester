#include "../include/list.h"

void	init_lst_tests(t_lst_test *tests)
{
	tests->chars = NULL;
	tests->uchars = NULL;
	tests->shorts = NULL;
	tests->ushorts = NULL;
	tests->ints = NULL;
	tests->uints = NULL;
	tests->longs = NULL;
	tests->ulongs = NULL;
	tests->lls = NULL;
	tests->ulls = NULL;
	tests->floats = NULL;
	tests->doubles = NULL;
	tests->ldoubles = NULL;
	tests->strs = NULL;
	tests->voids = NULL;
}

int		alloc_lst_test_chars(t_lst_test *tests)
{
	tests->chars = (char *)malloc(MAX_LST_NODES_NUM * sizeof (char));
	if (tests->chars == NULL)
		return (0);
	return (1);
}

int		alloc_lst_test_uchars(t_lst_test *tests)
{
	tests->uchars = (u_char *)malloc(MAX_LST_NODES_NUM * sizeof (u_char));
	if (tests->uchars == NULL)
		return (0);
	return (1);
}

int		alloc_lst_test_shorts(t_lst_test *tests)
{
	tests->shorts = (short *)malloc(MAX_LST_NODES_NUM * sizeof (short));
	if (tests->shorts == NULL)
		return (0);
	return (1);
}

int		alloc_lst_test_ushorts(t_lst_test *tests)
{
	tests->ushorts = (u_short *)malloc(MAX_LST_NODES_NUM * sizeof (u_short));
	if (tests->ushorts == NULL)
		return (0);
	return (1);
}
