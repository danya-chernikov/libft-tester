/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cprint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:40:49 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:40:53 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common_tester.h"

/* Colored printf wrapper. it has the same functionality as a regular printf()
 * but also add a color to our output */
void	cprintf(const char *color, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	if (GL_COLOR_FLAG)
	{
		printf("%s", color);
		fflush(stdout);
		vprintf(format, args);
		printf("%s", RESET_COLOR);
		fflush(stdout);
	}
	else
		vprintf(format, args);
	va_end(args);
}

/* Colored perror wrapper */
void	cperror(const char *color, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	if (GL_COLOR_FLAG)
	{
		fprintf(stderr, "%s", color);
		fflush(stderr);
		vfprintf(stderr, format, args);
		fprintf(stderr, "%s", RESET_COLOR);
		fflush(stderr);
	}
	else
		vfprintf(stderr, format, args);
	va_end(args);
}
