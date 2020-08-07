cmake_minimum_required(VERSION 3.15)
project(fdf)

add_compile_options(-Wall -Wextra -Werror -g)
set(CMAKE_C_STANDARD 99)

include_directories(
        includes
        libft/
)

link_directories(push_swap
        libft)

add_executable(fdf
       sources/fdf.c sources/read_file.c)


target_link_libraries(fdf
        "ft"
        "mlx"
        "-framework OpenGL"
        "-framework AppKit"
        )