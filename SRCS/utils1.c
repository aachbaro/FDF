/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:45:01 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:45:19 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	count_nbr(char *line)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (line[i])
	{
		while ((ft_isdigit(line[i]) || line[i] == '-') && line[i])
			i++;
		while (line[i] == ' ' && line[i])
			i++;
		nbr++;
	}
	if (line[i - 1] == ' ')
		nbr--;
	return (nbr);
}

void	free_everything(t_mlxdt *data)
{
	int	i;

	i = 0;
	free(data->file);
	while (i < data->map.h)
		free(data->map.pts[i++]);
	mlx_destroy_image(data->m_ptr, data->img.p_img);
	mlx_destroy_window(data->m_ptr, data->m_win);
	mlx_destroy_display(data->m_ptr);
}
