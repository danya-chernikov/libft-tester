/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_tester.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:51:25 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 14:37:08 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft_tester.h"

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
/*lstnew();
lstadd_front();
lstsize();
lstlast();
lstadd_back();
lstdel_one();
lstclear();
lstiter();
lstmap();*/
void	test_linked_list(void)
{
}
