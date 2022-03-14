#ifndef LIBFT_H
# define LIBFT_H
void	ft_bzero(void *s, size_t n);
int		ft_isalnum(int c);
char	ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t count);
void	*ft_memset(void *b, int c, size_t len);
size_t	ft_strlen(const char	*s);

#endif