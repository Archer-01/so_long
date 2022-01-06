# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LIBMLX		:= -L /usr/local/lib -lmlx -I /usr/local/include
LIBGNL		:= -L. -lgnl
LIBFT		:= -L. -lft
FRAMEWORKS	:= -framework OpenGL -framework AppKit

# ******************************* Other commands *******************************
RM	:= rm -f

# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
LIBS_DIR		:= lib

# *********************************** Files ************************************
NAME	:= so_long
SRCS	:= ft_map_parser.c ft_map_checks.c ft_render_map.c ft_colors.c \
			ft_mlx_pixel.c ft_images.c
HEADERS	:= get_next_line.h libft.h ft_map_parser.h ft_map_checks.h \
			ft_render_map.h ft_colors.h ft_mlx_pixel.h ft_images.h \
			ft_mlx_types.h
OBJS	:= $(SRCS:.c=.o)
LIBS	:= libgnl.a libft.a
MAIN	:= main.c

# ********************************** Targets ***********************************
all:	$(NAME)

$(NAME):	$(OBJS) $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) $(LIBS) $(MAIN)
			$(CC) $(CFLAGS) $(LIBMLX) $(LIBFT) $(LIBGNL) $(FRAMEWORKS) $(OBJS) $(MAIN) -o $(NAME)

%.o:	$(SRCS_DIR)/%.c $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
		$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c -o $@ $<

libgnl.a:
	make -C $(LIBS_DIR)/get_next_line
	make clean -C $(LIBS_DIR)/get_next_line
	mv $(LIBS_DIR)/get_next_line/libgnl.a .

libft.a:
	make -C $(LIBS_DIR)/libft
	make clean -C $(LIBS_DIR)/libft
	mv $(LIBS_DIR)/libft/libft.a .

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
