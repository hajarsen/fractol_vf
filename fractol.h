/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:29:07 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:29:23 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

#include <unistd.h>
#include <stdlib.h>
#include <math.h>
#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>
#define ERROR_MESSAGE "Please enter : ./fractol mandelbort or ./fractol julia <value 1> <value 2>\n"

#define WIDTH 1200
#define HEIGHT 1200

#define BLACK       0x000000  // Red: 0, Green: 0, Blue: 0
#define WHITE       0xFFFFFF  // Red: 255, Green: 255, Blue: 255

// Psychedelic colors
#define COLOR9      0xFF1CAE  ️
#define COLOR3      0xB57EDC  
#define PSY_ELECTRIC_BLUE 0x00FFFF  
#define COLOR1   0xFF6EC7  
#define COLOR2    0x39FF14  
#define PSY_ULTRA_VIOLET  0x6A0DAD  
#define COLOR5      0xFFD700  
#define PSY_CANDY_PURPLE  0xE754E1  
#define COLOR11    0xFFB5E8  
#define COLOR4    0xA0FFE6
  

typedef struct	s_complex_nbr
{
	//		real
	double	x;
	//		i
	double	y;
}				t_complex_nbr;

typedef struct	s_image
{
	void	*image_ptr; 
	char	*pixels_ptr; 
  int		line_lenght;
  int		bits_per_pixel;
	int		endian;
}				t_image;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_connection; 
	void	*mlx_window; 
	t_image	image;
	double	escape_value; 
	int	iterations_value; 
	double	zoom;
	double	shift_x;
	double	shift_y;
  	double	julia_x;
	double	julia_y;
}				t_fractal;

double	lin_inter(double nbr, double new_min, double new_max, double old_min, double old_max);
t_complex_nbr sum_complex_nbr(t_complex_nbr a, t_complex_nbr b);
t_complex_nbr	square_complex_nbr(t_complex_nbr a);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_putstr_fd(char *s, int fd);
double str_to_double (char *s);
void	fractal_init(t_fractal *fractal);
int	mouse_handler(int button, int x, int y, t_fractal *fractal);
int	key_handler(int keysym, t_fractal *fractal);
int	close_handler(t_fractal *fractal);
int	julia_track(int x, int y, t_fractal *fractal);
void	fractal_render(t_fractal *fractal);



#endif
