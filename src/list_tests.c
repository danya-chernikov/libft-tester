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
		lst_ask_user(&choice);
		if (choice == 'S')
		{
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

/* It performs  */
void	linked_list_launch_dynamic_testing(t_lst_test *tests)
{
	char	input_buf[MAX_USER_INPUT_BUF_LEN];
	char	cmd_type[MAX_CMD_TYPE_LEN];
	char	arg_type[MAX_CMD_ARG_TYPE_LEN];
	char	arg[MAX_CMD_ARG_LEN];

	int		attempts_cnt;
	t_lst_d	*list;
	t_list	*node;

	attempts_cnt = 0;
	while (attempts_cnt < MAX_LST_ATTEMPTS_NUM)
	{
		printf("Enter command ('man' for help): ");
		get_line(input_buf);
		if (parse_user_input(input_buf, cmd_type, arg_type, arg) == ERROR)
		{
			printf("You entered an incorrect command. Please try again.\n");
			attempts_cnt++;
			continue ;
		}
		if (strcmp(cmd_type, CMD_MAN) == 0)
		{
			lst_print_man();
		}
		else if (strcmp(cmd_type, CMD_NEW) == 0)
		{
			printf("new\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);

			t_cnt_type	data_type;

			data_type = determine_data_type(arg_type);
			if (data_type == CHAR)
			{
				int	pos = counters[(int)CHAR];

				if (strlen(arg) > 1)
				{
					printf("The passed argument is not a char\n");
					break ;
				}
				tests->chars_ptrs[pos] = alloc_char(arg[0]);
				list = list_debug_init((char *)tests->chars_ptrs[pos], data_type);
				if (list == NULL)
					return ;
				counters[(int)CHAR]++;
			}
			if (data_type == U_CHAR)
			{

			}
			if (data_type == SHORT)
			{

			}
			if (data_type == U_SHORT)
			{

			}
			if (data_type == INT)
			{

			}
			if (data_type == U_INT)
			{

			}
			if (data_type == LONG)
			{

			}
			if (data_type == U_LONG)
			{

			}
			if (data_type == LONG_LONG)
			{

			}
			if (data_type == U_LONG_LONG)
			{

			}
			if (data_type == FLOAT)
			{

			}
			if (data_type == DOUBLE)
			{

			}
			if (data_type == LONG_DOUBLE)
			{

			}
			if (data_type == STRING)
			{

			}
			if (data_type == INVALID_TYPE)
			{
				printf("You entered an invalid argument\n");
				break ;
			}
		}
		else if (strcmp(cmd_type, CMD_ADDFRONT) == 0)
		{
			printf("addfront\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
		}
		else if (strcmp(cmd_type, CMD_SIZE) == 0)
		{
			printf("size\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
		}
		else if (strcmp(cmd_type, CMD_LAST) == 0)
		{
			printf("last\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
		}
		else if (strcmp(cmd_type, CMD_ADDBACK) == 0)
		{
			printf("addback\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
		}
		else if (strcmp(cmd_type, CMD_CLEAR) == 0)
		{
			printf("clear\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
		}
		else if (strcmp(cmd_type, CMD_QUIT) == 0)
		{
			printf("quit\n");
			printf("\tinput_buf = \"%s\"\n", input_buf);
			printf("\tcmd_type = \"%s\"\n", cmd_type);
			printf("\targ_type = \"%s\"\n", arg_type);
			printf("\targ = \"%s\"\n", arg);
			break ;
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
