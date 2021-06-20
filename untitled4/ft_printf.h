#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include "stdarg.h"
#include <stdlib.h>

typedef struct s_pec
{
	int	i;
	int	len;
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	star;
	int	type;
	int dot;
	int base;
	int plus;
}	t_flag;

int		ft_atoi(const char *str);
size_t	ft_strlen(const char *str);
int		ft_direction(const char *format, t_flag *s_pec, va_list ap);
char	*ft_itoa(unsigned long x, t_flag *s_pec);
char	ft_char_of_itoa(t_flag *s_pec, int x);
void 	ft_putchar_len(char c, t_flag *spec);
void  	ft_printing_decimal(t_flag *s_pec, long long x);
void 	ft_printing_unsigned_decimal(t_flag *s_pec, unsigned int x);
void ft_zero_print(t_flag *s_pec, int wid, int c);

#endif