NAME	=	fillit
CC		=	gcc
TAGFILE	=	.tags

D_SRC	=	src
F_SRC	:=	$(shell ls -1 $(D_SRC) | grep "\.c$$")
DF_SRC	:=	$(addprefix $(D_SRC)/, $(F_SRC))

D_OBJ	=	obj
F_OBJ	=	$(F_SRC:.c=.o)
DF_OBJ	:=	$(addprefix $(D_OBJ)/, $(F_OBJ))

D_INC	=	includes libft/includes
O_INC	=	$(addprefix -I, $(D_INC))

W_FLAGS	=	-Wall -Wextra -Werror
D_FLAGS	=

MKDIR	=	mkdir -p
RM		=	/bin/rm -rf

.PHONY: all clean fclean re tags test

all: libft/libft.a $(NAME) $(TAGFILE)

test: all
	cd fillit-tests && ./test 2

$(TAGFILE): $(D_SRC)/*.c
	@ctags -f $(TAGFILE) $(addprefix $(D_SRC)/, $(F_SRC))
	@echo "Making tags..."

$(D_OBJ)/%.o: $(D_SRC)/%.c $(D_INC)
	@$(MKDIR) $(D_OBJ)
	@$(CC) $(O_INC) $(W_FLAGS) -c $< -o $@ $(D_FLAGS)
	@echo "Compiling "$<"..."

libft/libft.a:
	@$(MAKE) -C libft/ 2>/dev/null

$(NAME): $(DF_OBJ)
	$(CC) $(O_INC) -Llibft -lft $(W_FLAGS) $(DF_OBJ) -o $@ $(D_FLAGS)

clean:
	$(RM) $(D_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
