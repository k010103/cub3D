/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 23:36:11 by junmkang          #+#    #+#             */
/*   Updated: 2021/01/23 02:28:02 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef RAY_H
#	define RAY_H

#	include "../cub3d.h"
#	include "ray_struct.h"
#	include "key_press.h"

int		cub3d(t_map map);
int		main_loop(t_ray_info *ray_info);
int		key_press(int key, t_ray_info *info);

// img ----------------------------------------------------

void	ft_my_mlx_pixel_put(t_img img, int y, int x, int color);
void	ft_img_change(t_ray_info *ray_info, int x, int start, int end, int color);
void	ft_img(t_ray_info *ray_info, t_loop_info *info, int x);

#	endif