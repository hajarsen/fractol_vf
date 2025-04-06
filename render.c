/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:31:57 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:31:59 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_my_pixel_put(int x, int y, t_image *image, int color)
{
	int	offset;

	offset = (y * image->line_lenght) + (x * (image->bits_per_pixel / 8));
	*(unsigned int *)(image->pixels_ptr + offset) = color;
}
	
static void	julia_or_mandelbrot(t_complex_nbr *z, t_complex_nbr *c, t_fractal *fractal)
{	
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		c->x = fractal->julia_x;
		c->y = fractal->julia_y;
	}
	else
	{
		c->x = z->x;
		c->y = z->y;
	}
}

static int interpolate_color(double t, int color1, int color2)
{
    int r = (int)((1 - t) * ((color1 >> 16) & 0xFF) + t * ((color2 >> 16) & 0xFF));
    int g = (int)((1 - t) * ((color1 >> 8) & 0xFF) + t * ((color2 >> 8) & 0xFF));
    int b = (int)((1 - t) * (color1 & 0xFF) + t * (color2 & 0xFF));
    return (r << 16) | (g << 8) | b;
}

static void	handle_pixel(int x, int y, t_fractal *fractal)
{
  int			index;
	int			color;
	t_complex_nbr	z;
	t_complex_nbr	c;

	index = 0;
	z.x = (lin_inter(x, -2, +2, 0, WIDTH) * fractal->zoom) + fractal->shift_x;
	z.y = (lin_inter(y, +2, -2, 0, HEIGHT) * fractal->zoom) + fractal->shift_y;
	julia_or_mandelbrot(&z, &c, fractal);
 	while (index < fractal->iterations_value)
    	{
        	z = sum_complex_nbr(square_complex_nbr(z), c);
        	if ((z.x * z.x) + (z.y * z.y) > fractal->escape_value)
      		{
            		double t = (double)index / fractal->iterations_value;
            		if (t < 0.33)
                		color = interpolate_color(t / 0.33, COLOR1, COLOR2);
            		else if (t < 0.66)
                		color = interpolate_color((t - 0.33) / 0.33, COLOR2, COLOR3);
            		else
                		color = interpolate_color((t - 0.66) / 0.34, COLOR3, COLOR4);
            		ft_my_pixel_put(x, y, &fractal->image, color);
            		return;
        	}
        	index++;
    	}
	ft_my_pixel_put(x, y, &fractal->image, COLOR4);
}

void	fractal_render(t_fractal *fractal)
{
	int	x;
	int	y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			handle_pixel(x, y, fractal);
      x++;
		}
    y++;
	}
	mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->image.image_ptr, 0, 0);	
}
