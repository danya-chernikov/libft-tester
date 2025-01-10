/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:51:25 by dchernik          #+#    #+#             */
/*   Updated: 2025/01/10 17:09:12 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"
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
	t_cnt_type	types[MAX_LST_NODES_NUM];
	t_list		*head_ptr;
	char		text[64];
	int			number;
	float		fnum;

	strncpy(text, "just some text", 64);
	number = 10;
	fnum = 5.6;

	types[0] = STRING;
	head_ptr = lstnew_test((void *)text, STRING);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	types[1] = INT;
	addfront_quick(&head_ptr, (void *)&number, INT);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);

	types[2] = FLOAT;
	addfront_quick(&head_ptr, (void *)&fnum, FLOAT);
	print_list(head_ptr, types, 0);
	lstsize_test(&head_ptr);
}
