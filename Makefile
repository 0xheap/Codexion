NAME		= codexion

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread
SRC_DIR		= coders
OBJ_DIR		= obj

SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/utils.c \
			  $(SRC_DIR)/dongles.c \
			  $(SRC_DIR)/scheduler.c \
			  $(SRC_DIR)/coder.c \
			  $(SRC_DIR)/monitor.c \
			  $(SRC_DIR)/simulation.c

OBJS		= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all:		$(NAME)

$(OBJ_DIR):
			mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
			$(CC) $(CFLAGS) -I$(SRC_DIR) -c $< -o $@

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
			rm -rf $(OBJ_DIR)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
