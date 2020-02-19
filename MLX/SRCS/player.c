/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/15 19:40:26 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/19 18:20:15 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	init_player(t_wolf *w)
{
	t_player p;

	p.pos.x = 5;
	p.pos.y = 2;
	p.look_column_angle = 0.0;
	w->player = p;
}

void	draw_player(t_wolf *w)
{
	w->player.transform.x = w->player.pos.x * RECT_W;
	w->player.transform.y = w->player.pos.y * RECT_H;
	draw_rect((t_drawrect){w->player.transform, (t_color){255, 255, 255}},
															4, 4, w->mlx);
}
