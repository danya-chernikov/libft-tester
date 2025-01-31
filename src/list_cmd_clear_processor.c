#include "../include/list.h"

int	process_cmd_clear(t_lst_d **list, t_lst_test *tests, t_cmd *command, bool *lcrt)
{
	printf("process_cmd_clear()\n");
	t_list	*node;
	int		node_num;

	node_num = atoi(command->arg);
	node = get_node(*list, node_num);
	if (node != NULL)
		lstclear_test(*list, &node, del, tests);
	if (node_num == 0)
<<<<<<< HEAD
		*lcrt = false;
=======
	{
		*lcrt = false;
		free_list_debug(*list);
		list = NULL;
	}
>>>>>>> 5cfd34b8bf85c7a5093477b008c55c21fda46580
	return (SUCCESS);
}
