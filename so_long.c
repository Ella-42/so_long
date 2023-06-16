/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpeeters <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 15:24:34 by lpeeters          #+#    #+#             */
/*   Updated: 2023/06/16 23:06:41 by lpeeters         ###   ########.fr       */
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

void	put_pixel(t_data *img, int x, int y, int color)
{
	char	*dst;

	dst = img->adr + (y * img->llen + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

void	filler(t_data *img, t_edges shape, int color)
{
	int	t;

	t = shape.t;
	while (shape.l <= shape.r)
	{
		shape.t = t;
		while (shape.t <= shape.b)
		{
			put_pixel(img, shape.l, shape.t, color);
			shape.t++;
		}
		shape.l++;
	}
}

void	draw_tri(t_data *img, t_edges shape, int color)
{
	int	l;
	int	r;

	put_pixel(img, shape.t, shape.m, color);
	l = shape.m - 1;
	r = shape.m + 1;
	while (shape.t <= shape.b)
	{
		put_pixel(img, l, shape.t, color);
		put_pixel(img, r, shape.t, color);
		l--;
		r++;
		shape.t++;
	}
	while (l <= r)
	{
		put_pixel(img, l, shape.b, color);
		l++;
	}
}

int	main(void)
{
	void	*mlx;
	int	width;
	int	length;
	char	*title;
	void	*win;
	t_data	img;
	//t_edges	rect;
	//t_edges	sqr;
	t_edges	tri;

	width = 1920;
	length = 1080;
	mlx = mlx_init();
	title = "so_long";
	win = mlx_new_window(mlx, width, length, title);
	img.ptr = mlx_new_image(mlx, width, length);
	img.adr = mlx_get_data_addr(img.ptr, &img.bpp, &img.llen, &img.end);
	//rect.t = length / 4;
	//rect.b = length - rect.t;
	//rect.l = width / 4;
	//rect.r = width - rect.l;
	//sqr.t = 0;
	//sqr.b = length;
	//sqr.l = (width / 2) - (length / 2);
	//sqr.r = (width / 2) + (length / 2);
	tri.t = length / 2 - length / 4;
	tri.b = length - length / 4;
	tri.m = width / 2;
	draw_tri(&img, /*rectsqr*/tri, 0xFFFFFF);
	mlx_put_image_to_window(mlx, win, img.ptr, 0, 0);
	mlx_loop(mlx);
}
