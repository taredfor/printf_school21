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
	//s_pec->plus = 0;
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

void	ft_parsing(const char *format, t_flag *s_pec, va_list ap)
{
	ft_init_flag(s_pec);
	ft_flag_parsing(format, s_pec);
	ft_width_parsing(format, s_pec, ap);
	ft_precision_pars(format, s_pec, ap);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	s_pec;

	s_pec.i = 0;
	s_pec.len = 0;
	va_start(ap, format);
	while (*(format + s_pec.i))
	{
		if (*(format + s_pec.i) == '%' /*&& *(format + s_pec.i + 1) != (int)ft_strlen(format)*/)
		{
			ft_parsing(format + 1, &s_pec, ap);
			ft_direction(++format, &s_pec, ap);
		}
		else
			write(1, &format[s_pec.i], 1);
		s_pec.i++;
	}
	va_end (ap);
//	printf("i= %d\n", s_pec.i);
//	printf("dot= %d\n", s_pec.dot);
//	printf("width= %d\n", s_pec.width);
//	printf("precision= %d\n", s_pec.precision);
	return(s_pec.len);
}


int	main()
{
	static int					mx_i = 42;
	char *c = "Hello World";
	// //char *d = "qwertyjyhjh";
	// ft_printf("%-",c);
	// return (0);
	//ft_printf("|y%10.5c|\n");
	//printf("|y%10.5c|\n");
//	ft_printf(" !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~", c);
//	printf(" !"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^_`abcdefghijklmnopqrstuvwxyz{|}~", c);
	//ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',' ');
	//printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",' ','!','"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',' ');
	//ft_printf("%p", &mx_i);
	printf("%p", &mx_i);
	return (0);

}
