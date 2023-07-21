/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/21 22:52:51 by lpeeters         ###   ########.fr       */
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

//free, exit
# include <stdlib.h>

//perror
# include <stdio.h>

//mlx data structure
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	int		y;
	int		x;
}			t_mlx;

//map data structure
typedef struct s_map
{
	char	**arr;
	char	**suffix;
	char	*str;
	char	*line;
	bool	conditional;
	int		count;
	int		coll;
	int		ext;
	int		play;
	int		fd;
	int		i;
	int		j;
	int		x;
	int		y;
	int		prev;
}			t_map;

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
# define CASE2 2
# define CURR 2
# define CASE3 3
# define CASE4 4
# define MALLOC 12
# define MAP -22
# define AC 22
# define BER 22
# define OPEN 77

//key macros
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

/*************************************/
/*              so_long              */
/*************************************/

//parse map, handle errors, convert into interactive 2d video game
int		main(int ac, char **av);

//print a linked list's values
void	print_sll(t_bt *bt);

//print the map
void	print_map(t_map *map);

/*************************************/
/*           exit_handling           */
/*************************************/

//exit in a clean way
int		close_window(t_mlx *mlx, int status);

//handles errors
int		error_handler(t_mlx *mlx, int type, int status, char **arr);

//defines what happens when certain keys are pressed
int		key_event(int keycode, void *mlx);

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

//initialize singly linked list
t_bt	*mksll(int move);

//add values to the singly linked list
void	addmv(t_bt **bt, int move);

//free the memory of a singly linked list
void	free_sll(t_bt *bt, t_bt **curr, int structure);

#endif
