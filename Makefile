# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/18 17:00:45 by dmulish           #+#    #+#              #
#    Updated: 2017/10/09 14:56:24 by dmulish          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = filler
NAME2 = vizual_filler

FLAGS = -Wall -Wextra -Werror -I includes/ -g
MLX_FL = -lmlx -framework OpenGL -framework AppKit

FSRC = srcs/main.c
CSRC = srcs/free_res.c			\
	   srcs/init_str.c			\
	   srcs/get_coord.c			\
	   srcs/read_game.c			\
	   srcs/explor_map.c		\
	   srcs/first_read.c		\
	   srcs/read_piece.c		\
	   srcs/check_usr_num.c		\
	   srcs/explor_map_back.c	\
	   srcs/explor_map_forw.c
VSRC = viz/rot.c				\
	   viz/iso.c				\
	   viz/draw.c				\
	   viz/line.c				\
	   viz/main.c				\
	   viz/vizual.c				\
	   viz/draw_map.c			\
	   viz/new_elem.c			\
	   viz/read_map.c			\
	   viz/do_it_viz.c			\
	   viz/draw_grid.c			\
	   viz/loop_hook.c			\
	   viz/zero_angles.c		\

FBIN = $(FSRC:.c=.o)
CBIN = $(CSRC:.c=.o)
VBIN = $(VSRC:.c=.o)

LIB = -L libft -lft
LIBMLX = -L minilibx -lmlx

all: $(NAME1) $(NAME2)

$(NAME1): $(FBIN) $(CBIN)
	make -C libft/
	gcc -o $(NAME1) $(FLAGS) $(FBIN) $(CBIN) $(LIB)

$(NAME2): $(VBIN) $(CBIN)
	make -C minilibx/
	gcc -o $(NAME2) $(FLAGS) $(VBIN) $(CBIN) $(MLX_FL) $(MLXLIB) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(FBIN) $(CBIN) $(VBIN)
	make -C libft/ clean
	make -C minilibx/ clean

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2)

re: fclean all
