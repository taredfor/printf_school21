#include "ft_printf.h"
void ft_zero_print(t_flag *s_pec, int wid, int c)
{
	if (c)
	{
		while (wid-- && wid > 0)
		{
			write(1, &c, 1);
			s_pec->len++;
		}
		return ;
	}
	if (wid < 0)
		return ;
	while (wid-- && wid > 0)
	{
		if (!s_pec->minus && s_pec->zero)
		{
			write(1, "0", 1);
			s_pec->len++;
		}
		else
		{
			write(1, " ", 1);
			s_pec->len++;
		}
	}
}
void ft_string_print (char *format, t_flag *s_pec)
{
	int len;
	int i;

	len = 0;
	i = 0;
	if (format)
	{
		if (s_pec->precision == -1)
			len = (int)ft_strlen(format);
		else
			len = s_pec->precision;
		while (format[i] && len > 0)
		{
			write(1, &format[i], 1);
			s_pec->len++;
			i++;
			len--;
		}

	}
}

void	ft_char(t_flag *s_pec, char x)
{
	if (s_pec->minus == 1)
	{
		ft_putchar_len(x, s_pec);
		ft_zero_print(s_pec, s_pec->width, 0);
	}
	else
	{
		ft_zero_print(s_pec, s_pec->width, 0);
		ft_putchar_len(x, s_pec);
	}
}

void	ft_string(t_flag *s_pec, char *format)
{
	int len;

	len = 0;
	if (!format)
		format = "(null)";
	len = (int)ft_strlen(format);
	if (s_pec->precision < 0)
		s_pec->precision = -1;
	else if (s_pec->precision < len)
		len = s_pec->precision;
	if (s_pec->minus == 1)
	{
		ft_string_print(format, s_pec);
		ft_zero_print(s_pec, s_pec->width - len + 1, 0);
	}
	else
	{
		ft_zero_print(s_pec, s_pec->width - len + 1, 0);
		ft_string_print(format, s_pec);
	}
}

int	ft_direction(const char *format, t_flag *s_pec, va_list ap)
{
 	if (format[s_pec->i] == 'c')
 		ft_char(s_pec, va_arg(ap, int));
 	else if (format[s_pec->i] == '%')
 		ft_char(s_pec, '%');
 	else if (format[s_pec->i] == 's')
 		ft_string(s_pec, va_arg(ap,char *));
 	else if (format[s_pec->i] == 'd' || format[s_pec->i] == 'i')
		ft_printing_decimal(s_pec, va_arg(ap, int));
	else if (format[s_pec->i] == 'X' || format[s_pec->i] == 'x' || format[s_pec->i] == 'u')
		ft_printing_unsigned_decimal(s_pec, va_arg(ap, unsigned int));
	else if (format[s_pec->i] == 'p')
		ft_printing_pointer(s_pec, va_arg(ap, unsigned long);
 	return (0);
}