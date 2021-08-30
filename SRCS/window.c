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
		free_everything(data);
		exit(0);
	}
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
	data->val.vect_x = 2;
	data->val.vect_y = 1;
	data->val.size = 10;
	data->m_ptr = mlx_init();
	mlx_get_screen_size(data->m_ptr, &data->screen_x, &data->screen_y);
	data->m_win = mlx_new_window(data->m_ptr, data->screen_x, data->screen_y, "FdF");
	data->img.p_img = mlx_new_image(data->m_ptr, data->screen_x, data->screen_y);
	data->img.addr = mlx_get_data_addr(data->img.p_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	mlx_hook(data->m_win, 2, (1L<<0), &key_press, &data);
	mlx_loop_hook(data->m_ptr, &render, data);	
	printf("\nBARBBOUILLE\n");
	mlx_loop(data->m_ptr);
	return (0);
}
