/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_cmd_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 15:19:37 by dchernik          #+#    #+#             */
/*   Updated: 2025/02/01 15:19:42 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/list.h"
#include <limits.h>
#include <stdlib.h>

int	lstnew_char(t_lst_d **list, t_lst_test *tests, char *arg)
{
	int	pos;
	
	pos = tests->counters[(int)CHAR];
	if (strlen(arg) > 1)
	{
		printf("lstnew_char(): The passed argument is not a char\n");
		return (ERROR);
	}
	tests->chars_ptrs[pos] = alloc_char(arg[0]);
	*list = list_debug_init((char *)tests->chars_ptrs[pos], CHAR, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)CHAR]++;
	return (SUCCESS);
}

int	lstnew_uchar(t_lst_d **list, t_lst_test *tests, char *arg)
{
	int	pos;

	pos = tests->counters[(int)U_CHAR];
	if (strlen(arg) > 1)
	{
		printf("lstnew_uchar(): The passed argument is not an u_char\n");
		return (ERROR);
	}
	tests->uchars_ptrs[pos] = alloc_uchar(arg[0]);
	*list = list_debug_init((u_char *)tests->uchars_ptrs[pos], U_CHAR, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_CHAR]++;
	return (SUCCESS);
}

int	lstnew_short(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > SHRT_MAX || lst_data < SHRT_MIN)
	{
		printf("lstnew_short(): The passed argument is not a short\n");
		return (ERROR);
	}
	pos = tests->counters[(int)SHORT];
	tests->shorts_ptrs[pos] = alloc_short((short)lst_data);
	*list = list_debug_init((short *)tests->shorts_ptrs[pos], SHORT, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)SHORT]++;
	return (SUCCESS);
}

int	lstnew_ushort(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ull	lst_data;
	int		pos;

	lst_data = strtoull(arg, &stopstr, 10);
	if (lst_data > USHRT_MAX)
	{
		printf("lstnew_ushort(): The passed argument is not an u_short\n");
		return (ERROR);
	}
	pos = tests->counters[(int)U_SHORT];
	tests->ushorts_ptrs[pos] = alloc_ushort((u_short)lst_data);
	*list = list_debug_init((u_short *)tests->ushorts_ptrs[pos], U_SHORT, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)U_SHORT]++;
	return (SUCCESS);
}

int	lstnew_int(t_lst_d **list, t_lst_test *tests, char *arg)
{
	char	*stopstr;
	t_ll	lst_data;
	int		pos;

	lst_data = strtoll(arg, &stopstr, 10);
	if (lst_data > INT_MAX || lst_data < INT_MIN)
	{
		printf("lstnew_int(): The passed argument is not an int\n");
		return (ERROR);
	}
	pos = tests->counters[(int)INT];
	tests->ints_ptrs[pos] = alloc_int((int)lst_data);
	*list = list_debug_init((int *)tests->ints_ptrs[pos], INT, false);
	if (list == NULL)
		return (ERROR);
	tests->counters[(int)INT]++;
	return (SUCCESS);
}
