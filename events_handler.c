/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 17:47:28 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/04 18:42:29 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key(int keysym, t_fractal *fractal)
{
	// if (keysym == XK_Escape)
	// 	ft_close(fractal);
	if (keysym == XK_Left)
		fractal->x_shift -= 1;
	else if (keysym == XK_Right)
		fractal->x_shift += 1;
	else if (keysym == XK_Up)
		fractal->y_shift += 1;
	else if (keysym == XK_Down)
		fractal->y_shift -= 1;
	else if (keysym == 65451)
		fractal->iter_def += 10;
	else if (keysym == 65453)
		fractal->iter_def -= 10;
	ft_fractal_render(fractal);
	printf("%d\n", keysym);
	return (0);
}

// int	ft_key(int keysym, t_fractal *fractal)
// {
	
// }

// int	ft_key(int keysym, t_fractal *fractal)
// {
	
// }