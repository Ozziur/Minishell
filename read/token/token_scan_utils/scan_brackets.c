/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan_brackets.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:39:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/03 18:40:20 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

t_token *scan_brackets(char *cmd_line, size_t cursor, t_token **token_list)
{
	char	*new_cursor;
	t_token *token;

	new_cursor = scan_next_bracket(cmd_line, cursor, token_list);
	while (new_cursor > cursor)
	{
		cursor = new_cursor;
		new_cursor = scan_next_bracket(cmd_line, cursor, token_list);
	}
	return (new_cursor);
}

t_token *scan_next_bracket(char *cmd_line, size_t cursor, t_token **token_list)
{
	char	*new_cursor;
	t_token	*token;
	
	new_cursor = is_space(cmd_line);
	if (*new_cursor == '(' || *new_cursor == ')')
	{
		token = malloc(sizeof(t_token));
		token->token_id = e_BRACKETS;
		if (*new_cursor == '(')
			token->token_val = "(";
		else
			token->token_val = ")";
		token_add_back(token_list, token);
	}
	else
		return (cursor);
}
