/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 17:30:19 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/06 19:06:18 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_data_init(t_fractal *fractal, char *real, char *im)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->real_julia = ft_atod(real);
		fractal->im_julia = ft_atod(im);
	}
	fractal->color = BLUE;
	fractal->iter = 50;
	fractal->escape = 4;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
	fractal->zoom = 1;
	fractal->track_julia = 0;
	fractal->psychedelic_flag = -1;
}

void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, ft_key, fractal);
	mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, ft_mouse, fractal);
	mlx_hook(fractal->mlx_win, MotionNotify, PointerMotionMask, track, fractal);
	mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask, xw, fractal);
}

void	ft_fractal_init(t_fractal *fractal)
{
	fractal->mlx_con = mlx_init();
	if (!fractal->mlx_con)
		ft_malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH, HEIGHT,
			fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		ft_malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_con, WIDTH, HEIGHT);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		ft_malloc_error();
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img,
			&fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
}
