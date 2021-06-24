#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include "stdarg.h"
#include <stdlib.h>

typedef struct s_pec
{
	int		i;
	int		len;
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
	int 	dot;
	int 	star;
	int 	base;
}	t_flag;

int		ft_printf(const char *format, ...);
void	ft_parsing(const char *format, t_flag *s_pec, va_list ap);
void	ft_type(const char *format, t_flag *s_pec);
void	ft_precision_pars(const char *format, t_flag *s_pec, va_list ap);
void	ft_width_parsing(const char *format, t_flag *s_pec, va_list ap);
void	ft_flag_parsing(const char *format, t_flag *s_pec);
void	ft_init_flag(t_flag *s_pec);
int		ft_direction(const char *format, t_flag *s_pec, va_list ap);
void	ft_string(t_flag *s_pec, char *format);
void	ft_char(t_flag *s_pec, char x);
void	ft_string_print (char *format, t_flag *s_pec);
void	ft_zero_print(t_flag *s_pec, int wid, int c);
void	ft_printing_pointer(t_flag *s_pec, unsigned long x);
void	ft_specialcasefor_point(t_flag *s_pec);
void	ft_putstr_0x(t_flag *s_pec);
void	ft_printing_decimal(t_flag *s_pec, long long x);
void	ft_printing_unsigned_decimal(t_flag *s_pec, unsigned int x);
void	ft_private_case_decimal(t_flag *s_pec);
void	ft_putstr_spec(char *str, t_flag *s_pec);
void	ft_putchar_len(char c, t_flag *s_pec);
size_t	ft_strlen(const char *str);
int		ft_len_digit(unsigned long x, int base, int sign);
char	ft_char_of_itoa(t_flag *s_pec, int x);
char	*ft_itoa(unsigned long x, t_flag *s_pec);
int		ft_atoi(const char *str);

#endif