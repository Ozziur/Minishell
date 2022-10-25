/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_substr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:35:32 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/24 17:44:49 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

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
			return (str[i]);
		else
			++i;
	}
	return (NULL);
}
