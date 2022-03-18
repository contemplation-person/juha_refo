/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 02:22:52 by conteng           #+#    #+#             */
/*   Updated: 2022/03/18 22:53:58 by conteng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

void	ft_bzero(void *s, unsigned int n);
int		ft_isalnum(int c);
char	ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
void	*ft_memmove(void *dest, const void *src, unsigned int count);
void	*ft_memset(void *b, int c, unsigned int len);
unsigned int	ft_strlen(const char	*s);
unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int dstsize);

#endif