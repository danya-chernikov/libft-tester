#include "../include/list.h"

bool	cnt_was_freed(void *cnt, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = false;
	while (i < tests->nodes_num_to_free)
	{
		if (cnt == tests->cnts_to_free[i])
		{
			was_freed = true;
			break;
		}
		i++;
	}
	return (was_freed);
}

bool	node_was_freed(void *node, t_lst_test *tests)
{
	bool	was_freed;
	int		i;

	i = 0;
	was_freed = false;
	while (i < tests->nodes_num_to_free)
	{
		if (node == tests->nodes_to_free[i])
		{
			was_freed = true;
			break;
		}
		i++;
	}
	return (was_freed);
}

/* It just gets line from the
 * standard input and puts it
 * into `str` array */
void	get_line(char *str)
{
	int	ch;
	int	i;

	i = 0;
	while (i < MAX_USER_INPUT_BUF_LEN)
	{
		ch = getchar();
		if (ch == '\n' || ch == EOF)
			break ;
		str[i] = ch;
		i++;
	}
	str[i] = '\0';
}
