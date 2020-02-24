/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvernius <cvernius@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 21:36:18 by cvernius          #+#    #+#             */
/*   Updated: 2020/02/21 13:13:20 by cvernius         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_WOLF3D
# define PROTOTYPES_WOLF3D
#include "structs.h"
#include "wolf3d.h"

/** *********************************** **/
/** *********************************** **/
/**         func for rendering          **/
/** *********************************** **/
/** *********************************** **/

void				render_rays(t_wolf *w);
void				render_walls(t_wolf *w);
void				raycast(t_wolf *w, float t, t_vec2 len, int pix, int y_offset);

/** *********************************** **/
/** *********************************** **/
/**            func for mlx             **/
/** *********************************** **/
/** *********************************** **/

t_mlx				init_mlx(void);
int					draw_all_hook(t_wolf *w);
void				check_hooks_loops(t_wolf *wolf);
int					key_unpress(int k, t_wolf *w);
int					key_press(int k, t_wolf *);
int					close_hook(void *param);

/** *********************************** **/
/** *********************************** **/
/**           func for player           **/
/** *********************************** **/
/** *********************************** **/

void				init_player(t_wolf *w);
t_vec2				first_empty_place(t_wolf *w);
void				draw_player(t_wolf *w);
void				move_forward(t_wolf *w);
void				move_back(t_wolf *w);
void				move_right(t_wolf *w);
void				move_left(t_wolf *w);
int					check_f(t_wolf *w);
int					check_b(t_wolf *w);
int					check_r(t_wolf *w);
int					check_l(t_wolf *w);
void				player_move(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**        primary map rendering        **/
/** *********************************** **/
/** *********************************** **/

void				draw_walls(t_wolf *w);
void				draw_background(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**               color                 **/
/** *********************************** **/
/** *********************************** **/

t_color				wall_color(t_map *map, t_vec2 len);
int					get_color(t_color color);

/** *********************************** **/
/** *********************************** **/
/**         general functions           **/
/** *********************************** **/
/** *********************************** **/

void    draw_rect(t_drawrect dr, int w, int h, t_img *d_labyrinth, int y_offset);
void				clear_wolf(t_wolf **w);

/** *********************************** **/
/** *********************************** **/
/**            validation               **/
/** *********************************** **/
/** *********************************** **/

t_map				validate(int ac, char **maps);
int					rect_w(int w);
int					rect_h(int h);

/** *********************************** **/
/** *********************************** **/
/**              textures               **/
/** *********************************** **/
/** *********************************** **/

t_texture			**init_textures(void);
void 				render_texture(t_wolf *wolf, t_texture *t, t_ivec2 offset);
int					load_texture(char *filename, t_texture *t);
void				test_text(t_wolf *w);

/** *********************************** **/
/** *********************************** **/
/**              images                 **/
/** *********************************** **/
/** *********************************** **/
void				init_all_img(t_wolf *w);
void				clear_layer(t_img *image);
void				clear_dinamic_img(t_layer *layer);
void				prepare_static_layers(t_wolf *w);
void				put_layer_mask(t_img *image, t_img *mask);
void				put_color_mask(t_img *image, int mask, int x, int y);

void				init_fractol(t_draw_fractal **f, void *mlx);
void				init_img(t_img *img, void *mlx_ptr, int bul, t_ivec2 *begin, t_ivec2 *size);


#endif