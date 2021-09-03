/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:37:56 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:40:26 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	set_line_points(t_mlxdt *data, int l)
{
	int	i;

	i = 1;
	if (l != 0)
	{
		data->map.pts[l][0].x = data->map.pts[l - 1][0].x
			- data->val.vect_x * data->val.size;
		data->map.pts[l][0].y = data->map.pts[l - 1][0].y
			+ data->val.vect_y * data->val.size;
	}
	while (i < data->map.w)
	{
		data->map.pts[l][i].x = data->map.pts[l][i - 1].x
			+ data->val.vect_x * data->val.size;
		data->map.pts[l][i].y = data->map.pts[l][i - 1].y
			+ data->val.vect_y * data->val.size;
		i++;
	}
}

void	set_points(t_mlxdt *data)
{
	int	i;

	i = 0;
	data->map.pts[0][0].x = data->val.init_x;
	data->map.pts[0][0].y = data->val.init_y;
	while (i < data->map.h)
	{
		set_line_points(data, i);
		i++;
	}
}

void	draw_lines(t_mlxdt *data)
{
	int	i;
	int	j;

	j = 0;
	while (j < data->map.h)
	{
		i = 0;
		while (i < data->map.w - 1)
		{
			data->line.x1 = data->map.pts[j][i].x;
			data->line.x2 = data->map.pts[j][i + 1].x;
			data->line.y1 = data->map.pts[j][i].y
				- get_high(*data, i, j);
			data->line.y2 = data->map.pts[j][i + 1].y
				- get_high(*data, i + 1, j);
			draw_line(&data->img, &data->line, data->val.color);
			i++;
		}
		j++;
	}
}

void	draw_column(t_mlxdt *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map.w)
	{
		j = 0;
		while (j < data->map.h - 1)
		{
			data->line.x1 = data->map.pts[j][i].x;
			data->line.x2 = data->map.pts[j + 1][i].x;
			data->line.y1 = data->map.pts[j][i].y
				- get_high(*data, i, j);
			data->line.y2 = data->map.pts[j + 1][i].y
				- get_high(*data, i, j+ 1);
			draw_line(&data->img, &data->line, data->val.color);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_mlxdt *data)
{
	move(data);
	init_back_black(data);
	set_points(data);
	draw_lines(data);
	draw_column(data);
}
