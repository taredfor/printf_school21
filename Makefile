NAME = libftprintf.a

LIST =		ft_printf.c		ft_direction.c		ft_printf_utils.c\
			ft_decimal.c	ft_pointer.c		ft_parsing.c

OBJ = $(patsubst %.c, %.o,$(LIST))

HEADER = ft_printf.h

OPTFLAGS = -O2

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

%.o : %.c
	gcc $(FLAGS) $(OPTFLAGS) -c $< -o $@

clean :
	@rm -f ${OBJ}

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re