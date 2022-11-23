/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_very_stupid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:18:47 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/23 15:45:43 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h" 

t_bool	redirect_char(char c)
{
	return (c == '>' || c == '<');
}

t_bool	ft_is_digit_string(char *str)
{
	size_t	offset;

	if (str == NULL)
		return (e_false);
	offset = 0;
	if (str[offset] == '+'
		|| str[offset] == '-')
		offset += 1;
	while (str[offset])
	{
		if (e_false == char_is_digit(str[offset])
			&& e_false == ft_isspace(str[offset]))
			return (e_false);
		offset += 1;
	}
	return (e_true);
}
