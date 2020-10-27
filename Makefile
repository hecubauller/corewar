# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lelida <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/22 11:51:10 by lelida            #+#    #+#              #
#    Updated: 2020/10/22 11:51:22 by lelida           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Targets
ASM				:= asm
COREWAR			:= corewar

# Gcc and flags
CC				:= gcc
FLAGS			:= -Wall -Wextra -Werror

# Source files 
ASM_SRCS_FILES		:=	allocation.c file.c free.c\
 						instructions.c label.c main.c\
 						parse_header.c parser_utils.c parser.c\
 						types.c

CORE_SRCS_FILES		:=	check_play.c error.c free.c\
 						init_cursor.c init.c main.c\
 						move_cursor.c op.c parse_abc.c\
 						parse_args.c print.c parse_champion.c \
 						parse_flags.c parse_util.c play_corewar.c\
 						play_util.c validate_instr.c init_champ.c\
						print_arena.c print_bar.c\
						init_vs.c visualizer.c \
						ft_add.c ft_aff.c ft_and.c \
						ft_fork.c ft_ld.c ft_ldi.c \
						ft_lfork.c ft_live.c ft_lld.c\
						ft_lldi.c ft_or.c ft_st.c \
						ft_sti.c ft_sub.c ft_xor.c \
						ft_zjmp.c instr_util.c

# Headers
ASM_HEADERS_FILES	:=	op.h asm.h
CORE_HEADERS_FILES	:=	op.h corewar.h	

# Sources path's
ASM_PATH		:= srcs/asm/
CORE_PATH		:= srcs/corewar/
ASM_SRCS		:= $(addprefix $(ASM_PATH), $(ASM_SRCS_FILES))
CORE_SRCS		:= $(addprefix $(CORE_PATH), $(CORE_SRCS_FILES))

# Objects
OBJS_PATH			:= objs/
ASM_OBJS_PATH		:= objs/asm/
CORE_OBJS_PATH		:= objs/corewar/
ASM_OBJS		:= $(addprefix $(ASM_OBJS_PATH), $(ASM_SRCS_FILES:.c=.o))
CORE_OBJS 		:= $(addprefix $(CORE_OBJS_PATH), $(CORE_SRCS_FILES:.c=.o))

# Includes 
INCLUDES_PATH	:= includes/
INCLUDES		:= -I $(INCLUDES_PATH)
ASM_HEADERS		:= $(addprefix $(INCLUDES_PATH), $(ASM_HEADERS_FILES))
CORE_HEADERS	:= $(addprefix $(INCLUDES_PATH), $(CORE_HEADERS_FILES))

# Library
LIBFT_PATH		:= libft/
LIBFT_INCLUDES	:= -I libft/includes
LIBFT			:= -L $(LIBFT_PATH) -lft -lncurses -lpthread

# Colors
RED 		:= \033[31;1m
GREEN 		:= \033[32;1m
WHITE		:= \033[39;1m
DBLUE 		:= \033[34m
EOC			:= \033[00m

.PHONY: all libft clean fclean re

all: libft $(ASM) $(COREWAR)

libft:
	@make -C $(LIBFT_PATH)

$(ASM_OBJS_PATH)%.o: $(ASM_PATH)%.c $(ASM_HEADERS) $(LIBFT_PATH)libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(ASM_OBJS_PATH) 2> /dev/null || true
	@printf "$(DBLUE) - Compiling $< into $@\r$(EOC)"
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -o $@ -c $<
	

$(CORE_OBJS_PATH)%.o: $(CORE_PATH)%.c $(CORE_HEADERS) $(LIBFT_PATH)libft.a
	@mkdir $(OBJS_PATH) 2> /dev/null || true
	@mkdir $(CORE_OBJS_PATH) 2> /dev/null || true
	@printf "$(DBLUE) - Compiling $< into $@\r$(EOC)"
	@$(CC) $(FLAGS) $(INCLUDES) $(LIBFT_INCLUDES) -o $@ -c $<

$(ASM): $(ASM_OBJS)
	@$(CC) $(FLAGS) $(LIBFT) $(ASM_OBJS) -o $@
	@printf "\n$(GREEN)compiled: $(WHITE)$(ASM)$(EOC)\n"

$(COREWAR): $(CORE_OBJS)
	@$(CC) $(FLAGS) $(LIBFT) $(CORE_OBJS) -o $@
	@printf "\n$(GREEN)compiled: $(WHITE)$(COREWAR)$(EOC)\n"

clean:
	@make -C $(LIBFT_PATH) clean 
	@rm -f $(ASM_OBJS) $(CORE_OBJS)
	@rm -rf $(OBJS_PATH)
	@echo "$(RED)deleted: $(WHITE)objects files$(EOC)"

fclean: clean
	@make -C $(LIBFT_PATH) fclean 
	@rm -f $(ASM) $(COREWAR)
	@echo "$(RED)deleted: $(WHITE)$(ASM)$(EOC)"
	@echo "$(RED)deleted: $(WHITE)$(COREWAR)$(EOC)"

re: fclean all