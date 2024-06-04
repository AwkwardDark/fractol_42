/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/04 18:42:50 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_data_init(t_fractal *fractal)
{
	fractal->iter_def = 50;
	fractal->escape = 4;
	fractal->x_shift = 0;
	fractal->y_shift = 0;
}

void	ft_events_init(t_fractal *fractal)
{
	mlx_hook(fractal->mlx_win, KeyPress, KeyPressMask, ft_key, fractal);
	//mlx_hook(fractal->mlx_win, ButtonPress, ButtonPressMask, ft_mouse, fractal);
	//mlx_hook(fractal->mlx_win, DestroyNotify, StructureNotifyMask, ft_close, fractal);
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

void	ft_pixel_conv(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = 0;
	z.y = 0;
	c.x = ft_scale(x, -2, 2, WIDTH) + fractal->x_shift;
	c.y = ft_scale(y, 2, -2, HEIGHT) + fractal->y_shift;
	i = 0;
	while (i < fractal->iter_def)
	{
		z = ft_sum_complex(ft_square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractal->escape)
		{
			color = ft_scale(i, BLACK, WHITE, fractal->iter_def);
			ft_mlx_pixel_put(&fractal->img, x, y, color);
			return ;
		}
		i++;
	}
	ft_mlx_pixel_put(&fractal->img, x, y, BLACK);
}

void	ft_fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			ft_pixel_conv(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
