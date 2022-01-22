/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juha <juha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 15:16:58 by juha              #+#    #+#             */
/*   Updated: 2022/01/19 15:56:09 by juha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] == s2[i]) && (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}
/**
#include<stdio.h>
int main ()
{
    char* str1 = "BlockDMask";
    char* str2 = "Block";
    char* str3 = "BlockDMask";
    char* str4 = "BlockFMask";
    char* str5 = "BlockAMask";
 
    printf("strcmp(%s, %s)\t = %d\n", str1, str2, ft_strcmp(str1, str2));
    printf("strcmp(%s, %s)\t = %d\n", str1, str3, ft_strcmp(str1, str3));
    printf("strcmp(%s, %s)\t = %d\n", str1, str4, ft_strcmp(str1, str4));
    printf("strcmp(%s, %s)\t = %d\n", str1, str5, ft_strcmp(str1, str5));
}
*/
