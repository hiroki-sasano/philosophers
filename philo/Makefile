NAME	:= philo

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror
INC		:= -I include
SRC_DIR	:= src
OBJ_DIR	:= obj

SRC		:= main.c parse.c init.c destroy.c time.c utils.c thread.c\
			actions.c fork.c print.c routine.c stop_utils.c monitor.c
SRCS	:= $(addprefix $(SRC_DIR)/, $(SRC))
OBJS	:= $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -pthread -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/philo.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
