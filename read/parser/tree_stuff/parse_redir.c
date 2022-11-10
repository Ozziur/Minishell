/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 16:44:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 17:08:20 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_token	*parse_statement_redirs(t_token *token,
	t_node_content *node_content_ref, t_parser_status *p_status)
{
	node_content_ref->in_redir.file_name = NULL;
	node_content_ref->out_redir.file_name = NULL;
	while (
		token->token_id == e_IN_FILE_TRUNC
		|| token->token_id == e_HERE_DOC
		|| token->token_id == e_OUT_FILE_TRUNC
		|| token->token_id == e_OUT_FILE_APPEND
	)
	{
		parse_resir(node_content_ref, token->token_val, token->token_id);// da creare stando molto attenti
		token = take_next_token(p_status);
		if (!token)
		{
			node_content_ref->content_type = REDIR;
			break ;
		}
	}
	return (token);
}