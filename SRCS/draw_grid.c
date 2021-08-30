#include "../fdf.h"

void	set_line_points(t_mlxdt *data, int l)
{
	int	i;

	i = 1;
	if (l != 0)
	{
		data->map.pts[l][0].x = data->map.pts[l - 1][0].x -
			data->val.vect_x * data->val.size;
		data->map.pts[l][0].y = data->map.pts[l - 1][0].y +
			data->val.vect_y * data->val.size;
	}
	while (i < data->map.w - 1)
	{
		data->map.pts[l][i].x = data->map.pts[l][i - 1].x +
			data->val.vect_x * data->val.size;
		data->map.pts[l][i].y = data->map.pts[l][i - 1].y +
			data->val.vect_y * data->val.size;
		i++;
	}
}

void	set_points(t_mlxdt *data)
{
	int	i;

	i = 0;
	data->map.pts[0][0].x = data->screen_x / 2;
	data->map.pts[0][0].y = data->screen_y / 5;
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
			data->line.y1 = data->map.pts[j][i].y -
				data->map.pts[j][i].height;
			data->line.y2 = data->map.pts[j][i + 1].y -
				data->map.pts[j][i + 1].height;
			draw_line(data->img.p_img, &data->line, 0xFFFFFF00);
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
			data->line.y1 = data->map.pts[j][i].y -
				data->map.pts[j][i].height;
			data->line.y1 = data->map.pts[j + 1][i].y -
				data->map.pts[j + 1][i].height;
			draw_line(data->img.p_img, &data->line, 0xFFFFFF00);
			j++;
		}
		i++;
	}
}

void	draw_grid(t_mlxdt *data)
{
	set_points(data);
	draw_lines(data);
	draw_column(data);
}
