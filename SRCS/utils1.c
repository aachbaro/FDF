#include "../fdf.h"

int     count_nbr(char *line)
{
int     i;
int     nbr;

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
