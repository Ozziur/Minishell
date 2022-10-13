/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_leaf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:53:53 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 15:53:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tree.h"

static t_token	*leaf_get_next_token(t_parser_status *p_status)
{
	t_token	*token;

	if (p_status->status == ERROR)
		return (NULL);
	token = take_next_token(p_status);
	//gestione errori
	if (token == NULL
	 	|| is_operator_tok(token) || is_closing_paren(token))
    {
	 	set_error(&(p_status->status));
	 	return (NULL);
	 }
	return (token);
}

t_tree_node	*parse_leaf(t_parser_status *p_status) //vedi parse_atomic_expresion mmarinel
{
	t_token		*token;
	t_tree_node	*bracket;

	token = leaf_get_next_token(p_status);
	if (!token)
		return (NULL);
	//studiare questa parte
	 if (is_open_paren(token))
	 {
	 	p_status->open.parenthesis += 1;
	 	bracket = new_tree_node(
	 			NULL,
	 			parse_parenthesis_exp(p_status),
	 			NULL
	 			);
	 	return (bracket);
	 }
	 else
	return (parse_statement(token, p_status)); //da creare
}

