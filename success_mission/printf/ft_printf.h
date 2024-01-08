/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 16:04:34 by juha              #+#    #+#             */
/*   Updated: 2022/05/30 17:22:00 by juha             ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <sys/types.h>
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef enum e_success
{
	ERROR = 0,
	SUCCESS,
	EXCLUSION = 0,
	INCLUSION,
	EMPTY = 0,
}t_success;

int			ft_printf(const char *form, ...);
t_success	write_format(va_list *ap, char input_c, size_t *form_len);
int			print_char(va_list *ap, char *form);
t_success	chk_format(char c);
size_t		cnt_persent(const char *form, size_t form_len);

t_success	chk_persent(const char *form);
void		write_c(va_list *ap, char c, size_t *form_len);
void		write_str(va_list *ap, char str, size_t *form_len);

void		write_unsigned_int(va_list *ap, size_t *form_len);
void		write_int(va_list *ap, size_t *form_len);
void		write_hexa_num(va_list *ap, char c, \
size_t *form_len, long long is_last);
void		write_pointer(va_list *ap, size_t *form_len, long long is_last);

size_t		ft_strlen(const char	*s);
void		ft_putnbr_fd(long long n, int fd);
void		write_num(int fd, long long l);
#endif