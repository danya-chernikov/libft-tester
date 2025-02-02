#include "../include/list.h"

/* It deletes a node specified by the `cmd->arg` variable. A node can be
 * specified as a number or as an address. Of course, if the user wants
 * to delete the first node of the list, the head pointer value in the
 * list structure must be updated. Furthermore, if the list contains only
 * one node and we are going to delete it, we should lower the `lcrt` flag
 * to indicate that the list has been removed */
int	process_cmd_del(t_lst_d **list, t_lst_test *tests, t_cmd *cmd, bool *lcrt)
{
	int		node_num;
    int     lsize;
	t_list	*node;
    t_list  *ni;
    t_list  *next;

    lsize = lstsize(&(*list)->head);
	node_num = atoi(cmd->arg);

	if ((node_num < 0) || (node_num > lsize - 1))
		return (ERROR);

	node = get_node(*list, node_num);
	if (node != NULL)
    {
        if (node_num > 0 && node_num < lsize - 1)
            next = node->next;
		lstdelone_test(node, tests, del);
    }

    delete_type((*list)->types, (*list)->type_cnt, node_num);
	(*list)->type_cnt--;

    ni = (*list)->head;
	if (node_num == 0)
    {
        if (lsize == 1)
		    *lcrt = false;
        else if (lsize > 1)
            (*list)->head = (*list)->head->next;
    }
    else if (node_num == lsize - 1)
    {
        while (ni->next != node)
            ni = ni->next;
        ni->next = NULL;
    }
    else
    {
        while (ni->next != node)
            ni = ni->next;
        ni->next = next;
    }
	return (SUCCESS);
}
