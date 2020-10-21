# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/07 18:06:29 by gartanis          #+#    #+#              #
#    Updated: 2020/07/17 01:47:04 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET	:= corewar
CFLAGS 	:= -Wall -Werror -Wextra
CC 		:= gcc

# Source and object direct

LIBFT	:= ./libft/libft.a
INC		:= ./includes/
LFT_DIR := ./libft/
OBJ_DIR	:= ./obj/

# Source files

FILE 	:= srcs/corewar/check_play.c srcs/corewar/error.c srcs/corewar/free.c\
 			srcs/corewar/init_cursor.c srcs/corewar/init.c srcs/corewar/main.c\
 			srcs/corewar/move_cursor.c srcs/corewar/op.c srcs/corewar/parse_abc.c\
 			srcs/corewar/parse_args.c srcs/corewar/parse_champion.c \
 			srcs/corewar/parse_flags.c srcs/corewar/parse_util.c srcs/corewar/play_corewar.c\
 			srcs/corewar/play_util.c srcs/corewar/visualization/visualizer.c \
			srcs/corewar/print.c srcs/corewar/validate_instr.c srcs/corewar/init_champ.c\
			srcs/corewar/visualization/print_arena.c srcs/corewar/visualization/print_bar.c\
			srcs/corewar/visualization/init_vs.c\


INSTR	:= srcs/corewar/instruction/ft_add.c srcs/corewar/instruction/ft_aff.c srcs/corewar/instruction/ft_and.c \
			srcs/corewar/instruction/ft_fork.c srcs/corewar/instruction/ft_ld.c srcs/corewar/instruction/ft_ldi.c \
			srcs/corewar/instruction/ft_lfork.c srcs/corewar/instruction/ft_live.c srcs/corewar/instruction/ft_lld.c\
			srcs/corewar/instruction/ft_lldi.c srcs/corewar/instruction/ft_or.c srcs/corewar/instruction/ft_st.c \
			srcs/corewar/instruction/ft_sti.c srcs/corewar/instruction/ft_sub.c srcs/corewar/instruction/ft_xor.c \
			srcs/corewar/instruction/ft_zjmp.c srcs/corewar/instruction/instr_util.c

SRCS	+= $(notdir $(FILE))
SRCS	+= $(notdir $(INSTR))

HEADER	:= includes/*.h

vpath %.c srcs/corewar/instruction/
vpath %.c srcs/corewar/
vpath %.c srcs/corewar/visualization/
vpath %.h includes/

# Object files
OBJF	:= $(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

RED 	:= \033[31;1m
GREEN 	:= \033[32;1m
DBLUE 	:= \033[34m
WHITE	:= \033[39;1m
EOC		:= \033[00m

all: obj $(TARGET)

obj:
	@mkdir -p $(OBJ_DIR)

$(TARGET): $(LIBFT) $(OBJF)
	@$(CC) -lncurses $^ -o $@ $(LIBFT)
	@printf "\n$(GREEN)compiled: $(WHITE)$(TARGET)$(EOC)\n"

$(OBJ_DIR)%.o: %.c $(HEADER) Makefile
	@printf "$(DBLUE) - Compiling $< into $@\r$(EOC)"
	@$(CC) $(CFLAGS) -I $(INC) -I $(LFT_DIR)/includes -c $< -o $@

$(LIBFT): FORCE
	@make -C $(LFT_DIR)

clean:
	@rm -rf *.o obj includes/lemin.h.gch
	@cd libft/ && make clean
	@echo "$(RED)deleted: $(WHITE)obj files$(EOC)"

fclean: clean
	@rm -f $(TARGET)
	@cd libft/ && make fclean
	@echo "$(RED)deleted: $(WHITE)$(TARGET)$(EOC)"

re: fclean all

FORCE:

.PHONY: clean fclean re all
