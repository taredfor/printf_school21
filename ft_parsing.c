#include "ft_printf.h"

void	ft_init_flag(t_flag *s_pec)
{
	s_pec->minus = 0;
	s_pec->zero = 0;
	s_pec->type = 0;
	s_pec->width = 0;
	s_pec->precision = -1;
	s_pec->star = 0;
	s_pec->base = 10;
	s_pec->dot = 0;
}

void	ft_flag_parsing(const char *format, t_flag *s_pec)
{
	while (1)
	{
		if (format[s_pec->i] == '-')
			s_pec->minus = 1;
		else if (format[s_pec->i] == '0')
			s_pec->zero = 1;
		else
			break ;
		s_pec->i++;
	}
}

void	ft_width_parsing(const char *format, t_flag *s_pec, va_list ap)
{
	if (format[s_pec->i] == '*')
	{
		s_pec->width = va_arg(ap, int);
		if (s_pec->width < 0)
		{
			s_pec->minus = 1;
			s_pec->width = s_pec->width * (-1);
		}
		s_pec->i++;
		return ;
	}
	s_pec->width = ft_atoi(format + s_pec->i);
	while (format[s_pec->i] >= 48 && format[s_pec->i] <= 57)
		s_pec->i++;
}
