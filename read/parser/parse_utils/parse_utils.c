/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 17:30:57 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/12 17:36:03 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_utils.h"

t_token	*take_next_token(t_parser_status *p_status)
{
	t_token	*new_token;

	new_token = next_token();
	if (new_token)
	{
		p_status->last_read_token = new_token;
		p_status->last_read_tok_pos += 1;
	}
	return (new_token);
}
