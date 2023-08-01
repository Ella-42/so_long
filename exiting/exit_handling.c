/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:50 by lpeeters          #+#    #+#             */
/*   Updated: 2023/08/01 21:35:46 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//exit in a clean way
int	close_window(t_mlx *mlx, int status)
{
	if (mlx->map->arr != NULL)
		free_arr(mlx->map->arr);
	mlx_destroy_image(mlx->ptr, mlx->gimg);
	mlx_destroy_image(mlx->ptr, mlx->wimg);
	mlx_destroy_image(mlx->ptr, mlx->pimg);
	mlx_destroy_image(mlx->ptr, mlx->cimg);
	mlx_destroy_image(mlx->ptr, mlx->eimg);
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	if (status == FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}

//handles errors
void	error_handler(t_mlx *mlx, int type, int status, t_map *map)
{
	ft_printf("Error\n");
	if (type == AC || type == BER)
		ft_printf("Invalid argument\n");
	else if (type == MAP)
		ft_printf("Invalid map\n");
	else if (type == MALLOC)
		perror("malloc");
	else if (type == OPEN)
		perror("open");
	if (map->arr != NULL)
		free_arr(map->arr);
	if (map->cpy != NULL)
		free_arr(map->cpy);
	if (status == ERROR)
		exit(EXIT_FAILURE);
	else if (status == SUCCESS)
		close_window(mlx, SUCCESS);
	else if (status == FAILURE)
		close_window(mlx, FAILURE);
}

//defines what happens when certain keys are pressed
int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == ESCAPE)
		close_window(mlx, SUCCESS);
	if (keycode == UP || keycode == W)
		move(mlx, mlx->map, UP);
	if (keycode == DOWN || keycode == S)
		move(mlx, mlx->map, DOWN);
	if (keycode == LEFT || keycode == A)
		move(mlx, mlx->map, LEFT);
	if (keycode == RIGHT || keycode == D)
		move(mlx, mlx->map, RIGHT);
	return (0);
}
