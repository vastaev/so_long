# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nephilister <nephilister@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 12:30:03 by cjoanne           #+#    #+#              #
#    Updated: 2021/08/18 05:13:44 by nephilister      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	so_long

SRCS_LIST	=	main.c\
				error.c\
				free.c\
				validation.c\
				window.c\
				image.c\
				hooks.c\
				game_start.c
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

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJS_DIR) $(OBJS)
	@$(CC) $(OBJS) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	@echo "$(NAME): $(BLUE)$(NAME) object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@$(CC) $(СFLAGS) $(INCLUDES) -c $< -o $@
	
$(OBJS_DIR) :
	@mkdir -p $(OBJS_DIR)
	@echo "$(NAME): $(BLUE)creating $(NAME)$(RESET)"

$(LIBFT) :
	@echo "$(NAME): $(BLUE)creating $(LIBA)$(RESET)"
	@$(MAKE) -C $(LIBFT_DIR)

clean :
	@$(RM) $(OBJS_DIR)
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"
	@$(RM) $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBA) was deleted$(RESET)"

re : fclean all

.PHONY : all clean fclean re