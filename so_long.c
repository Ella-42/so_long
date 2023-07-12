/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/07/12 22:13:59 by lpeeters         ###   ########.fr       */
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
	//t_mlx	mlx;

	//mlx.ptr = mlx_init();
	//mlx.win = mlx_new_window(mlx.ptr, 1920, 1080, "so_long");
	//mlx_key_hook(mlx.win, key_event, &mlx);
	//mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	//mlx_loop(mlx.ptr);

//print a linked list's values
void	print_dll(t_bt *bt)
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
