/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/14 03:39:13 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_logger(int keycode, void *param)
{
	void	*mlx;

	if (keycode == 27)
	{
		mlx = param;
		mlx_loop_end(mlx);
	}
	return (0);
}

int	main(void)
{
	void	*mlx;
	void	*win;
	char	*title;

	title = "testing";
	mlx = mlx_init();
	win = mlx_new_window(mlx, 750, 500, title);
	mlx_loop(mlx);
	mlx_key_hook(win, key_logger, mlx);
}
