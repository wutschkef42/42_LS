
NAME = ft_ls

SRC = main.c \
		parse.c

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

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(FTINC) -I $(INCDIR) -o $@ -c $<

$(FTLIB):
	make -C $(FTDIR)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(FTLNK) -o $(NAME)

clean:
	rm -rf $(OBJDIR)
	make -C $(FT) clean

fclean: clean
	rm $(NAME)
	make -C $(FT) fclean

re: fclean all

.PHONY: clean, fclean, re
