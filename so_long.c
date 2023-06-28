/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/28 18:29:37 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//parse map, handle errors, convert into interactive 2d video game
int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		error_handler(NULL, AC, ERROR, NULL);
	map.str = av[1];
	check_filetype(&map);
	map.arr = maptoarr(&map);
	checkmap(&map);
	free_arr(map.arr);
	return (0);
}

/*//parse map, handle errors, convert into interactive 2d video game
int	main(int ac, char **av)
{
	char	**map;
	t_mlx	mlx;

	if (ac != 2)
		error_handler(NULL, AC, ERROR, NULL);
	check_filetype(av[1]);
	map = maptoarr(av[1]);
	free_arr(map);
	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "so_long");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}*/
