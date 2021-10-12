NAME = push_swap
FLAGS = -Wall -Wextra -Werror
OBJ_DIR = ./objects
SRC_DIR = ./sources
OBJS =	$(OBJ_DIR)/main.o\
		$(OBJ_DIR)/clean.o\
		$(OBJ_DIR)/commands.o\
		$(OBJ_DIR)/do_rotations.o\
		$(OBJ_DIR)/ft_atol.o\
		$(OBJ_DIR)/input_proc.o\
    	$(OBJ_DIR)/mini_sort.o\
    	$(OBJ_DIR)/rotate.o\
    	$(OBJ_DIR)/sort.o\
    	$(OBJ_DIR)/sort_utils.o\
    	$(OBJ_DIR)/stack.o\
    	$(OBJ_DIR)/swap_push.o\
    	$(OBJ_DIR)/utils.o
HDRS = 	./include/push_swap.h
PRINTF = $(SRC_DIR)/printf
LIBS = -L$(PRINTF) -lftprintf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS) $(HDRS)
	$(MAKE) -C $(PRINTF)
	gcc $(FLAGS) -o $@ $(OBJS) -I$(HDRS) $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	gcc $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir objects

clean:
	$(MAKE) -C $(PRINTF) clean
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(PRINTF) fclean

re: fclean all
