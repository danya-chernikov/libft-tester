#include "../include/list.h"

int	process_cmd_clear(t_lst_d *list, t_lst_test *tests, t_cmd *command)
{
	printf("process_cmd_clear()\n");
	t_list	*node;
	int		node_num;

	node_num = atoi(command->arg);
	node = get_node(list, node_num);
	if (node != NULL)
		lstclear_test(list, &node, del, tests);
	return (SUCCESS);
}
