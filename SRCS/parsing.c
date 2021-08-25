#include "../fdf.h"

void	get_map_size(t_mlxdt *data, char *line)
{
	int	i;

	i = 0;
	data->map.w = 0;
	data->map.h = 0;
	printf("\n%d\n", data->fd);
	while (get_next_line(data->fd, &line))
	{
		data->map.w = count_nbr(line);
		data->map.h++;
		free(line);
	}
	close(data->fd);
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

void	fill_line(t_point **pt_line, char *line)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if ((ft_isdigit(line[i]) || line[i] == '-'))
		{
			pt_line[j]->height = ft_atoi(line + i);
			while ((ft_isdigit(line[i]) || line[i] == '-') && line[i])
				i++;
			j++;
		}
		else if (line[i])
			i++;
	}
}

void	fill_tab(t_mlxdt *data, char *line)
{
	int	i;

	i = 0;
	while (get_next_line(data->fd, &line))
	{
		printf("i = %d |", i);
		fill_line(&data->map.pts[i], line);
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
	data->fd = open(data->file, O_RDONLY);
	fill_tab(data, line);
	return (0);
}
