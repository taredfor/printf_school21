#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>
#include "stdarg.h"

void	ft_init_flag(t_flag *s_pec)
{
	s_pec->minus = 0;
	s_pec->zero = 0;
	s_pec->type = 0;
	s_pec->width = 0;
	s_pec->precision = -1;
	s_pec->star = 0;
	s_pec->base = 10;
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

void ft_type(const char *format, t_flag *s_pec)
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
	va_list ap;
	t_flag 	s_pec;
	int 	i;

	i = 0;
	s_pec.i = 0;
	s_pec.len = 0;
	va_start(ap, format);
	while (*(format + s_pec.i) != '\0')
	{
		if (*(format + s_pec.i) == '%' && *(format + s_pec.i + 1) != '\0')
		{
			ft_parsing(format + 1 , &s_pec, ap);
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
//	printf("i= %d\n", s_pec.i);
//	printf("dot= %d\n", s_pec.dot);
//	printf("width= %d\n", s_pec.width);
//	printf("precision= %d\n", s_pec.precision);
	return (s_pec.len);
}

//int	main()
//{
//	int i;
//	int n;
//	static int					mx_i = 42;
//	char *c = "Hello World";
////	printf("%d\n", i);
////	i = printf("%5");
////	printf("%d\n", i);
////	//printf("\n");
////	n = ft_printf("%5");
////	printf("%d\n", n);
//
////	printf("%u\n", 4294967295u);
////	ft_printf("%u", 4294967295u);
//
//	//"this %x number", 17
//	printf("this %x number\n", 17);
//	ft_printf("this %x number\n", 17);
//	return (0);
//}
