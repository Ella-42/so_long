/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/25 23:24:24 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//testing
void	test(t_mlx *mlx, t_map *map)
{
	int		y;
	int		x;

	y = 0;
	print_map(map);
	while (map->arr[y] != NULL)
	{
		x = 0;
		while (map->arr[y][x] != '\0')
		{
			if (map->arr[y][x] == '0')
				mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img,
					(x * 20), (y * 20));
			x++;
		}
		y++;
	}
}

//parse map, handle errors, convert into interactive 2d video game
int	main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;

	if (ac != 2)
		error_handler(NULL, AC, ERROR, NULL);
	map.str = av[1];
	checkmap(&map);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "so_long");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx.y = 0;
	mlx.x = mlx.y;
	mlx.img = mlx_xpm_file_to_image(mlx.ptr, "sprites/grass_20x20.xpm",
			&mlx.y, &mlx.x);
	test(&mlx, &map);
	free_arr(map.arr);
	mlx_loop(mlx.ptr);
	return (0);
}

//print a linked list's values
void	print_sll(t_bt *bt)
{
	t_bt	*curr;

	ft_printf("\ncurrent saved moves:");
	curr = bt;
	while (curr != NULL)
	{
		if (curr->mv == UP)
			ft_printf(" UP");
		else if (curr->mv == LEFT)
			ft_printf(" LEFT");
		else if (curr->mv == DOWN)
			ft_printf(" DOWN");
		else if (curr->mv == RIGHT)
			ft_printf(" RIGHT");
		curr = curr->next;
	}
	ft_printf("\n");
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
