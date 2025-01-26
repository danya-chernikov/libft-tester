#include "../include/list.h"
#include "../include/putsmth_fd.h"
/* We included `putsmth_fd.h` to use
 * the `form_common_err_msg()` function */

/* This is the main function that launches all the tests */
void	linked_list_choose_testing_type(t_lst_test *tests)
{
	int		attempts_cnt;
	char	choice;

	attempts_cnt = 0;
	while (attempts_cnt < MAX_LST_ATTEMPTS_NUM)
	{
		lst_ask_user(&choice);
		if (choice == 'S')
		{
			add_static_list_tests(tests);
			linked_list_launch_static_testing(tests);
			break ;
		}
		else if (choice == 'D')
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

/* It performs dynamic testing of singly linked lists. It means
 * the user will have ability to construct thier own list using
 * predefined command set, entering each command in the loop
 * manually */
void	linked_list_launch_dynamic_testing(t_lst_test *tests)
{
	char		input_buf[MAX_USER_INPUT_BUF_LEN];
	t_cmd		command;
	t_lst_d		*list;
	t_list		*node;

	while (true)
	{
		printf("Enter command ('man' for help): ");
		get_line(input_buf);

		printf("input_buf = \"%s\"\n", input_buf);

		if (parse_user_input(input_buf, &command) == ERROR)
		{
			printf("You entered an incorrect command. Please try again.\n");
			continue ;
		}
		if (strcmp(cmd_type, CMD_MAN) == 0)
		{
			printf("\tman\n");
			print_parsed_cmd_args(&cmd);
			lst_print_man();
		}
		if (strcmp(cmd_type, CMD_NEW) == 0)
		{
			printf("\tnew\n");
			print_parsed_cmd_args(&cmd);
			process_cmd_new(list, tests, &cmd);
		}
		if (strcmp(cmd_type, CMD_ADDFRONT) == 0)
		{
			printf("\taddfront\n");
			print_parsed_cmd_args(&cmd);
			process_cmd_addfront(list, tests, &cmd);
		}
		if (strcmp(cmd_type, CMD_SIZE) == 0)
		{
			printf("\tsize\n");
			print_parsed_cmd_args(&cmd);
			lstsize_test(&list->head);
		}
		if (strcmp(cmd_type, CMD_LAST) == 0)
		{
			printf("\tlast\n");
			print_parsed_cmd_args(&cmd);
			lstlast_test(list->head, SHORT); // Improve this!
		}
		if (strcmp(cmd_type, CMD_ADDBACK) == 0)
		{
			printf("\taddback\n");
			print_parsed_cmd_args(&cmd);
			process_cmd_addback(list, tests, &cmd);
		}
		if (strcmp(cmd_type, CMD_CLEAR) == 0)
		{
			printf("\tclear\n");
			print_parsed_cmd_args(&cmd);
			process_cmd_clear(list, tests, &cmd);
		}
		if (strcmp(cmd_type, CMD_PRINT) == 0)
		{
			printf("\tprint\n");
			print_parsed_cmd_args(&cmd);
			print_list(list);
		}
		if (strcmp(cmd_type, CMD_QUIT) == 0)
		{
			printf("\tquit\n");
			print_parsed_cmd_args(&cmd);
			break ;
		}
	} // while (true)

	if (list != NULL)
		free_list_debug(list);
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

void	add_static_list_tests(t_lst_test *tests)
{
	tests->strs_ptrs[0] = alloc_string("just some text");
	tests->ints_ptrs[0] = alloc_int(10);
	tests->floats_ptrs[0] = alloc_float(5.6);
	tests->chars_ptrs[0] = alloc_char('X');
	tests->shorts_ptrs[0] = alloc_short(-512);
	tests->longs_ptrs[0] = alloc_long(1340802489);
	tests->ints_ptrs[1] = alloc_int(948010);
}
