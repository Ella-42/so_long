/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:50 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/28 18:02:57 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//exit in a clean way
int	close_window(t_mlx *mlx, int status)
{
	mlx_destroy_window(mlx->ptr, mlx->win);
	mlx_destroy_display(mlx->ptr);
	free(mlx->ptr);
	if (status == FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}

//error handler
int	error_handler(t_mlx *mlx, int type, int status, char **arr)
{
	if (type == AC || type == BER)
		ft_printf("Error: invalid argument\n");
	else if (type == MAP)
		ft_printf("Error: invalid map\n");
	else if (type == MALLOC)
		perror("malloc");
	else if (type == OPEN)
		perror("open");
	if (arr != NULL)
		free_arr(arr);
	if (status == ERROR)
		exit(EXIT_FAILURE);
	else if (status == SUCCESS)
		close_window(mlx, SUCCESS);
	else if (status == FAILURE)
		close_window(mlx, FAILURE);
	return (0);
}

//defines what happens when certain keys are pressed
int	key_event(int keycode, void *mlx)
{
	ft_printf("Keycode: %i\n", keycode);
	if (keycode == ESCAPE)
		close_window(mlx, SUCCESS);
	return (0);
}
