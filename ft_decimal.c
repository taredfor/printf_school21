#include "ft_printf.h"

void ft_putchar_len(char c, t_flag *s_pec)
{
	write(1, &c, 1);
	s_pec->len++;
}

void	ft_putstr_spec(char *str, t_flag *s_pec)
{
	unsigned int i;
	unsigned int len;

	if (!str)
		return ;
	i = 0;
	if (s_pec->precision == -1 || s_pec->precision >= (int)ft_strlen(str))
		len = ft_strlen(str);
	else
	{
		if (s_pec->precision < 1)
			s_pec->precision = 0;
		len = s_pec->precision;
	}
	while (i < len)
	{
		ft_putchar_len(str[i], s_pec);
		i++;
	}
}

void	ft_private_case_decimal(t_flag *s_pec)
{
	if (s_pec->zero)
	{
		s_pec->zero = 0;
		ft_zero_print(s_pec,s_pec->width + 1, 0);
	}
	else
		ft_zero_print(s_pec,s_pec->width + 1, 0);
}

void ft_printing_unsigned_decimal(t_flag *s_pec, unsigned int x)
{
	char *str;

	if (x == 0 && s_pec->precision == 0)
	{
		ft_private_case_decimal(s_pec);
		return ;
	}
	if (s_pec->precision > -1)
		s_pec->zero = 0;
	if (s_pec->type == 'X' || s_pec->type == 'x')
		s_pec->base = 16;
	str = ft_itoa(x, s_pec);
	if (s_pec->precision <= (int)ft_strlen(str))
		s_pec->precision = ft_strlen(str);
	if (!s_pec->minus)
		ft_zero_print(s_pec, s_pec->width - s_pec->precision + 1, 0);
	ft_zero_print(s_pec, s_pec->precision - (int)ft_strlen(str) + 1, '0');
	ft_putstr_spec(str, s_pec);
	if (s_pec->minus)
		ft_zero_print(s_pec, s_pec->width - s_pec->precision + 1 , 0);
	free(str);
}

void  ft_printing_decimal(t_flag *s_pec, long long x)
{
	char 	*str;

	if (x >= 0)
		ft_printing_unsigned_decimal(s_pec, x);
	else
	{
		x = -x;
		str = ft_itoa(x, s_pec);
		if (s_pec->precision > -1)
			s_pec->zero = 0;
		if (s_pec->precision <= (int)ft_strlen(str))
			s_pec->precision = ft_strlen(str);
		if (s_pec->zero)
			ft_putchar_len('-', s_pec);
		if (!s_pec->minus)
			ft_zero_print(s_pec, s_pec->width - s_pec->precision, 0);
		if (!s_pec->zero)
			ft_putchar_len('-', s_pec);
		ft_zero_print(s_pec,s_pec->precision - (int)ft_strlen(str) + 1, '0');
		ft_putstr_spec(str, s_pec);
		if (s_pec->minus)
			ft_zero_print(s_pec ,s_pec->width - s_pec->precision, 0);
		free(str);
	}
}
