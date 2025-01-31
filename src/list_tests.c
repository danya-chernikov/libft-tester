#include "../include/list.h"
#include "../include/putsmth_fd.h"
/* We included `putsmth_fd.h` to use
 * the `form_common_err_msg()` function */

/* This is the main function that launches all the tests */
void	linked_list_launch_tests(t_lst_test *tests)
{
	int		attempts_cnt;
	char	choice;

	attempts_cnt = 0;
	while (attempts_cnt < MAX_LST_ATTEMPTS_NUM)
	{
		ask_user_test_type(&choice);
		if (choice == CHOICE_STATIC[0])
		{
			add_static_list_tests(tests);
			linked_list_launch_static_testing(tests);
			break ;
		}
		else if (choice == CHOICE_DYNAMIC[0])
		{
			linked_list_launch_dynamic_testing(tests);
			break ;
		}
		else
		{
			printf("You've entered an invalid input. Please try again.\n\n");
			attempts_cnt++;
			continue ;
		}
	}
}

int	alloc_mem_for_tests(t_lst_test *tests)
{
	char	fname[MAX_FUNC_NAME_LEN];
	char	errbuf[MAX_ERR_BUF_SIZE];

	strncpy(fname, "create_list_tests", MAX_FUNC_NAME_LEN);
	if (!alloc_lst_test_chars(tests)
		|| !alloc_lst_test_uchars(tests)
		|| !alloc_lst_test_shorts(tests)
		|| !alloc_lst_test_ushorts(tests)
		|| !alloc_lst_test_ints(tests)
		|| !alloc_lst_test_uints(tests)
		|| !alloc_lst_test_longs(tests)
		|| !alloc_lst_test_ulongs(tests)
		|| !alloc_lst_test_lls(tests)
		|| !alloc_lst_test_ulls(tests)
		|| !alloc_lst_test_floats(tests)
		|| !alloc_lst_test_doubles(tests)
		|| !alloc_lst_test_ldoubles(tests)
		|| !alloc_lst_test_strings(tests)
		|| !alloc_lst_test_voids(tests))
	{
		form_common_err_msg(errbuf, fname, MEM_ERR_MSG);
		perror(errbuf);
		return (ERROR);
	}
	return (SUCCESS);
}
