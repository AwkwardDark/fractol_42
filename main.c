/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:54:29 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/07 12:48:01 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if ((ac == 2 && (!ft_strncmp(av[1], "mandelbrot", 10)
				|| !ft_strncmp(av[1], "bird", 4)))
		|| (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
	{
		fractal.name = av[1];
		ft_putstr_fd(WLCM_MSG, 1);
		ft_fractal_init(&fractal);
		ft_events_init(&fractal);
		ft_data_init(&fractal, av[2], av[3]);
		mlx_loop_hook(fractal.mlx_con, ft_shift_color, &fractal);
		ft_fractal_render(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	else
	{
		ft_putstr_fd(ERR_MSG, 2);
		exit(1);
	}
	return (0);
}
