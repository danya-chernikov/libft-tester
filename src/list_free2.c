#include "../include/list.h"

void	free_shorts(t_lst_test *tests)
{
	free(tests->shorts);
	tests->shorts = NULL;
}

void	free_ushorts(t_lst_test *tests)
{
	free(tests->ushorts);
	tests->ushorts = NULL;
}

void	free_ints(t_lst_test *tests)
{
	free(tests->ints);
	tests->ints = NULL;
}

void	free_uints(t_lst_test *tests)
{
	free(tests->uints);
	tests->uints = NULL;
}

void	free_longs(t_lst_test *tests)
{
	free(tests->longs);
	tests->longs = NULL;
}
