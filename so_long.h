/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/20 08:21:20 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*personal libft library functions*/
# include "libft/libft.h"

/*minilibx library functions*/
# include "mlx/mlx.h"

/*mlx data structure*/
typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*img;
	char	*adr;
	int		bpp;
	int		llen;
	int		end;
}	t_data;

/*macros*/
# define SUCCESS 0
# define TRUE 0
# define FAILURE 1
# define ERROR 1
# define FALSE 1
# define AC 2
# define BER 128

/*key macros*/
# define ESCAPE 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

#endif
