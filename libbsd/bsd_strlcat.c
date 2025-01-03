/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsd_strlcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 21:08:13 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/26 15:21:14 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*	$OpenBSD: strlcat.c,v 1.15 2015/03/02 21:41:08 millert Exp $	*/

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

/* Modified by [Daniil Chernikov/libft-tester] on [12/01/2024]
 * I formatted the code to fit the Norm (norminette) */

#include <sys/types.h>
#include "string.h"

/*
 * Appends src to string dst of size dsize (unlike strncat, dsize is the
 * full size of dst, not space left).  At most dsize-1 characters
 * will be copied.  Always NUL terminates (unless dsize <= strlen(dst)).
 * Returns strlen(src) + MIN(dsize, strlen(initial dst)).
 * If retval >= dsize, truncation occurred.
 * The first loop finds the end of dst and adjust bytes left but
 * don't go past end.
 * When returning the result count does not include NUL. */
size_t	strlcat(char *dst, const char *src, size_t dsize)
{
	const char	*odst;
	const char	*osrc;
	size_t		n;
	size_t		dlen;

	odst = dst;
	osrc = src;
	n = dsize;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - odst;
	n = dsize - dlen;
	if (n-- == 0)
		return (dlen + strlen(src));
	while (*src != '\0')
	{
		if (n != 0)
		{
			*dst++ = *src;
			n--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - osrc));
}
