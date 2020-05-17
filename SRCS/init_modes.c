/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_modes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hchau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 13:41:07 by hchau             #+#    #+#             */
/*   Updated: 2020/03/08 13:41:10 by hchau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_mode	*new_mode(void)
{
	t_mode		*res;

	res = (t_mode *)malloc(sizeof(t_mode));
	res->on = FALSE;
	res->intence = 0;
	return (res);
}

t_dem	*init_dem(void)
{
	t_dem	*res;

	res = (t_dem *)malloc(sizeof(t_dem));
	res->wave = new_mode();
	res->quake = new_mode();
	res->fisheye = new_mode();
	res->mirr = new_mode();
	res->norm = new_mode();
	res->fract = new_mode();
	res->norm->on = TRUE;
	res->mirr->intence = 2;
	res->music_on = FALSE;
	res->change_music = FALSE;
	res->repeat = TRUE;
	return (res);
}
