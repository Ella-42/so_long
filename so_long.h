/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/26 19:29:36 by lpeeters         ###   ########.fr       */
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

//open
# include <fcntl.h>

//free, exit
# include <stdlib.h>

//mlx data structure
typedef struct s_data
{
	void	*mlx;
	void	*win;
}			t_data;

//macros
# define SUCCESS 0
# define TRUE 0
# define FAILURE 1
# define ERROR 1
# define FALSE 1
# define AC 2
# define BER 128

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
int		close_window(t_data *mlx, int status);

//error handler
int		error_handler(t_data *mlx, int type, int status);

//defines what happens when certain keys are pressed
int		key_event(int keycode, void *mlx);

/*************************************/
/*              checker              */
/*************************************/

//check if argument is of the correct filetype
void	check_filetype(char *str);

//calculate the length of a map
int		maplen(char	*str);

//print the map
void	printmap(char **map);

//convert map to array
char	**maptoarr(char *str);

#endif
