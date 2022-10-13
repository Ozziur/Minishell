/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:55 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 16:52:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TREE_H
# define TREE_H

# include "../parser.h"

t_tree_node *plant_tree(t_parser_status *parser_status);
t_tree_node *new_tree_node(t_tree_node *left, t_node_content *content,
		t_tree_node *right);
t_tree_node	*parse_sub_tree(t_parser_status *p_status);

#endif
