NAME	=	fillit
CC		=	gcc

D_SRC	=	src
D_OBJ	=	obj
D_LIB	=	lib
D_INC	=	includes

W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")
F_OBJ	:=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	@$(CC) -I$(D_INC) $(W_FLAGS) -c $< -o $@ $(DEBUG)
	@echo "Compiling "$<"..."

$(NAME): $(F_OBJ)
	$(CC) -I$(D_INC) -L$(D_LIB) -lft $(F_OBJ) -o $@ $(DEBUG)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
