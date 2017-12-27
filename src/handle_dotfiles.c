

#include "libft.h"


int	not_dot_file(char *file)
{
	if (*file != '.')
		return (1);
	return (0);
}

int	not_dot_dir(char *file)
{
	if (ft_strcmp(file, ".") != 0 && ft_strcmp(file, "..") != 0)
		return (1);
	return (0);
}