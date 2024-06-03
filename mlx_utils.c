/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:45:02 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/03 17:32:44 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char *dst;
	int offset;
	
	offset = (y * img->line_len + x * (img->bpp / 8));
	dst = img->pixel + offset;
	*(unsigned int *)dst = color;
}

void	malloc_error(void)
{
	perror("Malloc error");
	exit(1);
}