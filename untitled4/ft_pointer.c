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
				ft_putchar_len('x', s_pec);
			}
		}
	}

}