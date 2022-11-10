/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:50:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:23:24 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

void	*ft_split_clear(char **split)
{
	size_t	i;
	char	**backup;

	if (!split)
		return (NULL);
	backup = split;
	i = 0;
	while (split[i])
	{
		ft_free(split[i]);
		i++;
	}
	ft_free(backup);
	return (NULL);
}
