
NAME = ft_ls

SRC = main.c \
		run.c \
		parse.c \
		ft_ls.c \
		list/to_list.c \
		tools.c \
		print.c \
		list/compare.c \
		list/list_tools.c \
		list/list_tools2.c \
		handle_dotfiles.c

SRCDIR = ./src
OBJDIR = ./obj
INCDIR = ./includes

FTDIR = ./libft
FTLIB = $(addprefix $(FTDIR)/, libft.a)
FTINC = -I $(FTDIR)
FTLNK = -L $(FTDIR) -l ft

OBJ = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
CC = gcc
FLAGS =	-Wall -Werror -Wextra -g

all: obj $(FTLIB) $(NAME)

obj:
	mkdir -p $(OBJDIR)
	mkdir -p $(OBJDIR)/list

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FLAGS) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(NAME): $(OBJ) $(FTLIB)
	$(CC) $(FLAGS) $(OBJ) $(FTLNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(FTDIR) fclean

re: fclean all

.PHONY: clean, fclean, re
