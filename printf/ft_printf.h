/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:04:34 by juha              #+#    #+#             */
/*   Updated: 2022/05/22 22:53:12 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdlib.h>

typedef struct s_format
{
	size_t			idx;
	char			change_char;
	struct s_format	*top;
	struct s_format	*bottom;
}t_format;

typedef enum e_success
{
	error = 0,
	success,
	exclusion = 0,
	inclusion,
	empty = 0
}t_success;

size_t	ft_strlen(const char	*s);

#endif