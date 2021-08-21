cmake_minimum_required(VERSION 3.20)
project(so_long C)

set(CMAKE_C_STANDARD 99)

include_directories(libs/libft/includes)
include_directories(libs/minilibx_macos)
include_directories(includes)

FILE(GLOB mlx libs/minilibx_macos/*.c)
FILE(GLOB prsrc srcs/*.c)
FILE(GLOB lsrcs libs/libft/srcs/*.c libs/libft/srcs/get_next_line.c libs/libft/srcs/get_next_line.c)
add_executable(so_long srcs/main.c srcs/validation.c includes/so_long.h srcs/error.c ${lsrcs} srcs/free.c libs/libft/srcs/ft_free_split.c
        ${prsrc} ${mlx})
