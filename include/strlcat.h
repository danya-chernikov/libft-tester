/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 19:42:45 by dchernik          #+#    #+#             */
/*   Updated: 2024/11/17 19:39:49 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRLCAT_H
# define STRLCAT_H

# include <stddef.h>

void	strlcat_regular_tests(t_char_c *fname);
void	strlcat_special_tests(t_char_c *fcname);
void	strlcat_test_helper(t_char_c *fname, char *dst, t_char_c *src, size_t s);

#endif
