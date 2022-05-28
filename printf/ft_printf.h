/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:04:34 by juha              #+#    #+#             */
/*   Updated: 2022/05/29 01:15:38 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>

typedef enum e_success
{
	ERROR = 0,
	SUCCESS,
	EXCLUSION= 0,
	INCLUSION,
	EMPTY = 0,
}t_success;


int			ft_printf(const char *form, ...);
void		write_format(va_list *ap, char input_c, size_t *form_len);
int			print_char(va_list *ap, char *form);
t_success	chk_format(char c);
size_t		cnt_persent(const char *form, size_t form_len);

void		write_c(va_list *ap, char c, size_t *form_len);
void		write_str(va_list *ap, char str, size_t *form_len);

void		write_unsigned_int(va_list *ap, size_t *form_len);
void		write_int(va_list *ap, size_t *form_len);
void		write_hexa_num(va_list *ap, char c, \
size_t *form_len, long long is_last);
void		write_pointer(va_list *ap, size_t *form_len, long long is_last);

char		*ft_itoa(long long n);
int			cnt_zero(size_t l);
char		*change_string(char *s, int cnt, size_t n, int is_minus);
char		*ft_strdup(const char *s1);
size_t		ft_strlen(const char	*s);
#endif