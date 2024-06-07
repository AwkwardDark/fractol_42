/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:47:28 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/06 19:00:57 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_shift_color(t_fractal *fractal)
{
	if (fractal->psychedelic_flag == 1)
	{
		fractal->color += 6630000;
		if (fractal->color == 214149051)
			fractal->color = -2146846784;
		ft_fractal_render(fractal);
	}
	return (0);
}

void	ft_color_selection(t_fractal *fractal)
{
	int			color_selection[7];
	static int	i;

	color_selection[0] = BLUE;
	color_selection[1] = GREEN;
	color_selection[2] = RED;
	color_selection[3] = FUNKY_RED;
	color_selection[4] = FUNKY_YELLOW;
	color_selection[5] = FUNKY_ORANGE;
	color_selection[6] = FUNKY_PINK;
	fractal->color = color_selection[i++];
	if (i == 7)
		i = 0;
}

void	ft_julia_selection(t_fractal *fractal)
{
	static int	j;
	double		real[6];
	double		im[6];

	real[0] = 0.285;
	im[0] = 0.01;
	real[1] = -0.835;
	im[1] = -0.232;
	real[2] = -0.8;
	im[2] = 0.156;
	real[3] = -0.7269;
	im[3] = 0.1889;
	real[4] = -0.4;
	im[4] = 0.6;
	real[5] = 0;
	im[5] = 0.8;
	fractal->real_julia = real[j];
	fractal->im_julia = im[j];
	if (j == 5)
		j = -1;
	j++;
}

int	ft_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		xw(fractal);
	if (keysym == XK_Left)
		fractal->x_shift -= 0.5 * fractal->zoom;
	else if (keysym == XK_Right)
		fractal->x_shift += 0.5 * fractal->zoom;
	else if (keysym == XK_Up)
		fractal->y_shift += 0.5 * fractal->zoom;
	else if (keysym == XK_Down)
		fractal->y_shift -= 0.5 * fractal->zoom;
	else if (keysym == 65451)
		fractal->iter += 5;
	else if (keysym == 65453)
		fractal->iter -= 5;
	else if (keysym == XK_p)
		fractal->psychedelic_flag *= -1;
	else if (keysym == XK_c)
		ft_color_selection(fractal);
	if (keysym == XK_t)
		fractal->track_julia++;
	else if (keysym == XK_j)
		ft_julia_selection(fractal);
	ft_fractal_render(fractal);
	return (0);
}

int	xw(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_con, fractal->img.img);
	mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_con);
	free(fractal->mlx_con);
	exit(0);
}
