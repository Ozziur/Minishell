#include "../utils.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

