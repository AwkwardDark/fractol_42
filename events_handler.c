/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:47:28 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/05 21:26:36 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		ft_close(fractal);
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
	else if (keysym == XK_t)
		fractal->track++;
	// else if (keysym == XK_c)
	// 	fractal->color += 20;
	ft_fractal_render(fractal);
	return (0);
}
int	ft_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_con, fractal->img.img);
	mlx_destroy_window(fractal->mlx_con, fractal->mlx_win);
	mlx_destroy_display(fractal->mlx_con);
	free(fractal->mlx_con);
	exit(0);
}
int	ft_mouse(int button, int x, int y, t_fractal *fractal)
{
	fractal->x_mouse = ft_scale(x, -2 * fractal->zoom, 2 * fractal->zoom, WIDTH) + fractal->x_shift;
	fractal->y_mouse = ft_scale(y, -2 * fractal->zoom, 2 * fractal->zoom, WIDTH) + fractal->y_shift;
	if (button == Button4)
		fractal->zoom *= 0.9;
	else if (button == Button5)
		fractal->zoom *= 1.1;
	ft_fractal_render(fractal);
	return (0);
}

int	ft_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5) && (fractal->track % 2))
	{
		fractal->real_julia = (ft_scale(x, -2, 2, WIDTH) * fractal->zoom) + fractal->x_shift;
		fractal->im_julia = (ft_scale(y, 2, -2, HEIGHT) * fractal->zoom) + fractal->y_shift;
		ft_fractal_render(fractal);
	}
	return (0);
}