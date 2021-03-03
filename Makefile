# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: klasak <klasak@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2020/11/03 13:29:10 by klasak        #+#    #+#                  #
#    Updated: 2021/02/01 19:35:20 by klasak        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a

HEADER_FILE		= libft.h

SRCS			= ft_bzero.c ft_split.c ft_substr.c ft_strlen.c ft_itoa.c\
				ft_putchar_fd.c ft_putnbr_fd.c ft_strmapi.c ft_strdup.c\
				ft_atoi.c ft_strtrim.c ft_putendl_fd.c ft_strlcpy.c\
				ft_putstr_fd.c ft_strjoin.c ft_calloc.c ft_strlcat.c\
				ft_memcmp.c ft_memchr.c ft_memmove.c ft_memccpy.c ft_tolower.c\
				ft_toupper.c ft_isprint.c ft_isascii.c ft_isalnum.c\
				ft_isalpha.c ft_strncmp.c ft_strchr.c ft_isdigit.c\
				ft_strrchr.c ft_strnstr.c ft_memcpy.c *ft_memset.c

OBJS			= $(SRCS:.c=.o)

BONUS			= ft_lstiter.c ft_lstsize.c ft_lstadd_front.c\
				ft_lstlast.c ft_lstadd_back.c ft_lstmap.c\
				ft_lstclear.c ft_lstdelone.c ft_lstnew.c

BONUS_OBJS		= $(BONUS:.c=.o)

CFLAGS			= -Wextra -Wall -Werror

cc				= gcc

ifdef WITH_BONUS
OBJ_FILES = $(OBJS) $(BONUS_OBJS)
else
OBJ_FILES = $(OBJS)
endif

all:			$(NAME)

$(NAME):		$(OBJ_FILES)
				ar rcs $(NAME) $(OBJ_FILES)

%.o: %.c $(HEADER_FILE)
			$(cc) -c $(CFLAGS) -o $@ $<

bonus:
		$(MAKE) WITH_BONUS=1 all

clean:
				rm -f $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re bonus %.o
