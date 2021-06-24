#include "ft_printf.h"

void ft_putstr_0x(t_flag *s_pec)
{
	ft_putchar_len('0', s_pec);
	ft_putchar_len('x', s_pec);
}

void ft_specialcasefor_point(t_flag *s_pec)
{
	if (s_pec->precision == 0)
	{
		if (!s_pec->minus)
			ft_zero_print(s_pec, s_pec->width - 1, 0);
		s_pec->precision = -1;
		ft_putstr_spec("0x", s_pec);
		if (s_pec->minus)
			ft_zero_print(s_pec, s_pec->width - 1, 0);

	}
	else
	{
		if (!s_pec->minus)
			ft_zero_print(s_pec, s_pec->width - 2, 0);
		s_pec->precision = -1;
		ft_putstr_spec("0x0", s_pec);
		if (s_pec->minus)
			ft_zero_print(s_pec, s_pec->width - 2, 0);
	}
}
void	ft_printing_pointer(t_flag *s_pec, unsigned long x)
{
	char 	*str;
	int 	len;

	len = 0;
	if (x == 0 && s_pec->precision <= 0)
	{
		ft_specialcasefor_point(s_pec);
		return ;
	}
	if (s_pec->precision > -1)
		s_pec->zero = 0;
	s_pec->base = 16;
	str = ft_itoa(x, s_pec);
	if (s_pec->precision <= (int)ft_strlen(str))
		s_pec->precision = ft_strlen(str);
	if (!s_pec->minus)
		ft_zero_print(s_pec, s_pec->width - s_pec->precision - 1, 0);
	ft_putstr_0x(s_pec);
	ft_zero_print(s_pec, s_pec->precision - (int)ft_strlen(str) + 1, '0');
	ft_putstr_spec(str, s_pec);
	if (s_pec->minus)
		ft_zero_print(s_pec, s_pec->width - s_pec->precision - 1, 0);
	free (str);
	}