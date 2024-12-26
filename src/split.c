/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:53:32 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 17:07:45 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/split.h"

static void	launch_tests(t_char_c *fname);
static char	*prepare_long_str(void);
static void	test_helper(t_char_c *fname, int ntest, t_char_c *str, char delim);
static void	call_split(t_char_c *fn, t_char_c *str, char delim);

void	split_test(void)
{
	char	our_funcname[MAX_FUNC_NAME_LEN];

	strlcpy(our_funcname, "ft_split", MAX_FUNC_NAME_LEN);
	print_test_header(our_funcname);
	printf("%s():\n", our_funcname);
	launch_tests(our_funcname);
	print_test_footer();
}

/* For the 17th test, we placed the string
 * in a buffer using memmove() because the
 * string contains null bytes */
static void	launch_tests(t_char_c *fname)
{
	char	buf[MAX_SPLIT_STR_LEN];

	test_helper(fname, 1, "uhfe:uiwhg328:gjrg:::3r3gEF:434t", ':');
	test_helper(fname, 2, "a:b:c:d:e:f:g:h", ':');
	test_helper(fname, 3, "-------", '-');
	test_helper(fname, 4, "a:b", '-');
	test_helper(fname, 5, ":a:", ':');
	test_helper(fname, 6, ":a:", 'a');
	test_helper(fname, 7, "::", ':');
	test_helper(fname, 8, ":", ':');
	test_helper(fname, 9, "", ':');
	test_helper(fname, 10, "", '\0');
	test_helper(fname, 11, "word", '\0');
	test_helper(fname, 12, "    :        :   a     :    : :", ':');
	test_helper(fname, 13, "just a string without a delimiter sign", ':');
	test_helper(fname, 14, "          ", ' ');
	test_helper(fname, 15, prepare_long_str(), ' ');
	test_helper(fname, 16, "", 'z');
	memmove(buf, "\0aa\0bbb", 7);
	test_helper(fname, 17, buf, '\0');
}

static char	*prepare_long_str(void)
{
	static char	long_str[MAX_SPLIT_STR_LEN];

	strlcpy(long_str, "   lorem   ipsum dolor    ", MAX_SPLIT_STR_LEN);
	strlcat(long_str, " sit amet, consectetur  ", MAX_SPLIT_STR_LEN);
	strlcat(long_str, " adipiscing elit. Sed ", MAX_SPLIT_STR_LEN);
	strlcat(long_str, "non risus. Suspendisse   ", MAX_SPLIT_STR_LEN);
	return (long_str);
}

static void	test_helper(t_char_c *fname, int ntest, t_char_c *str, char delim)
{
	char	format[MAX_FORMAT_STR_LEN];

	strlcpy(format, "(\"%s\", '%c') = ", MAX_FORMAT_STR_LEN);
	printf("\t%d. ", ntest);
	cprintf(YELLOW, "%s", fname);
	printf(format, str, delim);
	call_split(fname, str, delim);
}

static void	call_split(t_char_c *fn, t_char_c *str, char delim)
{
	char	errbuf[MAX_ERR_BUF_SIZE + 1];
	char	**ret;
	int		errflag;
	int		i;

	errflag = 0;
	ret = ft_split(str, delim);
	if (ret == NULL)
		errflag = 1;
	if (!errflag)
		printf("%p\n", ret);
	else
	{
		printf("NULL\n");
		snprintf(errbuf, MAX_ERR_BUF_SIZE, "\t%s_test(): %s", fn, MEM_ERR_MSG);
		perror(errbuf);
	}
	i = 0;
	while (ret[i] != NULL)
	{
		printf("\t\t%d substr = \"%s\"\n", i + 1, ret[i]);
		i++;
	}
	split_free(&ret);
}
