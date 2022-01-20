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
SRCS	:= ft_checks_1.c \
			ft_checks_2.c \
			ft_destroy_1.c \
			ft_destroy_2.c \
			ft_enemy.c \
			ft_hooks.c \
			ft_init_1.c \
			ft_init_2.c \
			ft_move.c \
			ft_parser.c \
			ft_render.c \
			ft_utils_1.c \
			ft_utils_2.c
HEADERS	:= ft_destroy.h \
			ft_enemy.h \
			ft_errors.h \
			ft_hooks.h \
			ft_init.h \
			ft_move.h \
			ft_parser.h \
			ft_render.h \
			ft_types.h \
			ft_utils.h \
			get_next_line.h \
			libft.h
OBJS	:= $(SRCS:.c=.o)
LIBS	:= libgnl.a libft.a
MAIN	:= main.c

# ********************************** Targets ***********************************
all:	$(NAME)

$(NAME):	$(OBJS) $(addprefix $(INCLUDES_DIR)/, $(HEADERS)) $(LIBS) $(MAIN)
			$(CC) $(CFLAGS) -I $(INCLUDES_DIR) $(LIBMLX) $(LIBFT) $(LIBGNL) \
			$(FRAMEWORKS) $(OBJS) $(MAIN) -o $(NAME)

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
