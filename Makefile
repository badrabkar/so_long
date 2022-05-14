CC = gcc

NAME = so_long

BONUS = so_long_bonus

SRC = so_long.c\
./get_next_line/get_next_line.c\
./get_next_line/get_next_line_utils.c\
putstr.c\
puterr.c\
check_errors.c\
check_errors_2.c\
read_map.c\
draw_map.c\
mouvement.c\
mouvement_utils.c\
window.c\

SRC_BONUS = ./get_next_line/get_next_line.c\
./get_next_line/get_next_line_utils.c\
so_long.c\
putstr.c\
puterr.c\
check_errors.c\
check_errors_2.c\
read_map.c\
draw_map.c\
mouvement.c\
mouvement_utils.c\
window.c\

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(BONUS): $(OBJ)
	$(CC) $(OBJ_BONUS) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)


%.o: %.c so_long.h
	$(CC) -Imlx -c $< -o $@

clean :
	rm *.o ./get_next_line/*.o
	
fclean : clean
	rm $(NAME) $(BONUS)

re: fclean all