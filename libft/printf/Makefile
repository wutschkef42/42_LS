
NAME := libftprintf.a

SRC_DIR :=	./src
OBJ_DIR :=	./obj
INC_DIR :=	./includes

SRC :=		ft_printf.c \
			process_format.c \
			seek_index.c \
			check_token.c \
			parse_token.c \
			proceed.c \
			init_cspec.c \
			parse_cspec.c \
			dispatch.c \
			print_cspec.c \
			string_handler.c \
			num_handler.c \
			unum_handler.c \
			escape_percent.c \
			char_handler.c \
			tools/ft_tools.c \
			tools/pf_atoi.c \
			tools/pf_itoa.c \
			tools/pf_num.c

OBJ :=		$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

CC :=		gcc

# remove -g before pushing live
CFLAGS :=	-Wall -Werror -Wextra -g

all: $(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)
			mkdir -p $(OBJ_DIR)/tools

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

$(NAME): $(OBJ_DIR) $(OBJ)
			ar rc $(NAME) $(OBJ)
			ranlib $(NAME)
clean:
			rm -rf $(OBJ_DIR)

fclean: clean
			rm -f $(NAME)
re: fclean all 

.PHONY: 	all clean fclean re

			
