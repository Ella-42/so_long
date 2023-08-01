/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/01 21:04:27 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

//test
void	move_test(t_mlx *mlx, t_map *map, int keycode)
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
	mlx.win = mlx_new_window(mlx.ptr, map.j * 20, map.i * 20, "Not_Pokemon");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	map2win(&mlx, &map);
	mlx.map = &map;
	getcpos(&map, 'P');
	map.count = 0;
	mlx_loop(mlx.ptr);
}
