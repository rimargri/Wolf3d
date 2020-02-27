//
// Created by Hugor Chau on 27/02/2020.
//

#include "wolf3d.h"
#define PUT_SECOND 10

void    draw_rect_mode(t_drawrect dr, int w, int h, t_img *d_labyrinth, int y_offset)
{
    int i;
    int j;
    int color;
    t_ivec2 offset;

    i = 0;
    offset = (t_ivec2){0, 0};
    color = get_color(dr.color);
    while (i < w)
    {
        j = 0;
        while (j < h)
        {
            offset.x = dr.firstpix.x + i;
            offset.y = dr.firstpix.y + j + y_offset;
            if ((offset.x + (offset.y + y_offset) * WIN_W) <= (WIN_H * WIN_W) && (offset.x + (offset.y + y_offset) * WIN_W) >= 0)
                d_labyrinth->img[offset.x + (offset.y + y_offset) * WIN_W] = color;
            j++;
        }
        i++;
    }
}

void	find_distance_mode(t_wolf *w, int pix, int w_w, int delim)
{
    float	t;
    t_vec2	column_angle;
    t_vec2	len;
    float	z = 0;
    float	y_offset;
    int		x;

    t = 0.0f;
    column_angle.x = (w->player.look_column_angle.x + w->layers->draw_shift) - FOV / delim + FOV * pix /
                                                                                             (float)(w_w);
    x = 0;
    column_angle.y = w->player.look_column_angle.y;
    while (t < 100)
    {
        z = t;
        len.x = cos(column_angle.x) * z + w->player.pos.x;
        len.y = sin(column_angle.x) * z + w->player.pos.y;
        if (len.x >= w->map.w || len.y > w->map.h || len.x < 0 || len.y < 0)
            break ;
        if (w->map.line[(int)len.x + (int)len.y * w->map.w] != ' ')
            break;
        t += 0.01;
    }
    z = z * cos(column_angle.y) * (w->dem->wave->intence) - len.y * sin(column_angle.y) * (w->dem->wave->intence);
    y_offset = z * sin(column_angle.y) + len.x * cos(column_angle.y);
    if (w->dem->norm->on == FALSE && w->dem->mirr->on != PUT_SECOND)
    {
        if ((w->dem->mirr->on == TRUE) && (y_offset > WIN_H / 2 / t))
            raycast_mode(w, t, len, pix, (int)(WIN_H / 2 / t));
        else
            raycast_mode(w, t, len, pix, (int)(y_offset) + (column_angle.y * 3));
    }
    else
        raycast_mode(w, t, len, pix, (int)(0));
}

void	raycast_mode(t_wolf *w, float t, t_vec2 len, int pix, int y_offset)
{
    t_raycast	r;
    int			column_height;
    t_ivec2		firstpix;
    int			wall_w;

    r.distance = t;
    wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
    r.wall_color = (t_color)wall_color(&w->map, len);
    column_height = (int)(WIN_H / r.distance);
    firstpix.x = (int){wall_w + pix};
    firstpix.y = (int){WIN_H / 2 - column_height / 2};
    if (r.wall_color.r == -1 && r.wall_color.g == -1 && r.wall_color.b == -1)
        return ;
    draw_rect_mode((t_drawrect){firstpix, r.wall_color}, 1, column_height, &w->layers->d_labyrinth, y_offset);
}

void	render_walls_mode(t_wolf *w)
{
    int	wall_w;
    int	delim;
    int	move_delim;
    int current_pix;//__FIXX_IMMIDEATLEY чтобы вместиться в норму, можно сделать t_ivec2

    current_pix = 0;
    wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
    delim = w->layers->map_view.on == TRUE ? 1 : 2;
    move_delim = w->layers->map_view.on == TRUE ? 2 : 1;
    while (current_pix < wall_w)
    {
        find_distance_mode(w, current_pix, wall_w / delim, move_delim);
        current_pix++;
    }
    if (w->dem->mirr->on != FALSE)
    {
        w->dem->mirr->on = PUT_SECOND;
        current_pix = 0;
        put_color_mask(&w->layers->d_labyrinth, 0xAA000000, WIN_W, WIN_H * 2);
        while (current_pix < wall_w)
        {
            find_distance_mode(w, current_pix, wall_w / delim, move_delim);
            current_pix++;
        }
        w->dem->mirr->on = TRUE;
    }
}
