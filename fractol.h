/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:01 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/03 19:01:24 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include "mlx/mlx.h"
#include <math.h>
#include <unistd.h>
#include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
#include "libft/libft.h"

# define WIDTH 1000
# define HEIGHT 1000
# define ERR_MSG "Wrong input, you can choose between this fractals:\n\t./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n"

//Colors
# define WHITE 0xFFFFF
# define BLACK 0x00000
# define TURQUOISE 0x40E0D0

typedef struct	s_img {
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

/*MLX, hooks, IDs, ...*/
typedef struct	s_fractal {
	void	*mlx_con;
	void	*mlx_win;
	t_img	img;
	//hooks

	//IDs
	char	*name;
	int		max_iter;
	int		escape;
}				t_fractal;

/* double x; double y*/
typedef struct s_complex {
	double	x;
	double	y;
}				t_complex;

//Fractal Utils
void		data_init(t_fractal *fractal);
void		fractal_init(t_fractal *fractal);
void		pixel_conv(int x, int y, t_fractal *fractal);
void		fractal_render(t_fractal *fractal);

//MLX Utils
void		my_mlx_pixel_put(t_img *img, int x, int y, int color);
void		malloc_error(void);

//Math Utils
t_complex	sum_complex(t_complex z1, t_complex z2);
t_complex	square_complex(t_complex z);
double		scale(double number, double new_min, double new_max, double old_max);

#endif