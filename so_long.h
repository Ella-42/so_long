/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:59 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/16 23:06:43 by lpeeters         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*personal libft library functions*/
# include "libft/libft.h"

/*minilibx library functions*/
# include "mlx/mlx.h"

/*data structure*/
typedef struct s_data
{
	void	*ptr;
	char	*adr;
	int		bpp;
	int		llen;
	int		end;
}	t_data;

typedef struct s_edges
{
	int	l;
	int	r;
	int	t;
	int	b;
	int	m;
}	t_edges;

#endif
