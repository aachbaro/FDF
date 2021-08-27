#include "../fdf.h"

void	get_map_size(t_mlxdt *data, char *line)
{
	int	i;

	i = 0;
	data->map.w = 0;
	data->map.h = 0;
	while (get_next_line(data->fd, &line))
	{
		data->map.w = count_nbr(line);
		data->map.h++;
		free(line);
	}
}

int	mall_tab(t_mlxdt *data)
{
	int	i;

	i = 0;
	data->map.pts = malloc(sizeof(t_point *) * data->map.h);
	if (!data->map.pts)
		return (-1);
	while (i < data->map.h)
	{
		data->map.pts[i] = malloc(sizeof(t_point) * data->map.w);
		if (!data->map.pts[i])
			return (-1);
		i++;
	}
	return (0);
}

void	fill_line(t_mlxdt *data, char *line, int index)
{
	int	i;
	int	j;
	int	reading;

	i = 0;
	j = 0;
	reading = 0;
	while (line[i])
	{
		if (!reading && (ft_isdigit(line[i]) || line[i] == '-'))
		{
			data->map.pts[index][j++].height = ft_atoi(line + i);
			reading = 1;
		}
		else if (reading && !ft_isdigit(line[i]) && line[i] != '-')
			reading = 0;
		i++;
	}
}

void	fill_tab(t_mlxdt *data, char *line)
{
	int	i;

	i = 0;
	while (get_next_line(data->fd, &line))
	{
		fill_line(data, line, i);
		free(line);
		i++;
	}
}

int	get_map(t_mlxdt *data)
{
	char	*line;

	data->fd = open(data->file, O_RDONLY);
	get_map_size(data, line);
	mall_tab(data);
	close(data->fd);
	data->fd = open(data->file, O_RDONLY);
	fill_tab(data, line);
	return (0);
}
