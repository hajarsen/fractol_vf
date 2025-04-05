/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsennane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:31:20 by hsennane          #+#    #+#             */
/*   Updated: 2025/04/05 23:31:20 by hsennane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double lin_inter(double nbr, double new_min, double new_max, double old_min, double old_max)
{
  return (new_max - new_min) * ((nbr - old_min) / (old_max - old_min)) + new_min;
}

t_complex_nbr sum_complex_nbr(t_complex_nbr a, t_complex_nbr b)
{
  t_complex_nbr res;

  res.x = a.x + b.x;
  res.y = a.y + b.y;
  return res;
}

t_complex_nbr square_complex_nbr(t_complex_nbr a)
{
  t_complex_nbr res;

  res.x = (a.x * a.x) - (a.y * a.y);
  res.y = 2*a.x*a.y;
  return res;
}
