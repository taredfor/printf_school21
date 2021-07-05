#include "ft_printf.h"

void	ft_precision_pars(const char *format, t_flag *s_pec, va_list ap)
{
	if (format[s_pec->i] == '.')
	{	
		s_pec->dot = 1;
		s_pec->i++;
	}
	else
		return ;
	if (format[s_pec->i] == '*')
	{
		s_pec->precision = va_arg(ap, int);
		s_pec->i++;
		return ;
	}
	s_pec->precision = ft_atoi(format + s_pec->i);
	while (format[s_pec->i] >= 48 && format[s_pec->i] <= 57)
		s_pec->i++;
}

void	ft_type(const char *format, t_flag *s_pec)
{
	if (format[s_pec->i])
	{
		s_pec->type = format[s_pec->i];
	}
}

void	ft_parsing(const char *format, t_flag *s_pec, va_list ap)
{
	ft_init_flag(s_pec);
	ft_flag_parsing(format, s_pec);
	ft_width_parsing(format, s_pec, ap);
	ft_precision_pars(format, s_pec, ap);
	ft_type(format, s_pec);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	s_pec;

	s_pec.i = 0;
	s_pec.len = 0;
	va_start(ap, format);
	while (*(format + s_pec.i) != '\0')
	{
		if (*(format + s_pec.i) == '%' && *(format + s_pec.i + 1) != '\0')
		{
			ft_parsing(format + 1, &s_pec, ap);
			ft_direction(++format, &s_pec, ap);
		}
		else
		{
			write(1, &format[s_pec.i], 1);
			s_pec.len++;
		}
		if ((int)(ft_strlen(format)) > s_pec.i)
			s_pec.i++;
	}
	va_end (ap);
	return (s_pec.len);
}
