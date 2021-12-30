# ****************************** Compiler Options ******************************
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

# ******************************* Other commands *******************************
RM	:= rm -f
AR	:= ar rcs

# ******************************** Directories *********************************
INCLUDES_DIR	:= ../../include
SRCS_DIR		:= .

# *********************************** Files ************************************
NAME	:= libgnl.a
SRCS	:= get_next_line.c get_next_line_utils.c
OBJS	:= $(SRCS:.c=.o)

# ********************************** Targets ***********************************
all:	$(NAME)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $?

%.o:	$(SRCS_DIR)/%.c
		$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c -o $@ $<

clean:
	$(RM) $(OBJS)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
