/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 12:23:55 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 16:42:08 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*splitcpy(char const *str, int *j, char delimiter)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i] != delimiter && str[i] != 0)
		++i;
	*j += i + 1;
	new_str = ft_malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] != delimiter && str[i] != 0)
	{
		new_str[i] = str[i];
		++i;
	}
	new_str[i] = 0;
	return (new_str);
}

int	split_count(char *str, char delimiter)
{
	int	i;
	int	lines;

	lines = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == delimiter)
			++lines;
		++i;
	}
	return (lines);
}

char	**ft_split(char const *str, char delimiter)
{
	int		i;
	int		j;
	int		lines;
	char	**split;

	if (!str)
		return (NULL);
		lines = split_count((char *)str, delimiter);
	split = ft_malloc(sizeof(char *) * (lines + 1));
	split[lines] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		split[i] = splitcpy(&str[j], &j, delimiter);
		++i;
	}
	return (split);
}

void	*ft_splitclear(char **split)
{
	size_t	i;
	char	**backup;

	if (!split)
		return (NULL);
	{
		backup = split;
		i = 0;
		while (split[i])
		{
			ft_free(split[i]);
			i++;
		}
		ft_free(backup);
	}
	return (NULL);
}
