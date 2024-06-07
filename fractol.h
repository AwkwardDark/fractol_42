/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 14:24:01 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/07 12:49:14 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <X11/X.h>
# include <X11/keysym.h>

# define WIDTH 1000
# define HEIGHT 1000
# define ERR_MSG "\nWrong input, you can choose between this fractals:\n\n\t\
./fractol mandelbrot\n\t./fractol julia <real> <imaginary>\n\t./fractol bird\n\n"
# define WLCM_MSG "\nWelcome to a fractal explorer!, the commands available\
 are:\n\n\t\
 -->Moving on the 2D plane with the arrows.\n\n\t\
 -->Mouse wheel to zoom in or out\n\n\t\
 -->'+' or '-' to change the resolution of the fractal.\n\n\t\
 -->'j' to move on a selection of my favourites julia fractals.\n\n\t\
 -->'t' to track the mouse position, which will change the julia fractal.\n\n\t\
 -->'c' to shift colors based on a selection.\n\n\t\
 -->'p' to test the psychedelic mode ;D.\n\n\t\
 -->'ESC' to close the window and exit the program.\n\n"

//Colors
# define WHITE 0xFFFFFFF
# define BLACK 0x0000000
# define BLUE 512
# define GREEN 6630512
# define RED 855270512
# define FUNKY_RED 1219920512
# define FUNKY_YELLOW 1279590512
# define FUNKY_ORANGE 643110512
# define FUNKY_PINK 1074060512

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
	int		color;
	int		psychedelic_flag;
	int		iter;
	double	escape;
	double	zoom;
	double	x_shift;
	double	y_shift;
	double	real_julia;
	double	im_julia;
	int		track_julia;
}				t_fractal;

typedef struct s_complex {
	double	x;
	double	y;
}				t_complex;

//Fractal Init, Rendering and Utils
void		ft_data_init(t_fractal *fractal, char *real, char *im);
void		ft_fractal_init(t_fractal *fractal);
void		ft_pixel_iter(int x, int y, t_fractal *fractal);
void		ft_fractal_render(t_fractal *fractal);
void		ft_mandel_julia(t_complex *z, t_complex *c, t_fractal *fractal);

//Events Init and Handler
void		ft_events_init(t_fractal *fractal);
int			ft_key(int keysym, t_fractal *fractal);
int			xw(t_fractal *fractal);
int			ft_mouse(int button, int x, int y, t_fractal *fractal);
int			track(int x, int y, t_fractal *fractal);
int			ft_shift_color(t_fractal *fractal);
void		ft_julia_selection(t_fractal *fractal);

//MLX Utils
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
void		ft_malloc_error(void);

//Math Utils
t_complex	ft_sum_complex(t_complex z1, t_complex z2);
t_complex	ft_square_complex(t_complex z);
t_complex	ft_burning_bird(t_complex z);
double		ft_scale(double nb, double new_min, double new_max, double old_max);
double		ft_abs(double d);

//String Utils
void		ft_putstr_fd(char *s, int fd);
int			ft_strncmp(char *s1, char *s2, int n);
int			ft_strlen(char *str);
double		ft_atod(char *str);

#endif