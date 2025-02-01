#include "../include/list.h"

/* It deletes a node specified by the cmd->arg variable. A node can be
 * specified as a number or as an address. Of course, if the user wants
 * to delete the first node of the list, the head pointer value in the
 * list structure must be updated. Furthermore, if the list contains only
 * one node and we are going to delete it, we should lower the `lcrt` flag
 * to indicate that the list has been removed */
int	process_del_clear(t_lst_d **list, t_lst_test *tests, t_cmd *cmd, bool *lcrt)
{
	t_list	*node;
	int		node_num;

	node_num = atoi(cmd->arg);
	if ((node_num < 0) || (node_num > lstsize(*list->head) - 1))
		return (ERROR);
	node = get_node(*list, node_num);
	if (node != NULL)
		lstdelone_test(*list, &node, del, tests);
	if (node_num == 0)
	{

	}
	if (lstsize(*list->head) == 1)
	{
		*lcrt = false;
	}
	return (SUCCESS);
}
