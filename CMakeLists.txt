cmake_minimum_required(VERSION 3.20)
project(CUB C)

set(CMAKE_C_STANDARD 99)

add_executable(CUB
#        main.c
        auf.c
        1.c             11.c            13.c            3.c             5.c             7.c             9.c
        10.c            12.c            2.c             4.c             6.c             8.c
        cub_3d.c
        ft_atoi.c
        ft_strncmp.c
        functions_1.c
        functions_2.c
        functions_3.c
        functions_4.c
        gnl/get_next_line.c
        gnl/get_next_line_utils.c
        gnl/get_next_line.h
        cub.h)

target_link_libraries(CUB
        ${CMAKE_CURRENT_SOURCE_DIR}/libft/libft.a
        ${CMAKE_CURRENT_SOURCE_DIR}/mlx_st/libmlx.a
        "-framework OpenGL"
        "-framework AppKit"
        )
