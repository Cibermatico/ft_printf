NAME	=	libftprintf.a

SRC	=	ft_printf.c			\
		ft_printf_helper.c	\
		text_handle.c		\
		decimal_handle.c	\
		hex_handle.c		\
		ft_printf_helper2.c	\

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf
AR = ar crs

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

ft_printf: $(OBJS) 
	$(CC) $(CFLAGS) -o ft_printf $(OBJS)

.PHONY:	all clean fclean re