/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:30:06 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:30:07 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


static void data_init(t_fractal *fractal)
{
  fractal->escape_value = 4;
  fractal->iterations_value = 42;
  fractal->shift_x = 0;
        fractal->shift_y = 0;
  fractal->zoom = 1;
}

static void     events_init(t_fractal *fractal)
{
        mlx_hook(fractal->mlx_window, KeyPress, KeyPressMask, key_handler, fractal);
        mlx_hook(fractal->mlx_window, ButtonPress, ButtonPressMask, mouse_handler, fractal);
        mlx_hook(fractal->mlx_window, DestroyNotify, StructureNotifyMask, close_handler, fractal);
        mlx_hook(fractal->mlx_window, MotionNotify, PointerMotionMask, julia_track, fractal);
}

static void error(void)
{
  ft_putstr_fd("Memory allocation failed.", STDERR_FILENO);
  exit(EXIT_FAILURE);
}

void    fractal_init(t_fractal *fractal)
{
        fractal->mlx_connection = mlx_init();
        if (!fractal->mlx_connection)
          error();
        fractal->mlx_window = mlx_new_window(fractal->mlx_connection, WIDTH, HEIGHT, fractal->name);
        if (!fractal->mlx_window)
        {
                mlx_destroy_display(fractal->mlx_connection);
                free(fractal->mlx_connection);
                error();
        }
        fractal->image.image_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
        if (!fractal->image.image_ptr)
        {
                mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
                mlx_destroy_display(fractal->mlx_connection);
                free(fractal->mlx_connection);
                error();
        }
        fractal->image.pixels_ptr = mlx_get_data_addr(fractal->image.image_ptr, &fractal->image.bits_per_pixel, &fractal->image.line_lenght, &fractal->image.endian);
        events_init(fractal);
        data_init(fractal);
}
