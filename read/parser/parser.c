/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:17:25 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/07 00:51:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_tree_node	*parse(void)
{
	t_tree_node		*tree;
	t_parser_status	p_status;

	parser_init(&p_status);
	tree =parse_leaf();      ///provvissorio, vedi parse_cmd_list mmarinel
}
