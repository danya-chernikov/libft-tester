#include "../include/list.h"

static int	proc_user_cmd1(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
static int	proc_user_cmd2(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
static int	proc_user_cmd3(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);
static int	proc_user_cmd4(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt);

/* It performs dynamic testing of singly linked lists. It means
 * the user will have ability to construct thier own list using
 * predefined command set, entering each command in the loop
 * manually.
 *     lcrt - a flag indicating whether a list was created or not */
void	linked_list_launch_dynamic_testing(t_lst_test *tests)
{
	char		input_buf[MAX_USER_INPUT_BUF_LEN];
	t_lst_d		*list;
	bool		lcrt;
	t_cmd		cmd;

	list = NULL;
	lcrt = false;
	fgets(input_buf, MAX_USER_INPUT_BUF_LEN, stdin);
	while (true)
	{
		printf("\nEnter command ('man' for help): ");
		//get_line(input_buf);
		fgets(input_buf, MAX_USER_INPUT_BUF_LEN, stdin);
		input_buf[strcspn(input_buf, "\n")] = '\0';
		if (parse_user_input(input_buf, &cmd) == ERROR)
		{
			printf("You entered an incorrect command. Please try again.\n");
			continue ;
		}
		if ((proc_user_cmd1(&cmd, &list, tests, &lcrt) == ERROR)
			|| (proc_user_cmd2(&cmd, &list, tests, &lcrt) == ERROR)
			|| (proc_user_cmd3(&cmd, &list, tests, &lcrt) == ERROR))
			continue ;
		if (proc_user_cmd4(&cmd, &list, tests, &lcrt) == SIGNAL_QUIT)
			break ;
	}
	if ((list != NULL) && (lcrt == true))
		free_list_debug(list);
}

static int	proc_user_cmd1(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if (strcmp(c->type, CMD_MAN) == 0)
	{
		printf("\tman\n");
		print_parsed_cmd_args(c);
		lst_print_man();
	}
	if (strcmp(c->type, CMD_NEW) == 0)
	{
		if (*lcrt == true)
		{
			printf("A list had aleady been created.\n");
			return (ERROR);
		}
		else
		{
			printf("\tnew\n");
			print_parsed_cmd_args(c);
			if (process_cmd_new(l, t, c) == ERROR)
				return (ERROR);
			else
				*lcrt = true;
		}
	}
	return (SUCCESS);
}

static int	proc_user_cmd2(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if (strcmp(c->type, CMD_ADDFRONT) == 0)
	{
		if (*lcrt == true)
		{
			printf("\taddfront\n");
			print_parsed_cmd_args(c);
			if (process_cmd_addfront(l, t, c) == ERROR)
				return (ERROR);
		}
		else
		{
			printf("Before working with a list, it must be created.\n");
			return (ERROR);
		}
	}
	return (SUCCESS);
}

static int	proc_user_cmd3(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if ((!strcmp(c->type, CMD_SIZE)
		|| !strcmp(c->type, CMD_LAST)
		|| !strcmp(c->type, CMD_ADDBACK)) && (*lcrt == false))
	{
		printf("Before working with a list, it must be created.\n");
		return (ERROR);
	}
	if (strcmp(c->type, CMD_SIZE) == 0)
	{
		printf("\tsize\n");
		print_parsed_cmd_args(c);
		lstsize_test(&(*l)->head);
	}
	if (strcmp(c->type, CMD_LAST) == 0)
	{
		printf("\tlast\n");
		print_parsed_cmd_args(c);
		lstlast_test(*l); // Improve this!
	}
	if (strcmp(c->type, CMD_ADDBACK) == 0)
	{
		printf("\taddback\n");
		print_parsed_cmd_args(c);
		if (process_cmd_addback(l, t, c) == ERROR)
			return (ERROR);
	}
	return (SUCCESS);
}

static int	proc_user_cmd4(t_cmd *c, t_lst_d **l, t_lst_test *t, bool *lcrt)
{
	if ((!strcmp(c->type, CMD_CLEAR)
		|| !strcmp(c->type, CMD_PRINT)) && (*lcrt == false))
	{
		printf("Before working with a list, it must be created.\n");
		return (ERROR);
	}
	if (strcmp(c->type, CMD_CLEAR) == 0)
	{
		printf("\tclear\n");
		print_parsed_cmd_args(c);
		if (process_cmd_clear(l, t, c, lcrt) == ERROR)
			return (ERROR);
	}
	if (strcmp(c->type, CMD_PRINT) == 0)
	{
		printf("\tprint\n");
		print_parsed_cmd_args(c);
		print_list(*l, 0);
	}
	if (strcmp(c->type, CMD_QUIT) == 0)
	{
		printf("\tquit\n");
		print_parsed_cmd_args(c);
		return (SIGNAL_QUIT);
	}
	return (SUCCESS);
}
