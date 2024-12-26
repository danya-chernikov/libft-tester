/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsd_strlcpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 00:04:03 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/02 00:10:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	$OpenBSD: strlcpy.c,v 1.12 2015/01/15 03:54:12 millert Exp $	*/

/*
 * Copyright (c) 1998, 2015 Todd C. Miller <Todd.Miller@courtesan.com>
 *
 * Permission to use, copy, modify, and distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

/* Modified by [Daniil Chernikov/libft-tester] on [11/15/2024]
 * I substituted the #include <string.h> line with #include "string.h",
 * making it possible to compile the code of this file using the original
 * string.h header file provided by libbsd-0.12.2, but not the system's
 * string.h header file */

/* Modified by [Daniil Chernikov/libft-tester] on [12/02/2024]
 * I formatted the code to fit the Norm (norminette) */

#include <sys/types.h>
#include "string.h"

/*
 * Copy string src to buffer dst of size dsize.  At most dsize-1
 * chars will be copied.  Always NUL terminates (unless dsize == 0).
 * Returns strlen(src); if retval >= dsize, truncation occurred.
 * The first loop copies as many bytes as will fit.
 * Then we check if there is not enough room in dst, add NUL and
 * traverse rest of src. When returning the result count does
 * not include NUL. */
size_t	strlcpy(char *dst, const char *src, size_t dsize)
{
	const char	*osrc;
	size_t		nleft;

	osrc = src;
	nleft = dsize;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			*dst++ = *src++;
			if (*dst == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (dsize != 0)
			*dst = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);	/*  */
}
