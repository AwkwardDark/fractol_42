/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/06 18:54:20 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->real_julia;
		c->y = fractal->im_julia;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

void	ft_pixel_iter(int x, int y, t_fractal *fractal)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	z.x = (ft_scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->x_shift;
	z.y = (ft_scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->y_shift;
	i = 0;
	ft_mandel_julia(&z, &c, fractal);
	while (i < fractal->iter)
	{
		if (!ft_strncmp(fractal->name, "bird", 4))
			z = ft_sum_complex(ft_burning_bird(z), c);
		else
			z = ft_sum_complex(ft_square_complex(z), c);
		if (z.x * z.x + z.y * z.y > fractal->escape)
		{
			color = ft_scale(i, 0, fractal->color, fractal->iter);
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
			ft_pixel_iter(x, y, fractal);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win,
		fractal->img.img, 0, 0);
}
