/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 16:33:19 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:47:35 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	key_press(int keysym, t_mlxdt *data)
{
	if (keysym == K_ESCAPE)
	{
		free_everything(data);
		exit(0);
	}
	else if (keysym == K_UP)
		data->val.init_y -= 10;
	else if (keysym == K_DOWN)
		data->val.init_y += 10;
	else if (keysym == K_LEFT)
		data->val.init_x -= 10;
	else if (keysym == K_RIGHT)
		data->val.init_x += 10;
	return (0);
}

int	render(t_mlxdt *data)
{
	draw_grid(data);
	mlx_put_image_to_window(data->m_ptr, data->m_win, data->img.p_img, 0, 0);
	return (0);
}

int	window(t_mlxdt *data)
{
	data->val.vect_x = 20;
	data->val.vect_y = 10;
	data->val.size = 1;
	data->m_ptr = mlx_init();
	mlx_get_screen_size(data->m_ptr, &data->screen_x, &data->screen_y);
	data->m_win = mlx_new_window(data->m_ptr, data->screen_x, data->screen_y,
			"FdF");
	data->img.p_img = mlx_new_image(data->m_ptr, data->screen_x,
			data->screen_y);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	data->val.init_x = data->screen_x / 2;
	data->val.init_y = data->screen_y / 5;
	data->img.size_x = data->screen_x;
	data->img.size_y = data->screen_y;
	mlx_hook(data->m_win, 2, (1L << 0), &key_press, data);
	mlx_loop_hook(data->m_ptr, &render, data);
	mlx_loop(data->m_ptr);
	return (0);
}
