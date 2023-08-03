/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/03 21:43:06 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//initialize the map strucuture's values
void	map_init(t_map *map, char *file)
{
	map->arr = NULL;
	map->cpy = NULL;
	map->str = file;
	map->conditional = false;
	map->count = 0;
	map->i = 0;
	map->j = 0;
	map->coll = 0;
	map->play = 0;
	map->ext = 0;
	map->y = 0;
	map->x = 0;
	map->prev = 0;
}

//parse map, handle errors, convert into interactive 2d video game
int	main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;

	if (ac != 2)
		error_handler(NULL, AC, ERROR, NULL);
	map_init(&map, av[1]);
	checkmap(&map);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 300, 180, "Not_Pokemon");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	img_init(&mlx);
	map2win(&mlx, &map);
	mlx.map = &map;
	map.count = 0;
	mlx_loop(mlx.ptr);
}
