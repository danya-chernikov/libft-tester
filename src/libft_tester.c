/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:51:25 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/12 14:57:09 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
#include "../include/putsmth_fd.h"
#include "../include/list.h"

void	launch_tester(void)
{
	test_glibc_funcs();
	test_addit_funcs();
	test_linked_list();
}

/* It launches tests of our
 * implementation of the
 * original Glibc functions */
void	test_glibc_funcs(void)
{
	isalpha_test();
	isdigit_test();
	isalnum_test();
	isascii_test();
	isprint_test();
	strlen_test();
	memset_test();
	bzero_test();
	memcpy_test();
	memmove_test();
	strlcpy_test();
	strlcat_test();
	toupper_test();
	tolower_test();
	strchr_test();
	strrchr_test();
	strncmp_test();
	memchr_test();
	memcmp_test();
	strnstr_test();
	atoi_test();
	calloc_test();
	strdup_test();
}

/* It launches tests of the
 * additional functions we've
 * been asked to implement */
void	test_addit_funcs(void)
{
	substr_test();
	strjoin_test();
	strtrim_test();
	split_test();
	itoa_test();
	strmapi_test();
	striteri_test();
	putchar_fd_test();
	putstr_fd_test();
	putendl_fd_test();
	putnbr_fd_test();
}

/* It launches test of our
 * singly linked list
 * implementation */
/*lstlast();
lstadd_back();
lstdel_one();
lstclear();
lstiter();
lstmap(); */
void	test_linked_list(void)
{
	char		fname[MAX_FUNC_NAME_LEN];
	char		errbuf[MAX_ERR_BUF_SIZE];
	t_lst_test	tests;

	strncpy(fname, "test_linked_list", MAX_FUNC_NAME_LEN);
	init_lst_tests(&tests);
	if (!alloc_lst_test_strs(&tests)
		|| !alloc_lst_test_ints(&tests)
		|| !alloc_lst_test_floats(&tests))
	{
		form_common_err_msg(errbuf, fname, MEM_ERR_MSG);
		perror(errbuf);
		return ;
	}
	add_list_tests(&tests);
	test_linked_list_1(&tests);
	free_all_lst_tests(&tests);
}
