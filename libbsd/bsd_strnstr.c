/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsd_strnstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 23:39:40 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/02 00:10:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*-
 * Copyright (c) 2001 Mike Barcroft <mike@FreeBSD.org>
 * Copyright (c) 1990, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * This code is derived from software contributed to Berkeley by
 * Chris Torek.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

/* Modified by [Daniil Chernikov/libft-tester] on [11/24/2024]
 * I substituted the #include <string.h> line with #include "string.h",
 * making it possible to compile the code of this file using the original
 * string.h header file provided by libbsd-0.12.2, but not the system's
 * string.h header file */

/* Modified by [Daniil Chernikov/libft-tester] on [12/01/2024]
 * I formatted the code to fit the Norm (norminette) */

#include <sys/cdefs.h>

#include "string.h"

static void	alg(const char *s, const char *find, size_t slen, char c);

/*
 * Find the first occurrence of find in s, where the search is limited to the
 * first slen characters of s. */
char	*strnstr(const char *s, const char *find, size_t slen)
{
	char	c;

	c = *find++;
	if (c != '\0')
		alg(s, find, slen, c);
	return ((char *)s);
}

static void	alg(const char *s, const char *find, size_t slen, char c)
{
	char	sc;
	size_t	len;

	len = strlen(find);
	while (1)
	{
		while (1)
		{
			sc = *s++;
			if (slen-- < 1 || sc == '\0')
				return (NULL);
			if (sc == c)
				break ;
		}
		if (len > slen)
			return (NULL);
		if (strncmp(s, find, len) == 0)
			break ;
	}
	s--;
}
