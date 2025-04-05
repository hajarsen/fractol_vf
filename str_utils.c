/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:33:10 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:33:12 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || !s1 || !s2)
			return (0);
	while (s1[i] && s2[i] && i < n - 1)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

double str_to_double (char *s)
{
	double	int_part;
	double	fract_part;
  	int sign;
	double	power;

	int_part = 0;
	fract_part = 0;
	sign = 1;
	power = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	while (*s == '+' || *s == '-')
		if (*s++ == '-')
			sign = -sign;
	while (*s && *s != '.')
		int_part = (int_part * 10) + (*s++ - 48);
	if (*s == '.')
	  s++;
	while (*s)
	{
		power /= 10;
		fract_part = fract_part + (*s++ - 48) * power;
	}
	return ((int_part + fract_part) * sign);
}
