#include "../include/list.h"

void	free_ulongs(t_lst_test *tests)
{
	free(tests->ulongs);
	tests->ulongs = NULL;
}

void	free_lls(t_lst_test *tests)
{
	free(tests->lls);
	tests->lls = NULL;
}

void	free_ulls(t_lst_test *tests)
{
	free(tests->ulls);
	tests->ulls = NULL;
}

void	free_floats(t_lst_test *tests)
{
	free(tests->floats);
	tests->floats = NULL;
}

void	free_doubles(t_lst_test *tests)
{
	free(tests->doubles);
	tests->doubles = NULL;
}
