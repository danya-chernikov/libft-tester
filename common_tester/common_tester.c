/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tester.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:11 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/20 19:33:40 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tester.h"

void	print_test_header(const char *funcname)
{
	int	i;

	i = 0;
	putchar('\n');
	while (i < TEST_HD_FT_LEN)
	{
		putchar(TEST_HD_FT_SYM);
		i++;
	}
	putchar('\n');
	cprintf(GREEN, "TEST OF %s()\n\n", funcname);
}

void	print_test_footer(void)
{
	int	i;

	i = 0;
	putchar('\n');
	while (i < TEST_HD_FT_LEN)
	{
		putchar(TEST_HD_FT_SYM);
		i++;
	}
	printf("\n\n");
}

/*
 * It unites two strings into a new one using ':' as a delimiter and
 * returns a pointer to this new string. We use this auxiliary function
 * during testing strncmp() to combine two variables into one. We are
 * doing this to reduce the number of arguments passed to strncmp()
 * from five to four, as functions can accept no more than four
 * arguments according to the Norm. After calling this function, you
 * must call unpack_strs() later or manually free the memory associated
 * with the returned pointer */
char	*pack_strs(t_char_c *s1, t_char_c *s2)
{
	char    *res;
    size_t  s1_len;
    size_t  s2_len;
    size_t  i;

    s1_len = strlen(s1);
    s2_len = strlen(s2);
    res = (char *)malloc(s1_len + s2_len + 2);
    if (res == NULL)
        return (NULL);
    i = 0;
    while (i < s1_len)
    {
        res[i] = s1[i];
        i++;
    }
    res[i++] = ':';
    while (i < s1_len + s2_len + 1)
    {
        res[i] = s2[i - s1_len - 1];
        i++;
    }
    res[i] = '\0';
    return (res);
}

/* It divides the strings united by pack_strs() using ':' as a delimiter.
 * Also, it frees memory allocated by pack_strs(). It returns zero if the
 * passed strs argument does not contain the delimiter */
int	unpack_strs(char *strs, char *s1, char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (strs[i] != ':')
	{
		if (strs[i] == '\0')
			return (0);
		s1[i] = strs[i];
		i++;
	}
	s1[i] = '\0';
	i++;
	j = 0;
	while (strs[i] != '\0')
	{
		s2[j] = strs[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	free(strs);
	return (1);
}
