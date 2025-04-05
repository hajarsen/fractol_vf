/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:28:20 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:28:20 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int     main(int ac, char **av)
{
        t_fractal       fractal;

        if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 4 && !ft_strncmp(av[1], "julia", 5)))
        {
                fractal.name = av[1];
                if (!ft_strncmp(fractal.name, "julia", 5))
                {
                        fractal.julia_x = str_to_double(av[2]);
                        fractal.julia_y = str_to_double(av[3]);
                }
                fractal_init(&fractal);
                fractal_render(&fractal);
                mlx_loop(fractal.mlx_connection);
        }
        else
        {
                ft_putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
                exit(EXIT_FAILURE);
        }
}
