# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/08/22 10:31:43 by nephilister      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS_LIST	=	main.c\
				error.c\
				free.c\
				validation.c\
				game_start.c\
				end_game.c\
				update.c\
				drawing.c\
				open_images.c\
				more_open_images.c\
				input.c\
				generate_cellmap.c\
				enemy_list.c\
				enemy_behavior.c
SRCS_DIR	=	srcs/
SRCS		=	$(addprefix $(SRCS_DIR), $(SRCS_LIST))

OBJS_LIST	=	$(SRCS_LIST:.c=.o)
OBJS_DIR	=	objects/
OBJS		=	$(addprefix $(OBJS_DIR), $(OBJS_LIST))

CC 			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

INCLUDES	=	-I$(LIBFT_HEADER) -I$(HEADERS_DIR) -I$(MINILIBX_HEADERS)

LIBFT_DIR		=	./libs/libft/
LIBFT_HEADER 	=	$(LIBFT_DIR)includes/
LIBFT			=	$(LIBFT_DIR)libft.a

HEADERS_DIR		=	./includes/
HEADERS_LIST	=	so_long.h
HEADERS 		=	$(addprefix $(HEADERS_DIR), $(HEADERS_LIST))

MINILIBX = $(MINILIBX_DIR)libmlx.a
MINILIBX_DIR = ./libs/minilibx_macos/
MINILIBX_HEADERS = $(MINILIBX_DIR)

LIBRARIES = -lmlx -lft\
		 -L$(LIBFT_DIR) -L$(MINILIBX_DIR)\
		 -framework OpenGL -framework AppKit

RM	=	rm -rf

# COLORS
GREEN = \033[0;32m
BLUE= \033[0;34m
RED = \033[0;31m
RESET = \033[0m


LIBA = libft.a
MLXLIB = libmlx.a

all : $(NAME)

$(NAME) : $(LIBFT) $(MINILIBX) $(OBJS_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	@echo "$(NAME): $(BLUE)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) -g $(СFLAGS) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(BLUE)creating $(NAME)$(RESET)"

$(LIBFT) :
	@echo "$(NAME): $(BLUE)creating $(LIBA)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

$(MINILIBX) :
	@echo "$(NAME): $(BLUE)creating $(MLXLIB)$(RESET)"
	@$(MAKE) -C $(MINILIBX_DIR)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(MINILIBX_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@$(RM) $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBA) was deleted$(RESET)"
	@echo "$(NAME): $(RED)$(MLXLIB) was deleted$(RESET)"


re : fclean all

.PHONY : all clean fclean re