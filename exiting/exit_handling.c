/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 13:28:50 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/22 14:15:48 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

//exit in a clean way
int	close_window(t_data *mlx, int status)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	if (status == FAILURE)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
	return (0);
}

//error handler
int	error_handler(t_data *mlx, int type, int status)
{
	if (type == AC)
		ft_printf("Error: invalid number of arguments\n");
	else if (type == BER)
		ft_printf("Error: invalid file type\n");
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
