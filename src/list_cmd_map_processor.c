/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_map_processor.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:15:52 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/03 19:40:47 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

/* In case if (new_list == NULL) we
 * must somehow release memory of the
 * list with the head `new_list_head` */
int	process_cmd_map(t_lst_d **list)
{
	t_lst_d		*new_list;
	t_list		*new_list_head;
	void		(*func_ptr)(void *);

	func_ptr = lstmap_func1;
	new_list_head = lstmap_test((*list)->head, func_ptr, del);
	if (new_list == NULL)
		return (ERROR);
	else
	{
		new_list = update_list(&list, new_list_head);
		if (new_list == NULL)
		{
			return (ERROR);
		}
		free_list_debug(list);
		*list = new_list;
	}
	return (SUCCESS);
}
