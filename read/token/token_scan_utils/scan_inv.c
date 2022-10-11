/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_inv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 15:04:38 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/10 18:16:52 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	scan_spaces(char *str, size_t offset)
{
	int	index;

	index = offset;
	while (e_true == ft_isspace(str[index]))
		index++;
	return (index);
}

size_t	scan_inv_quotes(char *str, size_t offset)
{
	int	index;

	index = offset;
	while (str[index] == "" || str[index] == '\'')
	{
		if (str[index + 1] != str[index])
			break ;
		index += 2;
	}
	return (index);
}

size_t	scan_invariants(char *str, size_t offset)
{
	size_t	new_offset;

	new_offset = scan_sapaes(str, offset);
	new_offset = scan_inv_quotes(str, new_offset);
	return (new_offset);
}
