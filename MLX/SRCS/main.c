/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:06:10 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/13 23:42:12 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"
//
//char	*get_map(void)
//{
//	char *map;
//
//	map = (char*)malloc(sizeof(char) * 258);
//	map   = "0000222222220000"\
//			"1              0"\
//			"1      11111   0"\
//			"1     0        0"\
//			"0     0  1110000"\
//			"0     3        0"\
//			"0   10000      0"\
//			"0   0   11100  0"\
//			"0   0   0      0"\
//			"0   0   1  00000"\
//			"0       1      0"\
//			"2       1      0"\
//			"0       0      0"\
//			"2 3000000      0"\
//			"0              0"\
//			"2202222222200000";
//	return (map);
//}

t_mlx	init_mlx(void)
{
	t_mlx mlx;
	
	mlx.mptr = mlx_init();
	mlx.wptr = mlx_new_window(mlx.mptr, WIN_W, WIN_H, "WOLF3D\0");
	return (mlx);
}

int		main(int ac, char **maps)
{
	t_wolf *wolf;

	wolf = (t_wolf*)malloc(sizeof(t_wolf));
	((wolf == NULL) ? (wolf_error(MALLOC_ERROR)) : 1);
	wolf->tmap = validate(ac, maps);
	wolf->mlx = init_mlx();
//	wolf->map = get_map();
	draw_background(wolf);
	draw_walls(wolf, wolf->tmap);
//	init_player(wolf);
//	init_reycast(wolf);
//	cast_ray(wolf->r, wolf, wolf->tmap);
	mlx_hook(wolf->mlx.wptr, 17, 0, &close_hook, &wolf->mlx);
	mlx_hook(wolf->mlx.wptr, 2, 0, &key_press, &wolf->mlx);
//	 mlx_hook(wolf->mlx.wptr, 4, 0, &mouse_hook, &wolf->mlx);
//	 mlx_hook(wolf->mlx.wptr, 6, 0, &move_hook, &wolf->mlx);
//	 mlx_update_hook();
	mlx_loop(wolf->mlx.mptr);
	return (0);
}
