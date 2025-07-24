# library name
NAME	=	ibft.a

# Directories
SRC_DIR =	src
OBJ_DIR =	obj
INCLUDE =	libft.h

SRC 	= 	ft_atoi.c		\
			ft_bzero.c		\
			ft_strlcat.c 	\
			ft_strlcpy.c	\
			ft_isalnum.c	\
			ft_isalpha.c	\
			ft_isascii.c	\
			ft_isdigit.c	\
			ft_isprint.c	\
			ft_memchr.c		\
			ft_memcmp.c		\
			ft_memcpy.c		\
			ft_memmove.c	\
			ft_memset.c 	\
			ft_strchr.c 	\
			ft_strlen.c 	\
			ft_strncmp.c	\
			ft_strnstr.c 	\
			ft_strrchr.c 	\
			ft_tolower.c 	\
			ft_toupper.c 	\
			ft_calloc.c		\
			ft_strdup.c		\
			ft_substr.c		\
			ft_strjoin.c 	\
			ft_strtrim.c	\
			ft_itoa.c 		\
			ft_split.c		\
			ft_putchar_fd.c \
			ft_putstr_fd.c	\
			ft_strmapi.c	\
			ft_striteri.c	\
			ft_putendl_fd.c	\
			ft_putnbr_fd.c 	\
			ft_lstnew.c			\
			ft_lstadd_front.c	\
			ft_lstsize.c		\
			ft_lstlast.c		\
			ft_lstadd_back.c	\
			ft_lstdelone.c		\
			ft_lstclear.c		\
			ft_lstiter.c		\
			ft_lstmap.c			\


SRC_FILES = $(addprefix $(SRC_DIR)/, $(SRC))
OBJ_FILES = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ_FILES)
	ar -rcs $(NAME) $(OBJ_FILES)

clean: 
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) 

re: fclean all 

bonus:
	$(MAKE) WITH_BONUS=1

.PHONY: clean fclean re bonus all
