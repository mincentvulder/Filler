# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vmulder <vmulder@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/22 14:18:40 by vmulder        #+#    #+#                 #
#    Updated: 2019/06/07 19:15:08 by vmulder       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

### COMPILATION ###
C      = gcc
FLAGS  = -g -Wall -Wextra -Werror

### EXECUTABLE ###
NAME   = vmulder.filler

### INCLUDES ###
LIBFT  = libft
OBJ_PATH  = objs
HEADER = incl
SRC_PATH  = srcs

### SOURCES ###
SOURCES = main.c get_data.c get_field.c check_and_replace_token.c \
			check_and_replace_token2.c find_xy.c return_xy.c return_xy_en.c \
			write_coor.c get_piece.c

### OBJECTS ###

SRCS = $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJS = $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))

### COLORS ###
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

### RULES ###

all: $(NAME)

$(NAME):
	@make -C ./libft
	@$(CC) $(SRCS) -I $(HEADER) $(FLAGS) -L $(LIBFT) -lft -o $@ $^
	@echo "$(GREEN)Project successfully compiled$(NOC)"

##tmp:
##	@mkdir -p objs

##$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADER)/$(NAME).h
##	@$(CC) $(FLAGS) -I $(HEADER) -c -g -o $@ $<

clean:
	@echo "Cleaning..."
	@make clean -C $(LIBFT)
	@rm -rf $(OBJ_PATH)

fclean:
	@echo "Fcleaning..."
	@rm -rf $(OBJ_PATH)
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean
	@$(MAKE) all -j

.PHONY: temporary, re, fclean, clean