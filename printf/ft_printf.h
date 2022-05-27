/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:04:34 by juha              #+#    #+#             */
/*   Updated: 2022/05/27 15:40:50 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_format
{
	size_t			idx;
	char			change_char;
	struct s_format	*top;
	struct s_format	*bottom;
}t_format;

typedef enum e_success
{
	ERROR = 0,
	SUCCESS,
	EXCLUSION= 0,
	INCLUSION,
	EMPTY = 0,
}t_success;

size_t		set_va_stack(t_format	**stack, char *form, int form_len);
t_success	chk_format(char c);
t_format	*write_format(va_list *ap, t_format *top, size_t *form_len);
int			print_char(va_list *ap, t_format *top, char *form);
int			ft_printf(const char *form, ...);

t_success	free_stack(t_format **top);
t_format	*push_node(t_format *bottom_node, char conversion_c, size_t idx);
t_success	chk_persent(const char *form);

void		write_hexa_num(va_list *ap, char c, size_t *form_len, \
long long is_last);
void		write_int(va_list *ap, size_t *form_len);
void		write_unsigned_int(va_list *ap, size_t *form_len);
void		write_str(va_list *ap, char c_or_str, size_t *form_len);
void		write_pointer(va_list *ap, size_t *form_len, long long is_last);

size_t		ft_strlen(const char	*s);
char		*change_string(char *s, int cnt, size_t n, int is_minus);
char		*ft_itoa(int n);
int			cnt_zero(size_t l);

#endif