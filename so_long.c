/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/20 08:21:14 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*exit in a clean way*/
int	close_window(t_data *mlx, int status)
{
	mlx_destroy_window(mlx->mlx, mlx->win);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
	if (status == SUCCESS)
		exit(EXIT_SUCCESS);
	else if (status == FAILURE)
		exit(EXIT_FAILURE);
	return (0);
}

/*defines what happens when certain keys are pressed*/
int	key_event(int keycode, void *mlx)
{
	ft_printf("Keycode: %i\n", keycode);
	if (keycode == ESCAPE)
		close_window(mlx, SUCCESS);
	return (0);
}

/*error handler*/
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

int	check_filetype(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.' && str[i + 1] != '\0')
			return (TRUE);
		i++;
	}
	error_handler(NULL, BER, ERROR);
	return (FALSE);
}

/*parse map, handle errors, convert into interactive 2d video game*/
int	main(int ac, char **av)
{
	t_data	mlx;
	char	**suffix;

	(void)ac;
	if (ac != 2)
		error_handler(&mlx, AC, ERROR);
	if (check_filetype(av[1]) == TRUE)
	{
		suffix = ft_split(av[1], '.');
		if (ft_strncmp(suffix[1], "ber", 3) || ft_strlen(suffix[1]) != 3)
		{
			free_arr(suffix);
			error_handler(NULL, BER, ERROR);
		}
		free_arr(suffix);
	}
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1920, 1080, "so_long");
	mlx_key_hook(mlx.win, key_event, &mlx);
	mlx_hook(mlx.win, 17, 0L, close_window, &mlx);
	mlx_loop(mlx.mlx);
	return (0);
}
