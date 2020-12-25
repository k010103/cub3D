/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junmkang <junmkang@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 18:57:40 by junmkang          #+#    #+#             */
/*   Updated: 2020/12/26 01:55:53 by junmkang         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef MAP_CHK_H
#	define MAP_CHK_H

#	include "../cub3d.h"

int		ft_map_chk(t_map *map);

int		ft_map_value_chk(char c, char *dir);
int		ft_map_validity(char **chk_map, int i, int j);

#	endif
