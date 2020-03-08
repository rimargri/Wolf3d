/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 18:30:30 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 18:31:27 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		open_menu_image(t_img *image, char *filename,
							int size_x, int size_y)
{
	int		bp;
	int		size_line;
	int		endian;
	int		x;
	void	*mptr;

	x = 0;
	mptr = image->mptr;
	mlx_destroy_image(image->mptr, image->iptr);
	image->mptr = mptr;
	if ((image->iptr = mlx_xpm_file_to_image(image->mptr,
					filename, &(size_x), &(size_y))) == NULL)
		return ;
	image->img = (int *)mlx_get_data_addr((char *)image->iptr,
			&bp,
			&size_line,
			&endian);
	while (x < 150)
	{
		image->img[x] = image->img[0] | 0xFF000000;
		x++;
	}
}

int			open_menu(int button, int x, int y, t_wolf *w)
{
	int		menu;

	if (w->layers->menu.on == TRUE)
		menu = FALSE;
	else
		menu = TRUE;
	if (button != 1)
		return (0);
	if (x > WIN_W - 155 && x < WIN_W - 5 && y > 5 && y < 62)
	{
		if (menu == TRUE)
		{
			w->layers->menu_button.on = FALSE;
			w->layers->menu.on = TRUE;
		}
		else
		{
			w->layers->menu_button.on = TRUE;
			w->layers->menu.on = FALSE;
		}
		w->layers->button_mask.on = FALSE;
	}
	return (0);
}
