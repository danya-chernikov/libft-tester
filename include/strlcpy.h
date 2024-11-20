/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:43:00 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/17 19:39:25 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRLCPY_H
# define STRLCPY_H

void	strlcpy_regular_tests(t_char_c *fname);
void	strlcpy_special_tests(t_char_c *fname);
void	strlcpy_test_helper(t_char_c *fname, char *dst, t_char_c *src, size_t s);

#endif
