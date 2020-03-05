#include "wolf3d.h"

void	full_column_texture_mirr(t_wolf *w, int *column, int column_height, int current_pix, int y_offset)
{
	int		y;
	t_ivec2	pix;
	int mask;
	int     l_y;
	
	pix.x = current_pix + WIN_W / 2;
	mask = (w->dem->mirr->intence * 10) << 24;
	pix.y = y_offset;
	l_y = 0;
	y = column_height;
	while (l_y < column_height)
	{
		pix.y = l_y + y_offset + WIN_H / 2 - y_offset / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			w->layers->d_labyrinth.img[pix.x + pix.y * WIN_W] = column[y] | mask;
		y--;
		l_y++;
	}
}

void	full_column_texture_mode(t_wolf *w, int *column, int column_height, int current_pix, int y_offset)
{
	int		y;
	t_ivec2	pix;
	
	pix.x = current_pix + WIN_W / 2;
	pix.y = 0;
	y = 0;
	while (y < column_height)
	{
		pix.y = y + WIN_H / 2 + y_offset - column_height / 2;
		if (pix.y >= 0 && pix.y < WIN_H)
			// w->mlx.img[pix.x + pix.y * WIN_W] = column[y];
			w->layers->d_labyrinth.img[pix.x + pix.y * WIN_W] = column[y];
		y++;
	}
}


void    draw_rect_mirror(t_drawrect dr, int w, int h, t_img *d_labyrinth, int y_offset, t_wolf *wolf)
{
	int i;
	int j;
	int color;
	int mask;
	t_ivec2 offset;

	i = 0;
	mask = (wolf->dem->mirr->intence * 10) << 24;
	offset = (t_ivec2){0, 0};
	color = dr.color;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			offset.x = dr.firstpix.x + i;
			offset.y = dr.firstpix.y + j;
			if ((offset.x + (offset.y) * WIN_W) <= (WIN_H * WIN_W) && (offset.x + (offset.y) * WIN_W) >= 0)
				d_labyrinth->img[offset.x + (offset.y) * WIN_W] = color;
			j++;
		}
		while (j < h + y_offset)
		{
			offset.x = dr.firstpix.x + i;
			offset.y = dr.firstpix.y + j;
			if ((offset.x + (offset.y) * WIN_W) <= (WIN_H * WIN_W) && (offset.x + (offset.y) * WIN_W) >= 0)
				d_labyrinth->img[offset.x + (offset.y) * WIN_W] = color | mask;
			j++;
		}
		i++;
	}
}



void	raycast_mirror(t_wolf *w, float t, t_vec2 len, int pix, int y_offset)
{
	t_raycast	r;
	int			column_height;
	t_ivec2		firstpix;
	int			wall_w;
	
	r.distance = t;
	wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
	r.wall_color = choice_color(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
	column_height = (int)(WIN_H / r.distance);
	if (y_offset > WIN_H / 2 / t)
		y_offset = WIN_H / 2 / t;
	else
		y_offset = column_height - y_offset;
	firstpix.x = (int){wall_w + pix};
	firstpix.y = (int){WIN_H / 2 - column_height / 2};
	if (r.wall_color == -1)
		return ;
	draw_rect_mirror((t_drawrect){firstpix, r.wall_color}, 1, column_height, &w->layers->d_labyrinth, y_offset, w);
}

int     find_offset(t_raycast r, t_wolf *w)
{
	float   z;
	float   angle;
	int     y;
	
	angle =  w->player.look_column_angle.y;
	z = r.distance;
	y = r.len.y;
	z = z * cos(angle) * (w->dem->wave->intence) - y * sin(angle) * (w->dem->wave->intence);
	y = z * sin(angle) + r.len.x * cos(angle);
	return (y);
}

void	raycast_modes_text(t_wolf *w, t_raycast r, int pix, float column_angle)
{
	int         y_offset;
	int			column_height;
	int			*column;
	
	y_offset = find_offset(r, w);
	column_height = (int)(WIN_H / (r.distance * cos(column_angle - w->player.look_column_angle.x)));
	r.t = cardinal_points(w, r.len);
	if (!(r.t) || !(check_distance(r.len, &w->map)))
		return ;
	if (w->dem->mirr->on == TRUE)
	{
		y_offset += 30;
		if (y_offset > column_height + 10)
			y_offset = column_height + 10;
		column = (int*)malloc(sizeof(int) * y_offset);
		((column == NULL) ? exit (99) : 1);
		column = scale_column(r, column, y_offset);
		full_column_texture_mirr(w, column, y_offset, pix, column_height);
	}
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? exit (99) : 1);
	column = scale_column(r, column, column_height);
	if (w->dem->mirr->on == TRUE)
	{
		full_column_texture(w, column, column_height, pix);
		return ;
	}
	full_column_texture_mode(w, column, column_height, pix, y_offset);
}
