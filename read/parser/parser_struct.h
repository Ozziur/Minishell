/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 21:23:12 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/07 00:36:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include <unistd.h>

//* declarations
typedef struct s_tree_node				t_tree_node;
typedef struct s_parser_status			t_parser_status;

//* creation
struct s_tree_node
{
	struct s_tree_node	*left;

	struct s_tree_node	*right;
};

struct s_parser_status
{
	t_status	status;
//	t_groupings	open;
	t_token		*last_read_token;
	int			last_read_tok_pos;
};

#endif
