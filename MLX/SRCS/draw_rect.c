/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:56:28 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/04 17:00:28 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** в ф-цию draw_rect поступает х, у - коорд-ты первого пискеля из всего rect
** Внутри ф-ции мы проходимся по у, х и прибавляем каждый раз
** по единичке(+i; +j), чтобы отрисовать rectngle полностью.
** Т. о. доходим от первого пикселя в левом верхнем углу
** до правого пикселя в нижнем правом - весь rectcolumn_angle отрисован
*/

// void    draw_rect(t_drawrect dr, int w, int h, t_wolf *wolf)

//__FIXX_IMMIDEATLEY Норма!

void    draw_rect(t_drawrect dr, int w, int h, t_img *d_labyrinth)
{
	int i;
	int j;
	t_ivec2 offset;

	i = 0;
	offset = (t_ivec2){0, 0};
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			offset.x = dr.firstpix.x + i;
			offset.y = dr.firstpix.y + j;
			if ((offset.x + (offset.y) * WIN_W) <= (WIN_H * WIN_W) && (offset.x + offset.y * WIN_W) >= 0)
				d_labyrinth->img[offset.x + (offset.y) * WIN_W] = dr.color;
			j++;
		}
		i++;
	}
}
