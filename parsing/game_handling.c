/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 21:39:23 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/01 21:42:03 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//fetch the position of a character
int	checkc(t_map *map)
{
	map->i = 0;
	while (map->arr[map->i] != NULL)
	{
		map->j = 0;
		while (map->arr[map->i][map->j] != '\0')
		{
			if (map->arr[map->i][map->j] == 'C')
				return (0);
			map->j++;
		}
		map->i++;
	}
	return (1);
}

//update an image to the window
void	upd_win(t_mlx *mlx, t_map *map, char c)
{
	if (c == '0')
	{
		map->arr[map->y][map->x] = '0';
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->gimg, map->x * 20, map->y * 20);
	}
	else if (c == 'P')
	{
		map->arr[map->y][map->x] = 'P';
		mlx_put_image_to_window(mlx->ptr, mlx->win,
			mlx->pimg, map->x * 20, map->y * 20);
	}
}

//move the player
void	move(t_mlx *mlx, t_map *map, int keycode)
{
	if (map->arr[map->y][map->x] != 'E')
		upd_win(mlx, map, '0');
	if (keycode == UP && map->arr[map->y - 1][map->x] != '1')
		map->y--;
	else if (keycode == DOWN && map->arr[map->y + 1][map->x] != '1')
		map->y++;
	else if (keycode == LEFT && map->arr[map->y][map->x - 1] != '1')
		map->x--;
	else if (keycode == RIGHT && map->arr[map->y][map->x + 1] != '1')
		map->x++;
	else
		map->count--;
	map->count++;
	ft_printf("current moves: %i\n", map->count);
	if (map->arr[map->y][map->x] == 'E')
	{
		if (checkc(map))
			close_window(mlx, SUCCESS);
		else
			ft_printf("You are not yet ready for battle\n");
	}
	if (map->arr[map->y][map->x] != 'E')
		upd_win(mlx, map, 'P');
}
