/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memcmp.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchernik <dchernik@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:41:43 by dchernik          #+#    #+#             */
/*   Updated: 2024/12/27 16:41:45 by dchernik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMCMP_H
# define MEMCMP_H

# include <stddef.h>

void	memcmp_regular_tests(t_char_c *fname);
void	memcmp_special_tests(t_char_c *fcname);
void	memcmp_test_helper(t_char_c *fn, t_void_c *s1, t_void_c *s2, size_t n);

#endif
