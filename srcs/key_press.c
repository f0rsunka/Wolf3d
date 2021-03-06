/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 20:02:34 by cvernius          #+#    #+#             */
/*   Updated: 2020/03/08 21:48:36 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** ********************************************************************** **
**																		  **
** key_space			-	show radar or no 							  **
**																		  **
**						*** move of player ***							  **
**																		  **
** arrow let		-		rotation player on left						  **
** arrow right		-		rotation player on right					  **
** arrow up			-		rotation player on up//need to be fixed		  **
** arrow down		-		rotation player on down//need to be fixed	  **
**																		  **
** key_w			-		move up										  **
** key_s			-		move down									  **
** key_a			-		move_left									  **
** key_d			-		move right									  **
** key_ 36			-		Enter, show map								  **
** key_space		-		jump (make it please!)						  **
**																		  **
**								*** modes ***							  **
**																		  **
** Norm_dem(key 1)	-		set default mode							  **
** Waves_dem(2)		-		set waves mode							  	  **
** Earthquake_dem(3)-		set quake mode							  	  **
** Mirror_dem(4)	-		set mirror on the floor						  **
** Fractal_dem(5)	-		set fractal on the screen					  **
** ********************************************************************** **
*/

int		dem_change(int k, t_wolf *w)
{
	if (k == EARTHQUAKE_DEM)
		change_dems(w, w->dem->quake);
	else if (k == WAVES_DEM)
		change_dems(w, w->dem->wave);
	else if (k == MIRROR_DEM)
		change_dems(w, w->dem->mirr);
	else if (k == NORM_DEM)
		change_dems(w, w->dem->norm);
	else if (k == FRACTAL_DEM)
		w->dem->fract->on = w->dem->fract->on == TRUE ? FALSE : TRUE;
	else
		return (FALSE);
	w->dem->change_music = w->dem->repeat == TRUE ? FALSE : TRUE;
	if (k != NORM_DEM)
		w->dem->norm->on = FALSE;
	return (TRUE);
}

void	map_view_change(t_wolf *w)
{
	w->layers->map_view.on = w->layers->map_view.on == TRUE ? FALSE : TRUE;
	if (w->layers->map_view.on == TRUE)
	{
		w->layers->d_player.on = TRUE;
		w->layers->draw_shift = 0.0;
	}
	else
	{
		w->layers->d_player.on = FALSE;
		w->layers->draw_shift = -0.5236;
	}
}

int		key_unpress(int k, t_wolf *w)
{
	if (k == KEY_ARROW_RIGHT)
		w->player.move.camera = 0;
	else if (k == KEY_ARROW_LEFT)
		w->player.move.camera = 0;
	else if (k == KEY_ARROW_UP)
		w->player.move.camera = 0;
	else if (k == KEY_ARROW_DOWN)
		w->player.move.camera = 0;
	else if (k == ENTER)
		map_view_change(w);
	else if (dem_change(k, w) == TRUE)
		;
	else if (k == KEY_SPACE)
	{
		w->player.move.jump_h = w->player.move.jump_h > MAX_HEIGHT ?
				MAX_HEIGHT : w->player.move.jump_h;
		w->player.move.jump = w->player.move.jump_h / 2;
	}
	else if (k == KEY_Q)
		w->dem->repeat = w->dem->repeat == TRUE ? FALSE : TRUE;
	w->player.move.left = k == KEY_A ? FALSE : w->player.move.left;
	w->player.move.right = k == KEY_D ? FALSE : w->player.move.right;
	w->player.move.forward = k == KEY_W ? FALSE : w->player.move.forward;
	w->player.move.back = k == KEY_S ? FALSE : w->player.move.back;
	return (0);
}

int		key_press(int k, t_wolf *w)
{
	(k == KEY_T ? change_textures(w) : 1);
	(k == KEY_ESC ? clear_wolf(&(w)) : 1);
	if (k == KEY_W)
		w->player.move.forward = KEY_W;
	else if (k == KEY_S)
		w->player.move.back = KEY_S;
	else if (k == KEY_D)
		w->player.move.right = KEY_D;
	else if (k == KEY_A)
		w->player.move.left = KEY_A;
	else if (k == KEY_ARROW_RIGHT)
		w->player.move.camera = KEY_ARROW_RIGHT;
	else if (k == KEY_ARROW_LEFT)
		w->player.move.camera = KEY_ARROW_LEFT;
	else if (k == KEY_ARROW_UP)
		w->player.move.camera = KEY_ARROW_UP;
	else if (k == KEY_ARROW_DOWN)
		w->player.move.camera = KEY_ARROW_DOWN;
	else if (k == KEY_R)
		w->space_was_pressed = !(w->space_was_pressed);
	else if (k == KEY_SPACE)
		w->player.move.jump = STARTED;
	return (0);
}

int		close_hook(void *param)
{
	(void)param;
	exit(0);
	return (0);
}
