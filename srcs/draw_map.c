/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 15:40:58 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:46:14 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		rect_w(int w)
{
	return ((WIN_W / 2 / w));
}

int		rect_h(int h)
{
	return (WIN_H / h);
}

void	draw_background_on_map(t_wolf *w)
{
	int x;
	int y;
	int color;

	y = 0;
	color = get_color((t_color){120, 120, 150});
	while (y < WIN_H)
	{
		x = 0;
		while (x < WIN_W / 2)
		{
			if ((x + y * WIN_W) <= (WIN_H * WIN_W) && (x + y * WIN_W) >= 0)
				w->layers->map_view.img[x + y * WIN_W] = color;
			x++;
		}
		y++;
	}
}

void	draw_walls(t_wolf *w)
{
	int			x;
	int			y;
	t_drawrect	dr;

	y = 0;
	dr = (t_drawrect){(t_ivec2){0, 0}, get_color((t_color){0, 0, 0})};
	while (y < w->map.h)
	{
		x = 0;
		while (x < w->map.w)
		{
			if (w->map.line[x + y * w->map.w] == ' ')
			{
				x++;
				continue;
			}
			dr.firstpix.x = x * rect_w(w->map.w);
			dr.firstpix.y = y * rect_h(w->map.h);
			dr.color = choice_color(w, w->map.line[x + y * w->map.w]);
			draw_rect(dr, rect_w(w->map.w), rect_h(w->map.h),
												&w->layers->map_view);
			x++;
		}
		y++;
	}
}
