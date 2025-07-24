NAME = 	push_swap
SRC  = 	main.c			\
		utils.c			\
		rules.c			\
		more_rules.c	\
		more_rules_2.c	\
		Push_Swap.c		\
		small_sort.c	\
		utils_2.c 		\
		utils_3.c		\
		utils_4.c		\
		utils_5.c		\

		

LIB	 	=	./src/libft/libft.a
HEADER 	= ./Push_Swap.h
LIB_HEADERS = 	-I./src/libft/
OBJECTS	=	$(SRC:.c=.o)
INCLUDE =	-I include $(LIB_HEADERS)
FLAGS 	= 	-Wall -Werror -Wextra -fsanitize=address
CC    	=	gcc


all: $(NAME)

$(LIB):
	@$(MAKE) -s -C $(dir $(LIB))
	
	@echo "libft made"

$(NAME):$(OBJECTS) $(HEADER) $(LIB)
	$(CC) $(FLAGS) $(INCLUDE) $(LIB) -o $(NAME) $(OBJECTS)
	rm -f $(OBJECTS)
	@echo "made $(NAME)"

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME) 

re: fclean all 

.PHONY: clean fclean re all
