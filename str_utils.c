/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pajimene <pajimene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 12:58:58 by pajimene          #+#    #+#             */
/*   Updated: 2024/06/06 19:03:06 by pajimene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}

int	ft_strncmp(char *s1, char *s2, int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && i < n - 1 && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

double	ft_atod(char *str)
{
	double	nb;
	double	frac;
	int		i;
	int		sign;

	i = 0;
	sign = 1;
	nb = 0;
	frac = 0.1;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '.')
		nb = nb * 10 + (str[i++] - 48);
	i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb + (frac * (str[i++] - 48));
		frac /= 10;
	}
	return (nb * sign);
}
