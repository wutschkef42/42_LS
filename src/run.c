

#include "ft_ls.h"

int	run(int ac, char **av)
{
	int		pos;
	int		options;

	pos = 0;
	options = parse_options(ac, av, &pos);
	if (pos == ac)
 		ft_ls(options, ".", 0);
	while (pos < ac)
	{
		ft_ls(options, av[pos], 0);
		pos++;
	}
	return (1);
}
