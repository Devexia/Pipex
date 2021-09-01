
# Folders

override BIN		:= bin
override SRC		:= src
override INC		:= includes

# Libraries

override LIBFT_DIR	:= src/libft
override LIBFT		:= libft.a

# Properties

NAME				= pipex

# Commands

override CC			:= gcc
override RM			:= rm -rf
override CFLAGS		:= -Wall -Wextra -Werror
override INCLUDES	:= -I$(INC) -I$(LIBFT_DIR)

# Sources

override SRCS		:=									\
						parsing.c						\
						pipex.c							\
						pipex_utils.c					\


override OBJS		:= $(addprefix $(BIN)/, $(SRCS:.c=.o))

override HEADERS	:= $(addprefix $(INC)/,				\
				pipex.h									\
				)

all:		libs $(NAME)

libs:
			$(MAKE) -C $(LIBFT_DIR)
			ln -sf $(LIBFT_DIR)/$(LIBFT)

bonus:		all

$(BIN)/%.o:	$(SRC)/%.c $(HEADERS)
			@mkdir -p $(dir $@);
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(LIBRARIES)

clean:
			$(RM) $(OBJS)
			find $(BIN) -type d -empty -delete
			$(MAKE) -C $(LIBFT_DIR) clean

fclean:		clean
			$(RM) $(NAME)
			$(RM) $(LIBFT)
			$(MAKE) -C $(LIBFT_DIR) fclean

re:			fclean all

.PHONY:		all libs bonus clean fclean re
