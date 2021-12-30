# ****************************** Compiler Options ******************************
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -g
LIBMLX		+= -L /usr/local/lib -lmlx -I /usr/local/include
FRAMEWORKS	+= -framework OpenGL -framework AppKit

# ******************************* Other commands *******************************
RM	:= rm -f

# ******************************** Directories *********************************
INCLUDES_DIR	:= include
SRCS_DIR		:= src
LIBS_DIR		:= lib

# *********************************** Files ************************************
NAME	:= so_long
SRCS	:=
HEADERS	:=
OBJS	:= $(SRCS:.c=.o)
LIBS	:= libgnl.a
MAIN	:= main.c

# ********************************** Targets ***********************************
all:	$(NAME)
		./$(NAME)

$(NAME):	$(OBJS) $(addprefix $(INCLUDES_DIR)/, $(HEADERS))
			$(CC) $(CFLAGS) $(LIBMLX) $(FRAMEWORKS) $(OBJS) $(MAIN) -o $(NAME)

%.o:	$(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c -o $@ $<

gnl:
	make -C $(LIBS_DIR)/get_next_line
	make clean -C $(LIBS_DIR)/get_next_line
	mv $(LIBS_DIR)/get_next_line/libgnl.a .

clean:
	$(RM) $(OBJS)
	$(RM) $(LIBS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
