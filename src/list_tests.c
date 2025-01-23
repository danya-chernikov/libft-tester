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
		if (choice[0] == 'S')
		{
			lst_ask_user(&choice);
			linked_list_launch_static_testing(tests);
			break ;
		}
		else if (choice[0] == 'D')
		{
			linked_list_launch_dynamic_testing(tests);
			break ;
		}
		else
		{
			printf("You've entered an invalid input Please try again.\n\n");
			attempts_cnt++;
			continue ;
		}
	}
}

/* It performs static testing of a singly linked list,
 * i.e., this function launches predefined tests that
 * can be easily hardcoded into its body, by the way */
void	linked_list_launch_static_testing(t_lst_test *tests)
{
	t_lst_d	*list;
	t_list	*node;

	list = list_debug_init((char *)tests->strs_ptrs[0], STRING);
	if (list == NULL)
		return ;
	addfront_quick(list, (int *)tests->ints_ptrs[0], INT, true);
	addfront_quick(list, (float *)tests->floats_ptrs[0], FLOAT, true);
	lstlast_test(list->head, STRING);
	addfront_quick(list, (char *)tests->chars_ptrs[0], CHAR, true);
	addback_quick(list, (short *)tests->shorts_ptrs[0], SHORT, true);
	lstlast_test(list->head, SHORT);
	addback_quick(list, (long *)tests->longs_ptrs[0], LONG, true);
	addback_quick(list, (int *)tests->ints_ptrs[1], INT, true);
	node = get_node(list, 4);
	if (node != NULL)
		lstclear_test(list, &node, del, tests);
	print_list(list, 0);
	lstsize_test(&list->head);
	free_list_debug(list);
}

/* It performs  */
void	linked_list_launch_dynamic_testing(t_lst_test *tests)
{
	char	cmd[MAX_CMD_BUF_LEN];
	int		attempts_cnt;
	t_lst_d	*list;
	//t_list	*node;

	attempts_cnt = 0;
	while (attempts_cnt < MAX_LST_ATTEMPTS_NUM)
	{
		printf("Enter command ('man' for help): ");
		get_line(cmd);
		if (strcmp(cmd, CMD_MAN))
		{
			lst_print_man();
		}
		else if (strcmp(cmd, CMD_NEW))
		{
			printf("new\n");
			list = list_debug_init((char *)tests->strs_ptrs[0], STRING);
			if (list == NULL)
				return ;
		}
		else if (strcmp(cmd, CMD_ADDFRONT))
		{
			printf("addfront\n");
		}
		else if (strcmp(cmd, CMD_SIZE))
		{
			printf("size\n");
		}
		else if (strcmp(cmd, CMD_LAST))
		{
			printf("last\n");
		}
		else if (strcmp(cmd, CMD_ADDBACK))
		{
			printf("addback\n");
		}
		else if (strcmp(cmd, CMD_CLEAR))
		{
			printf("clear\n");
		}
		else if (strcmp(cmd, CMD_QUIT))
		{
			printf("quit\n");
			break ;
		}
		else
		{
			printf("You entered an incorrect command. Please try again.\n");
			attempts_cnt++;
		}
	}
	if (list != NULL)
		free_list_debug(list);
}

int	create_list_tests(t_lst_test *tests)
{
	char	fname[MAX_FUNC_NAME_LEN];
	char	errbuf[MAX_ERR_BUF_SIZE];

	strncpy(fname, "create_list_tests", MAX_FUNC_NAME_LEN);
	init_list_tests(tests);
	if ((alloc_lst_test_strings(tests) == ERROR)
		|| (alloc_lst_test_ints(tests) == ERROR)
		|| (alloc_lst_test_floats(tests) == ERROR)
		|| (alloc_lst_test_chars(tests) == ERROR)
		|| (alloc_lst_test_shorts(tests) == ERROR)
		|| (alloc_lst_test_longs(tests) == ERROR))
	{
		form_common_err_msg(errbuf, fname, MEM_ERR_MSG);
		perror(errbuf);
		return (ERROR);
	}
	add_list_tests(tests);
	return (SUCCESS);
}

void	add_list_tests(t_lst_test *tests)
{
	tests->strs_ptrs[0] = alloc_string("just some text");
	tests->ints_ptrs[0] = alloc_int(10);
	tests->floats_ptrs[0] = alloc_float(5.6);
	tests->chars_ptrs[0] = alloc_char('X');
	tests->shorts_ptrs[0] = alloc_short(-512);
	tests->longs_ptrs[0] = alloc_long(1340802489);
	tests->ints_ptrs[1] = alloc_int(948010);
}
