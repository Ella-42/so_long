/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_to_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 20:44:18 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/07 19:20:25 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
	else if (map->arr[map->my][map->mx] == '2')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->pcimg, mlx->x, mlx->y);
	else if (map->arr[map->my][map->mx] == '3')
		mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->peimg, mlx->x, mlx->y);
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
	ft_printf("     ===========MAP===========     \n\n");
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		map->j = 0;
		while (map->arr[map->i][map->j] != '\0')
		{
			if (map->arr[map->i][map->j] == '2'
			|| map->arr[map->i][map->j] == '3')
				ft_printf("P");
			else
				ft_printf("%c", map->arr[map->i][map->j]);
			map->j++;
		}
		ft_printf("\n");
		map->i++;
	}
	ft_printf("\n");
}
