/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 18:58:28 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/06 19:02:08 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_mouse(int button, int x, int y, t_fractal *fractal)
{	
	(void)x;
	(void)y;
	if (button == Button4)
		fractal->zoom *= 0.9;
	else if (button == Button5)
		fractal->zoom *= 1.1;
	ft_fractal_render(fractal);
	return (0);
}

int	track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5) && (fractal->track_julia % 2))
	{
		fractal->real_julia = (ft_scale(x, -2, 2, WIDTH) * fractal->zoom)
			+ fractal->x_shift;
		fractal->im_julia = (ft_scale(y, 2, -2, HEIGHT) * fractal->zoom)
			+ fractal->y_shift;
		ft_fractal_render(fractal);
	}
	return (0);
}
