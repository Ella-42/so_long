/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/04 22:28:45 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//personal libft library functions
# include "libft/libft.h"

//minilibx library functions
# include "mlx/mlx.h"

//NULL
# include <stddef.h>

//bool
# include <stdbool.h>

//open
# include <fcntl.h>

//close
# include <unistd.h>

//malloc, free, exit
# include <stdlib.h>

//perror
# include <stdio.h>

//map data structure
typedef struct s_map
{
	char	**arr;
	char	**cpy;
	char	**suffix;
	char	*str;
	char	*line;
	bool	conditional;
	int		fd;
	int		count;
	int		i;
	int		j;
	int		coll;
	int		play;
	int		ext;
	int		ccoll;
	int		x;
	int		y;
	int		prev;
	int		mx;
	int		my;
}			t_map;

//mlx data structure
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*gimg;
	void	*wimg;
	void	*cimg;
	void	*pimg;
	void	*eimg;
	void	*pcimg;
	void	*peimg;
	void	*oimg;
	int		y;
	int		x;
	int		n;
	t_map	*map;
}			t_mlx;

//backtracing data structure
typedef struct s_bt
{
	int			mv;
	struct s_bt	*next;
}				t_bt;

//macros
# define SUCCESS 0
# define TRUE 0
# define FAILURE 1
# define ERROR 1
# define FALSE 1
# define CASE1 1
# define BT 1
# define CURR 2
# define CASE2 2
# define CASE3 3
# define CASE4 4
# define MALLOC 12
# define MAP -22
# define AC 22
# define BER 22
# define OPEN 77

//key macros
# define SPACEBAR 32
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define M 109
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/*************************************/
/*              so_long              */
/*************************************/

//initialize the map strucuture's values
void	map_init(t_map *map, char *file);

//parse map, handle errors, convert into interactive 2d video game
int		main(int ac, char **av);

/*************************************/
/*              handling             */
/*************************************/

//exit in a clean way
int		close_window(t_mlx *mlx, int status);

//handles errors
void	error_handler(t_mlx *mlx, int type, int status, t_map *map);

//defines what happens when certain keys are pressed
int		key_event(int keycode, t_mlx *mlx);

/*************************************/
/*           map_checking            */
/*************************************/

//check if argument is of the correct filetype
void	check_filetype(t_map *map);

//calculate the length of a map and allocate memory for it
char	**maparr(t_map *map);

//convert map to array
char	**maptoarr(t_map *map);

//parse the elements in the map and check if they are correct
void	mapparser(t_map *map);

//check if map is valid
void	checkmap(t_map *map);

/*************************************/
/*       backtracing_algorithm       */
/*************************************/

//fetch the position of a character
void	getcpos(t_map *map, char c);

//move to a given direction and store it in the singly linked list
void	case_handler(t_map *map, t_bt **bt, int arrow);

//trace steps back untill point of intrest
void	backtracer(t_bt **bt, t_map *map);

//master algorithm
void	bt_algo(t_map *map);

/*************************************/
/*        singly_linked_list         */
/*************************************/

//free the memory of a singly linked list
void	free_sll(t_bt *bt, t_bt **curr, int structure);

//initialize singly linked list
t_bt	*mksll(int move);

//add values to the singly linked list
void	addmv(t_bt **bt, int move);

//print a linked list's values
void	print_sll(t_bt *bt);

/*************************************/
/*           map_to_window           */
/*************************************/

//load the xpm files to image pointers
void	img_init(t_mlx *mlx);

//fetch the correct sprite and send it to the window
void	img_handler(t_mlx *mlx, t_map *map);

//print the map to the graphical window around the player
void	map2win(t_mlx *mlx, t_map *map);

//print the map
void	print_map(t_map *map);

/*************************************/
/*           game_handling           */
/*************************************/

//fetch the position of a character
int		checkc(t_map *map);

//print out all the keymappings
void	print_legend(void);

//update an image to the window
void	upd_win(t_mlx *mlx, t_map *map, char c);

//count how many steps were taken and display them
void	step(t_map *map);

//move the player
void	move(t_mlx *mlx, t_map *map, int keycode);

#endif
