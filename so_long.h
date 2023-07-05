/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/05 17:39:54 by lpeeters         ###   ########.fr       */
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
}			t_map;

//macros
# define SUCCESS 0
# define TRUE 0
# define FAILURE 1
# define ERROR 1
# define FALSE 1
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
/*           exit_handling           */
/*************************************/

//exit in a clean way
int		close_window(t_mlx *mlx, int status);

//error handler
int		error_handler(t_mlx *mlx, int type, int status, char **arr);

//defines what happens when certain keys are pressed
int		key_event(int keycode, void *mlx);

/*************************************/
/*              checker              */
/*************************************/

//check if argument is of the correct filetype
void	check_filetype(t_map *map);

//calculate the length of a map and allocate memory for it
char	**maparr(t_map *map);

//convert map to array
char	**maptoarr(t_map *map);

//print the map
void	checkmap(t_map *map);

//

//
void	testing(t_map *map);

#endif
