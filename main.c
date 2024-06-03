/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:54:29 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/03 18:45:37 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
	{
		fractal.name = av[1];
		fractal_init(&fractal);
		// fractal_render(&fractal);
		mlx_loop(fractal.mlx_con);
	}
	// else if (ac == 4 && !ft_strncmp(av[1], "julia", 5))
	// {
	// 	ft_printf("Executing Julia");
	// }
	else
	{
		ft_putstr_fd(ERR_MSG, 2);
		exit(1);
	}
	return (0);
}