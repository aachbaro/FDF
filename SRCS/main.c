/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aachbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:42:26 by aachbaro          #+#    #+#             */
/*   Updated: 2021/08/31 16:42:41 by aachbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	main(int ac, char **av)
{
	t_mlxdt	data;

	data.file = ft_strdup(av[ac - 1]);
	get_map(&data);
	printf("\nw = %d\nh = %d\n", data.map.w, data.map.h);
	window(&data);
	return (0);
}
