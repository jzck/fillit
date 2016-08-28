NAME	=	fillit
CC		=	gcc


D_SRC	=	src
F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")

D_OBJ	=	obj
F_OBJ	=	$(F_SRC:.c=.o)
F_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

D_INC	=	includes

D_LIB	=	lib
D_LIB	:=	$(shell find $(D_LIB) -maxdepth 1 -mindepth 1 -type d)
D_LIB	:=	$(addprefix -L,$(D_LIB))
F_LIB	=	ft
F_LIB	:=	$(addprefix -l, $(F_LIB))

W_FLAGS	=	-Wall -Wextra -Werror
DEBUG	=
MKDIR	=	mkdir -p
RM		=	/bin/rm -rf


.PHONY: all clean fclean re

all: $(NAME)

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	@$(CC) -I$(D_INC) $(W_FLAGS) -c $< -o $@ $(DEBUG)
	@echo "Compiling "$<"..."

$(NAME): $(F_OBJ)
	$(CC) -I$(D_INC) $(D_LIB) $(F_LIB) $(W_FLAGS) $(F_OBJ) -o $@ $(DEBUG)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
