/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:17:25 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 15:08:32 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	parser_init(t_parser_status *p_status)
{
	p_status->last_read_tok_pos = NULL;
	p_status->status = OK;
	p_status->open.quotes = 0;
	p_status->open.double_qquotes = 0;
	p_status->open.parenthesis = 0;
	p_status->last_read_tok_pos = 0;
}

t_tree_node	*parse(void)
{
	t_tree_node		*tree;
	t_parser_status	p_status;

	parser_init(&p_status);
	tree = plant_tree(&p_status);      ///provvissorio, vedi parse_cmd_list mmarinel*/
	if (p_status.status == ERROR)
	{
		//gestione errori
		free_tree(&tree);// da creare
		tokenizer_free();
	}
	return (tree);
}
