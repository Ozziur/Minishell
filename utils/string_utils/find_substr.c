/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:35:32 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/08 17:22:03 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

char	*ft_substr(char *str, char delimiter)
{
	char	*substr;
	size_t	len_substr;

	substr = NULL;
	len_substr = 0;
	while (str[len_substr])
	{
		if (str[len_substr] == delimiter)
			break ;
		len_substr++;
	}
	if (len_substr == 0)
		return (NULL);
	substr = ft_strcpy(substr, str, len_substr);
	return (substr);
}

char	*find_substr(char *str, char *substr)
{
	int	i;
	int	j;

	if (!str)
		return (NULL);
	if (!substr)
		return (str);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && substr[j] && str[i + j] == substr[j])
			++j;
		if (substr[j] == '\0')
			return (str + i);
		else
			++i;
	}
	return (NULL);
}
