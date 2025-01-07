/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:27 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/07 19:07:45 by dchernik         ###   ########.fr       */
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

/*
 * MEM_ERR_BUF        - The size of a buffer in which we put the text
 *						to indicate an error during memory allocation
 *						when launching the `alloc_mem()` function in
 *						the `pus_smth_fd.c` file;
 * MEM_ERR            - The common message indicating an error in memory
 *						allocation (used in `ft_split.c`);
 * ERR_FUNC		      - The name of a function where the error occurred;
 * FILE_READ_BUF_SIZE - The size of the buffer used by the `read()` system
 *						call (used in `put_smth_fd.c`);
 * TEMP_FILE_NAME     - The name of the temporary file created when testing
 *						the `put_smth_fd()` family of functions;
 * PUTCHAR_FORMAT	  - The format string used to print the test result of
 *						the `putchar_fd()` function (used in the
 *						`print_special_test_result()`);
 * MAX_CNT_STR_LEN    - The maximum length of a string representing the
 *						content of a node of a singly linked list.
 */
# define ERROR						0
# define SUCCESS					1
# define STDIN						0
# define STDOUT						1
# define STDERR						2
# define NO_STD_STREAM				0
# define MAX_FUNC_NAME_LEN			128
# define MAX_FORMAT_STR_LEN			1024
# define MAX_STRNCMP_STR_LEN		128
# define MAX_MEMCHR_STR_LEN			128
# define MAX_STRNSTR_STR_LEN		128
# define MAX_STRDUP_STR_LEN			256
# define MAX_SUBSTR_STR_LEN			128
# define MAX_SPLIT_STR_LEN			256
# define FILE_READ_BUF_SIZE			256
# define MAX_ERR_BUF_SIZE			256
# define MAX_TESTS_NUM				128
# define MAX_TEST_STR_LEN			256
# define MAX_CNT_STR_LEN			1024
# define TEMP_FILE_NAME				"text.txt"
# define TOO_MANY_TESTS_ERR_MSG		"too many tests"
# define PUTSMTH_MEM_ERR_STRS		"unable to allocate mem for an arr of strs"
# define MEM_ERR_BUF_MSG			"unable to allocate mem for the error buf"
# define MEM_ERR_FILE_READ_BUF_MSG	"unable to allocate mem for the file buf"
# define MEM_ERR_MSG				"unable to allocate memory"
# define FILE_CREAT_ERR_MSG			"error creating file"
# define FILE_OPEN_ERR_MSG			"error opening file"
# define FILE_DEL_ERR_MSG			"unable delete file"
# define FILE_READ_ERR_MSG			"error reading from the file"
# define PUTCHAR_FORMAT				"('%c', fd): \"%s\"\n"
# define PUTSTR_FORMAT				"(\"%s\", fd): \"%s\"\n"
# define PUTENDL_FORMAT				"(\"%s\", fd): \"%s\"\n"
# define PUTNBR_FORMAT				"(%d, fd): \"%s\"\n"

/*
 * Each testing function has its unique identifier (ID).
 * This ID is passed to the ps_test_helper() function so
 * that it knows which function should be tested. */
typedef enum func_id
{
	PUTCHAR_FD_ID,
	PUTSTR_FD_ID,
	PUTENDL_FD_ID,
	PUTNBR_FD_ID
}	t_func_id;

/* The type of a list's content */
typedef enum list_cnt_type
{
	CHAR,
	U_CHAR,
	SHORT,
	U_SHORT,
	INT,
	U_INT,
	LONG,
	U_LONG,
	LONG_LONG,
	U_LONG_LONG,
	FLOAT,
	DOUBLE,
	LONG_DOUBLE,
	STRING,
	VOID
}	t_cnt_type;

/*
 * This structure defines all the tests to be performed on
 * the function being tested.
 * In this structure, we store all possible arguments that
 * may be accepted by the ps_fd() family of functions,
 * e.g., putchar_fd(), putstr_fd(), etc. Each of these functions
 * accepts two arguments: the first is described by the first
 * substructure, and the second is described by the second
 * substructure.
 * There are three different types of arguments that can be
 * accepted by the first parameter of the tested function:
 * a `symbol` (in the case of putchar_fd()), a `string`
 * (in the case of putstr_fd() and putendl_fd()), or a `number`
 * (in the case of the putnbr_fd() function).
 * For the second parameter, there is only one possible type
 * of argument: an `fd` (I/O descriptor). It may only take values
 * within the range defined by the func_id enum
 * (e.g., PUTCHAR_FD_ID, PUTSTR_FD_ID, etc.)
 *
 * Description of some structure fields:
 *     symbol[MAX_TESTS_NUM] - The size of this array is the
 *							   maximum possible number of tests;
 *     string                - No more than MAX_TESTS_NUM strings,
 *							   each with a length not exceeding
 *							   MAX_TEST_STR_LEN bytes;
 *     number                - No more than MAX_TESTS_NUM numbers
 *							   can be passed to tests a function.
 *
 * Examples of how this structure is used to stores tests:
 * When testing putchar_fd():
 * First test:										
 *				   'a'								
 *					‖								
 *     putchar_fd(first, second)					
 *     'a'          |      |
 *      ‖           |	   |
 *  (symbol[0])<----|      ----->(fd[0]) =  STDOUT
 *  string[0]-------|								
 *  number[0]-------|								
 *													
 *				    'c'								
 *	Second test:	 ‖								
 *      putchar_fd(first, second)					
 *      'c'          |      |						
 *       ‖           |		|
 *   (symbol[1])<----|      ----->(fd[1]) = STDERR		
 *   string[1]-------|								
 *   number[1]-------|								
 *
 * When testing putnbr_fd():
 * First test:										
 *				  2014								
 *				   ‖								
 *     putnbr_fd(first, second)					
 *                  |      |
 *  symbol[0]-------|      ----->(fd[0]) =  STDOUT
 *  string[0]-------|								
 *  (number[0])<----|								
 *	    ‖
 *	  2014												
 *				    100								
 *	Second test:	 ‖								
 *      putchar_fd(first, second)					
 *                   |      |						
 *   symbol[1]-------|      ----->(fd[1]) = a file descriptor
 *   string[1]-------|								
 *   (number[1]<-----|								
 *		 ‖
 *	    100  */
typedef struct ps_tests
{
	struct s_first_arg
	{
		char	symbol[MAX_TESTS_NUM + 1];
		char	**string;
		int		number[MAX_TESTS_NUM + 1];
	}	first;
	struct s_second_arg
	{
		int	fd[MAX_TESTS_NUM + 1];
	}	second;
}	t_ps_tests;

void	launch_tester(void);
void	test_glibc_funcs(void);
void	test_addit_funcs(void);
void	test_linked_list(void);

void	isalpha_test(void);
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
void	split_test(void);
void	itoa_test(void);
void	strmapi_test(void);
void	striteri_test(void);
void	putchar_fd_test(void);
void	putstr_fd_test(void);
void	putendl_fd_test(void);	
void	putnbr_fd_test(void);

t_list	*lstnew_test(void *cnt, t_cnt_type type);
void	lstadd_front(void);
void	lstsize(void);
void	lstlast(void);
void	lstadd_back(void);
void	lstdel_one(void);
void	lstclear(void);
void	lstiter(void);
void	lstmap(void);

#endif
