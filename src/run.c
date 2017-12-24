

#include "ft_ls.h"

int	run(int ac, char **av)
{
	int		pos;
	t_ls	ls;

	pos = 0;
	ls = parse(ac, av, &pos);

	if (pos == ac)
		ft_ls(ls, ".");
	while (pos < ac)
	{
		ft_ls(ls, av[pos]);
		pos++;
	}
	return (1);
}
