/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:44:18 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/31 20:20:27 by lpeeters         ###   ########.fr       */
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
}

//fetch the correct sprite and send it to the window
void	img_handler(t_mlx *mlx, t_map *map, char c)
{
	if (c == '0')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->gimg,
			(map->x * 20), (map->y * 20));
	else if (c == '1')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->wimg,
			(map->x * 20), (map->y * 20));
	else if (c == 'C')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->cimg,
			(map->x * 20), (map->y * 20));
	else if (c == 'P')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pimg,
			(map->x * 20), (map->y * 20));
	else if (c == 'E')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->eimg,
			(map->x * 20), (map->y * 20));
}

//print the map to the graphical window
void	map2win(t_mlx *mlx, t_map *map)
{
	img_init(mlx);
	map->y = 0;
	while (map->arr[map->y] != NULL)
	{
		map->x = 0;
		while (map->arr[map->y][map->x] != '\0')
		{
			if (map->arr[map->y][map->x] == '0')
				img_handler(mlx, map, '0');
			else if (map->arr[map->y][map->x] == '1')
				img_handler(mlx, map, '1');
			else if (map->arr[map->y][map->x] == 'C')
				img_handler(mlx, map, 'C');
			else if (map->arr[map->y][map->x] == 'P')
				img_handler(mlx, map, 'P');
			else if (map->arr[map->y][map->x] == 'E')
				img_handler(mlx, map, 'E');
			map->x++;
		}
		map->y++;
	}
}

//print the map
void	print_map(t_map *map)
{
	int	x;

	ft_printf("\n");
	ft_printf("X ");
	x = 0;
	while (x <= map->count)
		ft_printf("%i", x++);
	ft_printf(" Y\n\n");
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		ft_printf("  %s %i\n", map->arr[map->i], map->i);
		map->i++;
	}
	ft_printf("\n");
}
