/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_utils_grm.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:00:51 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/07 18:26:12 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"

size_t	skip_consecutive_chars(char *string, size_t offset,
			char to_skip, int direction)
{
	while (string[offset] == to_skip
		&& e_false == (offset == 0 && direction == -1))
		offset += direction;
	return (offset);
}

size_t	bash_next_word_len(char *cmd_line, size_t offset)
{
	size_t	len_word;

	offset = skip_consecutive_chars(cmd_line, offset, ' ', 1);
	len_word = 0;
	while (cmd_line[offset + len_word])
	{
		// while (ft_is_quote(cmd_line[offset + len_word])) // da creare
		// 				len_word = skip_past_char(
		// 			command_line + offset,
		// 			len_word + 1,
		// 			command_line[offset + len_word],
		// 			+1);
	// if (command_line[offset + len_word] == '\0'
	// 		|| e_true == bash_control_character(
	// 			command_line[offset + len_word]))
	// 		break ;
	// 	len_word++;
	}
	return (len_word)
}

size_t	bash_next_string_len(char *str, size_t offset)
{
	size_t	bash_string_len;
	t_bool	repeat;
	int		new_offset;

	new_offset = offset;
	repeat = e_true;
	while (repeat)
	{
		new_offset = skip_consecutive_chars(str, new_offset, '$', 1);
		new_offset += bash_next_word_len(str, new_offset);
		if (str[new_offset] != '$')
			repeat = e_false;
	}
	bash_string_len = new_offset - offset;
	return (bash_string_len);
}
