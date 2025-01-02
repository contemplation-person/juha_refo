#ifndef _ASM_
#define _ASM_

#include <errno.h>
extern int ft_strlen(const char* str);
extern int ft_strcmp(const char* origin, const char* cmp);
extern int ft_strcpy(const char* dest, const char* src);
extern int ft_write(int fd, char *str, int len);

#endif
