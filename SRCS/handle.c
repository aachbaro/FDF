/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
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
	if (keysym == K_UP)
		data->val.up = 1;
	if (keysym == K_DOWN)
		data->val.down = 1;
	if (keysym == K_LEFT)
		data->val.left = 1;
	if (keysym == K_RIGHT)
		data->val.right = 1;
	return (0);
}

int	key_release(int keysym, t_mlxdt *data)
{
	if (keysym == K_UP)
		data->val.up = 0;
	if (keysym == K_DOWN)
		data->val.down = 0;
	if (keysym == K_LEFT)
		data->val.left = 0;
	if (keysym == K_RIGHT)
		data->val.right = 0;
	return (0);
}

void	move(t_mlxdt *data)
{
	if (data->val.up)
		data->val.init_y += 20;
	if (data->val.down)
		data->val.init_y -= 20;
	if (data->val.left)
		data->val.init_x += 20;
	if (data->val.right)
		data->val.init_x -= 20;
	else
		data->val.color++;

}
