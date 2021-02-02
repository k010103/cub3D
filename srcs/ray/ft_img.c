/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 06:01:10 by junmkang          #+#    #+#             */
/*   Updated: 2021/02/03 05:09:09 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

void			ft_my_mlx_pixel_put(t_img img, int y, int x, int color)
{
	img.data[y * (img.size_l / 4) + x] = color;
}

void	ft_img(t_ray_info *ray_info, t_loop_info *info, int x)
{
	t_img *img;

	ray_info->img_x = x;
	img = ft_img_map_chk(ray_info, info);
	// 기존 함수들 생성.
	ft_wall_change(ray_info, info, 0, info->drawStart - 1);
	ft_wall_change(ray_info, info, info->drawStart, info->drawEnd);
	ft_wall_change(ray_info, info, info->drawEnd, ray_info->screen_Y - 1);
}