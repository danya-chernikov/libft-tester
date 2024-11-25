/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:27 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/25 16:26:36 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TESTER_H
# define LIBFT_TESTER_H

# include "../common_tester/common_tester.h"
# include "../libbsd/bsd_string.h"
# include "../../libft.h"

# include <ctype.h>
# include <locale.h>
# include <limits.h>
# include <stdint.h>

# define FT_STR					"ft_"
# define MAX_FUNC_NAME_LEN		20
# define MAX_STRNCMP_STR_LEN	128
# define MAX_MEMCHR_STR_LEN		128
# define MAX_STRNSTR_STR_LEN	128
# define MAX_STRDUP_STR_LEN		256
# define MAX_SUBSTR_STR_LEN		128

/* In this structure we store all possible arguments that may have a put_smth
 * putchar_fd_test, putstr_fd_test, ...) function. There are 3 different
 * possible argument types that can accept the first argument of the tested
 * function (symbol, string, number). There is only one possible type of
 * argument that can accept the second argument - it's fd (I/O descriptor).
 *
 * symbol[MAX_TESTS_NUM] - the size of this array is the maximum possible
 * number of tests;
 * string				 - no more than MAX_TESTS_NUM strings of length
 *						   not exceeding MAX_TEST_STR_LEN bytes; */
typedef struct
{
	struct s_first_arg
	{
		char	symbol[MAX_TESTS_NUM];
		char	**string;
		int		number[MAX_TESTS_NUM];
	} first;
	struct s_second_arg
	{
		int		fd[MAX_TESTS_NUM];
	} second;
} put_smth_args;

void	launch_tester(void);
void	test_glibc_funcs(void);
void	test_addit_funcs(void);
void	test_linked_list(void);

void	split_test(void);
int		split_test_helper(const char *funcname,
						  int ntest,
						  char const *str,
						  char delim);

void	itoa_test_helper(const char *funcname, int ntest, int num);
void	itoa_test(void);

char	func_for_strmapi(unsigned int pos, char symbol);
void	strmapi_test(void);

void	func_for_striteri(unsigned int pos, char *ptr);
void	striteri_test(void);

void	putchar_fd_test(void **func_arr);
void	putstr_fd_test(void **func_arr);
void	putendl_fd_test(void **func_arr);	
void	putnbr_fd_test(void **func_arr);
void	put_smth_test_helper(const char *funcname,
							 void **func_arr,
							 int find,
							 put_smth_args *args,
							 int tests_num);

void    isalpha_test(void);
void	isdigit_test(void);
void	isalnum_test(void);
void	isascii_test(void);
void	isprint_test(void);
void	strlen_test(void);
void	memset_test(void);
void	bzero_test(void);
void	memcpy_test(void);
void	memmove_test(void);
void	strlcpy_test(void);
void	strlcat_test(void);
void	tolower_test(void);
void	toupper_test(void);
void	strchr_test(void);
void	strrchr_test(void);
void	strncmp_test(void);
void	memchr_test(void);
void	memcmp_test(void);
void	strnstr_test(void);
void	atoi_test(void);
void	calloc_test(void);
void	strdup_test(void);

void	substr_test(void);
void	strjoin_test(void);
void	strtrim_test(void);

void	free_node(void *ptr);
void	singly_linked_list_test(void);

#endif
