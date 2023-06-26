/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/26 18:43:16 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//parse map, handle errors, convert into interactive 2d video game
int	main(int ac, char **av)
{
	char	**map;
	//t_data	mlx;
	//(void)ac;
	if (ac != 2)
		error_handler(NULL, AC, ERROR);
	check_filetype(av[1]);
	map = check_map(av[1]);
	free_arr(map);
	//mlx.mlx = mlx_init();
	//mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "so_long");
	//mlx_key_hook(mlx.win, key_event, &mlx);
	//mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	//mlx_loop(mlx.mlx);
	return (0);
}
