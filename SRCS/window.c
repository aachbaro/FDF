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

int	key_press(int keysym, t_mlxdt *data)
{
	if (keysym == K_ESCAPE)
	{
		mlx_destroy_image(data->m_ptr, data->img.p_img);
		mlx_destroy_window(data->m_ptr, data->m_win);
		mlx_destroy_display(data->m_ptr);
	}
	return (0);
}

int	render(t_mlxdt *data)
{	
	return (0);
}

int	window(t_mlxdt *data)
{
	int	x;
	int	y;

	data->m_ptr = mlx_init();
	mlx_get_screen_size(data->m_ptr, &x, &y);
	data->m_win = mlx_new_window(data->m_ptr, x, y, "FdF");
	data->img.p_img = mlx_new_image(data->m_ptr, x, y);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_hook(data->m_win, 2, (1L<<0), &key_press, &data);
	mlx_loop(data->m_ptr);
	return (0);
}
