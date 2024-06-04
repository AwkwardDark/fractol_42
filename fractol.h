/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:01 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/04 18:24:23 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ERR_MSG "Wrong input, you can choose between this fractals:\n\t\
./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n"

//Colors
# define WHITE 0xFFFFFFF
# define BLACK 0x0000000
# define TURQUOISE 0x40E0D0
# define ROSE_FLUO 0xff00ff
# define ROSE_FONCE 0xff1493
# define VERT_FLUO 0x00ff00
# define ROUGE_FLUO 0xff0000
# define JAUNE_FLUO 0xffff00
# define CYAN_FLUO 0x00ffff
# define ORANGE_FONCE 0xff4500
# define VIOLET_FONCE 0x800080
# define ROSE_CLAIR 0xff69b4
# define VERT_CLAIR 0x00ff7f

typedef struct s_img {
	void	*img;
	char	*pixel;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_fractal {
	void	*mlx_con;
	void	*mlx_win;
	t_img	img;
	char	*name;
	int		iter_def;
	double		escape;
	double		x_shift;
	double		y_shift;
}				t_fractal;

typedef struct s_complex {
	double	x;
	double	y;
}				t_complex;

//Fractal Utils
void		ft_data_init(t_fractal *fractal);
void		ft_fractal_init(t_fractal *fractal);
void		ft_pixel_conv(int x, int y, t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);

//Events
void	ft_events_init(t_fractal *fractal);
int		ft_key(int keysym, t_fractal *fractal);


//MLX Utils
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void		ft_malloc_error(void);

//Math Utils
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
double		ft_scale(double nb, double new_min, double new_max, double old_max);

//String Utils
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strlen(char *str);

#endif