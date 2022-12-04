/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:03:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/03 20:05:04 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*split_strcpy(char *str, int *j)
{
	int		i;

	if (str[0] == ' ' && str[1] == ' ')
	{
		*j += 1;
		return (split_strcpy(str + 1, j));
	}
	i = 0;
	if (str[0] == '\'' || str[0] == '"')
	{
		while (i == 0 || str[i] != str[0])
			++i;
	}
	else
	{
		while (str[i] && str[i] != ' ' && str[i + 1] != ' ')
			++i;
	}
	*j += i + 1;
	return (ft_strcpy(NULL, str, i + 1));
}

int	count_chunks(char *str)
{
	int		i;

	i = 0;
	if (str[0] == '\'' || str[0] == '"')
	{
		while (i == 0 || str[i] != str[0])
			++i;
	}
	else
	{
		while (str[i] && str[i] != ' ' && str[i + 1] != ' ')
			++i;
	}
	if (str[i])
		return (1 + count_chunks(str + i + 1));
	else
		return (0);
}

char	**cc_split(char *str)
{
	int		i;
	int		j;
	int		lines;
	char	**split;

	if (!str)
		return (NULL);
	lines = 1 + count_chunks(str);
	split = ft_malloc(sizeof(char *) * (lines + 1));
	split[lines] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		split[i] = split_strcpy(&str[j], &j);
		++i;
	}
	return (split);
}
