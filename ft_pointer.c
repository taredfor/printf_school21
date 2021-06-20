#include "ft_printf.h"

void	ft_printing_pointer(t_flag *s_pec, unsigned long x)
{
	char 	*str;
	int 	len;
	int		counter;

	len = 0;
	if (x == 0 && s_pec->precision <= 0)
	{
		if (s_pec->precision == 0)
		{
			s_pec->precision = -1;
			if (s_pec->minus == 1)
			{
				ft_putchar_len('0', s_pec);
				ft_putchar_len('x', s_pec);
				ft_zero_print(s_pec, s_pec->width, 0);
			}
		}
		return ;
	}
	if (s_pec->precision > -1)
		s_pec->zero = 0;
	s_pec->base = 16;
	str = ft_itoa(x, s_pec);
	if (s_pec->precision <= ft_strlen(str))
		s_pec->precision = ft_strlen(str);
	if (!s_pec->minus)
		ft_zero_print(s_pec, s_pec->width - s_pec->precision - 1, 0);
}