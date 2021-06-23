#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t			i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

int ft_len_digit(unsigned long x, int base, int sign)
{
	int len;

	len = 1;
	x = x / base;
	while (x)
	{
		x = x / base;
		len++;
	}
	return (len + sign);
}

int	ft_atoi(const char *str)
{
	unsigned int		i;
	long				temp;
	int					sign;

	i = 0;
	sign = 1;
	temp = 0;
	while ((8 < str[i] && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (47 < str[i] && str[i] < 58)
	{
		temp = temp * 10 + str[i] - '0';
		i++;
		if (temp > 2147483647 && sign == 1)
			return (-1);
		if (temp > 2147483648 && sign == -1)
			return (0);
	}
	return ((long)(temp * sign));
}

int ft_return_nbr(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

char	ft_char_of_itoa(t_flag *s_pec, int x)
{
		char c;

		if (x > 9)
		{
			if (s_pec->type == 'X')
				c = x + 7 + '0';
			else
				c = x + 39 + '0';
		}
		else
		{
			if (x < 0)
				x = -x;
			c = x + '0';
		}
		return (c);
}

char	*ft_itoa(unsigned long x, t_flag *s_pec)
{
	char 	*str;
	int		sign;
	int 	len;
	int		count_digit;

	sign = 0;
	if (x < 0)
		sign = 1;
	len = ft_len_digit(x, s_pec->base, sign);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (x < 0)
		str[0] = '-';
	str[len] = '\0';
	while (--len >= sign)
	{
		count_digit = x % s_pec->base;
		str[len] = ft_char_of_itoa(s_pec, count_digit);
		x = x / s_pec->base;
	}
	return (str);
}