/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:33:19 by aachbaro          #+#    #+#             */
/*   Updated: 2021/06/07 16:33:20 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	window(t_mlxdt *data)
{
	int	i;

	i = 0;
	data->m_ptr = mlx_init();
	data->m_win = mlx_new_window(data->m_ptr, 1920, 1080, "FdF");
	data->img.p_img = mlx_new_image(data->m_ptr, 1920, 1080);
	fill_points_tab(&data->map);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_hook(data->m_win, 2, (1L<<0), &key_press, &data);	
	if (data->over == 0)
		mlx_loop(data->m_ptr);
	return (0);
}
