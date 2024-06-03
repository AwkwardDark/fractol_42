/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:36:50 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/03 18:58:26 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// void	data_init(t_fractal *fractal)
// {
// 	fractal->max_iter = 100;
// 	fractal->escape = 2;
// }

void	fractal_init(t_fractal *fractal)
{
	fractal->mlx_con = mlx_init();
	if (!fractal->mlx_con)
		malloc_error();
	fractal->mlx_win = mlx_new_window(fractal->mlx_con, WIDTH, HEIGHT, fractal->name);
	if (!fractal->mlx_win)
	{
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		malloc_error();
	}
	fractal->img.img = mlx_new_image(fractal->mlx_con, WIDTH, HEIGHT);
	if (!fractal->img.img)
	{
		mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
		mlx_destroy_display(fractal->mlx_con);
		free(fractal->mlx_con);
		malloc_error();
	}
	fractal->img.pixel = mlx_get_data_addr(fractal->img.img, &fractal->img.bpp, &fractal->img.line_len, &fractal->img.endian);
	// events_init();
	// data_init(fractal);
}

// void	pixel_conv(int x, int y, t_fractal *fractal)
// {
// 	t_complex	z;
// 	t_complex	c;
// 	int			i;
// 	int			color;

// 	z.x = 0.0;
// 	z.y = 0.0;
// 	c.x = scale(x, -2, 2, WIDTH);
// 	c.x = scale(y, -2, 2, HEIGHT);
// 	i = 0;
// 	while (i < fractal->max_iter)
// 	{
// 		z = sum_complex(square_complex(z), c);
// 		if (z.x * z.x + z.y * z.y > fractal->escape)
// 		{
// 			color = scale(i, BLACK, WHITE, fractal->max_iter);
// 			my_mlx_pixel_put(&fractal->img, x, y, color);
// 			return ;
// 		}
// 		i++;
// 	}
// 	my_mlx_pixel_put(&fractal->img, x, y, TURQUOISE);
// }

// void	fractal_render(t_fractal *fractal)
// {
// 	int	x;
// 	int	y;

// 	x = 0;
// 	while (x < WIDTH)
// 	{
// 		y = 0;
// 		while (y < HEIGHT)
// 		{
// 			pixel_conv(x, y, fractal);
// 		}
// 	}
// 	mlx_put_image_to_window(fractal->mlx_con, fractal->mlx_win, fractal->img.img, 0, 0);
// }