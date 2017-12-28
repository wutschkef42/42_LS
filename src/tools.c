
#include "libft.h"

int	ft_strcmpc(const char *s1, const char *s2)
{
	while (*s1 && ft_tolower(*s1) == ft_tolower(*s2))
	{
		s1++;
		s2++;        
	}
	return ((unsigned char)ft_tolower(*s1) - (unsigned char)ft_tolower(*s2));
}

size_t	ft_numlen(unsigned long n)
{
	int	len;

	len = 0;
	while (++len && (n = n / 10));
	return (len);
}


char	*ft_strfjoin(char const *s1, char const *s2)
{
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (!str)
		return (NULL);
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free((void*)s1);
	return (str);
}