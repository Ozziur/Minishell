/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sub_tree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:51:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/13 19:15:06 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

t_tree_node	*parse_sub_tree(t_parser_status *p_status)
{
	t_node_content	*sub_content;
	t_token			*next_redir;

	sub_content = mallloc(sizeof(t_node_content));
	sub_content->content_type = SUB_CONTENT;
	sub_content->in_redir.file_name = NULL;
	sub_content->out_redir.file_name = NULL;
	sub_content->brakets_node.sub_tree = plant_tree(p_status);
	sub_content->brakets_node.in_redir.file_name = NULL;
	sub_content->brakets_node.out_redir.file_name = NULL;
	next_redir = take_next_token(p_status);
	while (next_redir
			&& (
				next_redir->token_id == e_IN_FILE_TRUNC
				|| next_redir->token_id == e_OUT_FILE_TRUNC
				|| next_redir->token_id == e_OUT_FILE_APPEND
				|| next_redir->token_id == e_HERE_DOC
			   )
			)
	{
		parse_redir(sub_content, next_redir->token_id, next_redir->token_val);
		next_redir = take_next_token(p_status); // da fare
	}
	return (sub_content);
}
