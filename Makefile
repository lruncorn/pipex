NAME = pipex

SRC =  ft_split.c      ft_strdup.o     ft_strlcpy.c    ft_strncmp.c    get_data.c  \
 		ft_strjoin.c    ft_strlen.c     \
		 ft_strdup.c      ft_substr.c     pipex.c        utils.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(NAME)

%.o:	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf *.o

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re 
