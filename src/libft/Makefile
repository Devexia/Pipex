#----------------------------------------------#
#-------------------SOURCE---------------------#
#----------------------------------------------#

SRCS = 				\
	   ft_strncmp.c \
	   ft_strjoin.c \
	   ft_split.c \
	   ft_split_util.c \
	   ft_calloc.c \
	   ft_bzero.c \
	   ft_strlen.c \
	   ft_strdup.c \

NAME		= libft.a
LIB			= libft.h
OBJS		= $(SRCS:.c=.o)
CC			= gcc
RM 			= rm -f
CFLAGS		= -Wall -Wextra -Werror
AR			= ar -rcs

all:		${NAME}

$(NAME):	${OBJS} ${LIB}
	${AR} ${NAME} ${OBJS}




%.o: %.c	${LIB} 
	@${CC} ${CFLAGS} -c $< -o $@ -g



clean:
	@echo "${ColorRed} perfect clean"
	@${RM} ${OBJS} ${OBJSBONUS}

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

#===================ASCIIART===============#


.PHONY:		all clean fclean re bonus 
