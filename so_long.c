/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/23 14:57:42 by lpeeters         ###   ########.fr       */
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

//load the xpm files to image pointers
void	img_init(t_mlx *mlx)
{
	mlx->n = 0;
	mlx->gimg = mlx_xpm_file_to_image(mlx->ptr, "sprites/grass_200x200.xpm",
			&mlx->n, &mlx->n);
	mlx->wimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/rock_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->cimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/pokeball_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->pimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->eimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/tall_grass_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->pcimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_with_pokeball_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->peimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_in_tall_grass_on_grass_200x200.xpm", &mlx->n, &mlx->n);
	mlx->oimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/water_200x200.xpm", &mlx->n, &mlx->n);
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
	mlx.win = mlx_new_window(mlx.ptr, 3000, 1800, "Not_Pokemon");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	img_init(&mlx);
	map2win(&mlx, &map);
	mlx.map = &map;
	map.count = 0;
	ft_printf("\n");
	step_or_print_legend(NULL, PRINT_LEGEND);
	if (map.cccoll == 1)
		ft_printf("You have got %i Pokeball to collect\n\n", map.cccoll);
	else
		ft_printf("You have got %i Pokeballs to collect\n\n", map.cccoll);
	mlx_loop(mlx.ptr);
}
