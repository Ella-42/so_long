/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:44:18 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/03 21:50:31 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//load the xpm files to image pointers
void	img_init(t_mlx *mlx)
{
	mlx->n = 0;
	mlx->gimg = mlx_xpm_file_to_image(mlx->ptr, "sprites/grass_20x20.xpm",
			&mlx->n, &mlx->n);
	mlx->wimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/rock_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->cimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/pokeball_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->pimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->eimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/tall_grass_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->pcimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_with_pokeball_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->peimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/May_in_tall_grass_on_grass_20x20.xpm", &mlx->n, &mlx->n);
	mlx->oimg = mlx_xpm_file_to_image(mlx->ptr,
			"sprites/water_20x20.xpm", &mlx->n, &mlx->n);
}

//fetch the correct sprite and send it to the window
void	img_handler(t_mlx *mlx, t_map *map)
{
	if (map->arr[map->my][map->mx] == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->gimg, mlx->x, mlx->y);
	else if (map->arr[map->my][map->mx] == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->wimg, mlx->x, mlx->y);
	else if (map->arr[map->my][map->mx] == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->cimg, mlx->x, mlx->y);
	else if (map->arr[map->my][map->mx] == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pimg, mlx->x, mlx->y);
	else if (map->arr[map->my][map->mx] == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->eimg, mlx->x, mlx->y);
}

//print the map to the graphical window around the player
void	map2win(t_mlx *mlx, t_map *map)
{
	getcpos(map, 'P');
	map->my = map->y - 4;
	mlx->y = 0;
	while (mlx->y <= 160)
	{
		map->mx = map->x - 7;
		mlx->x = 0;
		while (mlx->x <= 280)
		{
			if (map->my < 0 || map->mx < 0 || map->my >= map->i
				|| map->mx >= map->j)
				mlx_put_image_to_window(mlx->ptr, mlx->win,
					mlx->oimg, mlx->x, mlx->y);
			else
				img_handler(mlx, map);
			mlx->x += 20;
			map->mx++;
		}
		mlx->y += 20;
		map->my++;
	}
}

//print the map
void	print_map(t_map *map)
{
	int	y;

	ft_printf("\n");
	ft_printf("X ");
	map->j = 0;
	while (map->arr[0][map->j] != '\0')
		ft_printf("%i", map->j++);
	ft_printf("\n\n");
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		ft_printf("  %s %i\n", map->arr[map->i], map->i);
		map->i++;
	}
	ft_printf("\n");
	y = -1;
	while (y++ < map->j)
		ft_printf(" ");
	ft_printf("   Y\n\n");
}
