/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tests2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:21:34 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 16:53:46 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"

void	lst_print_man(void)
{
	printf("Usage: {command} [contenttype] [content]\n");
	printf("command\n");
	printf("\tman\n");
	printf("\t\tGet this manual page\n");
	printf("\tnew {contenttype} {content}\n");
	printf("\t\tCreates a new list and initializes it with content\n");
	printf("\taddfront {contenttype} {content}\n");
	printf("\t\tAdds a node at the beginning of the list\n");
	printf("\tsize\n");
	printf("\t\tReturns the size of the list\n");
	printf("\tlast\n");
	printf("\t\tReturns the last node of the list\n");
	printf("\taddback {contenttype} {content}\n");
	printf("\t\tAdds a node at the end of the list\n");
	printf("\tclear {nodenumber}\n");
	printf("\t\tClears the list starting from the node that has "
		"the `nodenumber` position in the list (by count)\n");
	printf("\tPossible types of content are: CHAR, U_CHAR, SHORT, U_SHORT, "
		"INT, U_INT, LONG, U_LONG, LONG_LONG, U_LONG_LONG, FLOAT, DOUBLE, "
		"LONG_DOUBLE, STRING, VOID\n");
}
