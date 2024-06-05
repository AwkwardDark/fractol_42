/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:01:42 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/05 20:01:40 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double		ft_abs(double d)
{
	if (d < 0)
		d *= -1;
	return (d);
}

t_complex	ft_sum_complex(t_complex z1, t_complex z2)
{
	t_complex	res;

	res.x = z1.x + z2.x;
	res.y = z1.y + z2.y;
	return (res);
}

t_complex	ft_square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

t_complex	ft_burning_bird(t_complex z)
{
	t_complex	res;
	
	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * ft_abs(z.y);
	return (res);
}

double	ft_scale(double number, double new_min, double new_max, double old_max)
{
	return ((new_max - new_min) * number / old_max + new_min);
}
