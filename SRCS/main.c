#include "../fdf.h"

int	main(int ac, char **av)
{
	t_mlxdt data;

	data.file = ft_strdup(av[ac - 1]);
	get_map(&data);
	printf("\nw = %d\nh = %d\n", data.map.w, data.map.h);
	window(&data);
	return (0);
}
