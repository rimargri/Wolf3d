

//void    draw_rect_mirror(t_drawrect dr, int w, int h, t_img *d_labyrinth, int y_offset)
//{
//	int i;
//	int j;
//	int color;
//	int mask;
//	t_ivec2 offset;
//
//	i = 0;
//	mask = w->dem->mirr->intence << 24;
//	offset = (t_ivec2){0, 0};
//	color = dr.color;
//	while (i < w)
//	{
//		j = 0;
//		while (j < h)
//		{
//			offset.x = dr.firstpix.x + i;
//			offset.y = dr.firstpix.y + j + y_offset;
//			if ((offset.x + (offset.y + y_offset) * WIN_W) <= (WIN_H * WIN_W) && (offset.x + (offset.y + y_offset) * WIN_W) >= 0)
//				d_labyrinth->img[offset.x + (offset.y + y_offset) * WIN_W] = color;
//			j++;
//		}
//		i++;
//	}
//}
//
//
//
//void	raycast_mirror(t_wolf *w, float t, t_vec2 len, int pix, int y_offset)
//{
//	t_raycast	r;
//	int			column_height;
//	t_ivec2		firstpix;
//	int			wall_w;
//
//	if (y_offset > WIN_H / 2 / t)
//		y_offset = WIN_H / 2 / t;
//	r.distance = t;
//	wall_w = w->layers->map_view.on == TRUE ? WIN_W / 2 : WIN_W;
//	r.wall_color = choice_color(w, w->map.line[(int)len.x + (int)len.y * w->map.w]);
//	column_height = (int)(WIN_H / r.distance);
//	firstpix.x = (int){wall_w + pix};
//	firstpix.y = (int){WIN_H / 2 - column_height / 2};
//	if (r.wall_color == -1)
//		return ;
//	draw_rect_mirror((t_drawrect){firstpix, r.wall_color}, 1, column_height, &w->layers->d_labyrinth, y_offset);
//}