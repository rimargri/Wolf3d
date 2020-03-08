#include "wolf3d.h"

void	full_column_texture_mirr(t_wolf *w, int *column, int column_height, int current_pix, int y_offset)
{
	int		y;
	t_ivec2	pix;
	int mask;
	int     l_y;
	
	pix.x = w->layers->map_view.on == TRUE ? current_pix + WIN_W / 2 : current_pix;
	mask = (w->dem->mirr->intence * 5) << 24;
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
	
	pix.x = w->layers->map_view.on == TRUE ? current_pix + WIN_W / 2 : current_pix;
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
	column_height = (int)(WIN_H / (r.distance * cos(column_angle / 2 - w->player.look_column_angle.x / 2)));
	r.t = choice_drawing_texture(w, r.len);
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
		free(column);
	}
	column = (int*)malloc(sizeof(int) * column_height);
	((column == NULL) ? exit (99) : 1);
	column = scale_column(r, column, column_height);
	if (w->dem->mirr->on == TRUE)
	{
		full_column_texture(w, column, column_height, pix);
		free(column);
		return ;
	}
	full_column_texture_mode(w, column, column_height, pix, y_offset);
	free(column);
}
