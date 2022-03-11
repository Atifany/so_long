# executable
SO_LONG = so_long

# sources
_SRC = *.c
SRC_DIR = sources
SRC = $(_SRC:%=$(SRC_DIR)/%)

# headers
HEADS = so_long.h

# libraries
MLX = libmlx.a
MLX_DIR = mlx
LIBFT = libft.a
LIBFT_DIR = libft
FT_PRINTF = ft_printf.a
FT_PRINTF_DIR = ft_printf
LIBS = $(MLX:%=$(MLX_DIR)/%) $(LIBFT:%=$(LIBFT_DIR)/%) $(FT_PRINTF:%=$(FT_PRINTF_DIR)/%)

# Make commands
GCC = gcc -O2 -Wall -Wextra -Werror
RM = rm -f

# rules
all: compile_libs $(SO_LONG)

compile_libs:
	@make -C $(FT_PRINTF_DIR)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)

$(SO_LONG): $(SRC) $(HEADS)
	$(GCC) $(SRC) $(LIBS) -framework OpenGL -framework AppKit -o $@

clean:
	$(RM) $(SO_LONG)

fclean: clean
	@make clean -C $(MLX_DIR)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all re clean compile_libs