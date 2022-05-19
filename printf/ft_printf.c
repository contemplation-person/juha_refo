/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conteng <conteng@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:00:07 by conteng           #+#    #+#             */
/*   Updated: 2022/05/20 03:00:28 by conteng          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     args;
    int     i;

    i = 0;
    while (format[i])
        i++;
    --i;
    while (--i > -1)
    {
        if (format[i] == '%')
        {
            if (format[i + 1] == 'c')
        }
    }
    va_start(ap, args);