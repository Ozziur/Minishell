/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:43:09 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/13 16:08:17 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_STRUCT_H
# define PARSER_STRUCT_H

# include <unistd.h>
# include "../token/token_struct.h"

//* declarations
typedef struct s_tree_node				t_tree_node;
typedef struct s_parser_status			t_parser_status;
typedef struct s_groupings				t_groupings;
typedef struct s_content				t_content;
typedef struct	s_braket_node			t_braket_node;

//* creation
struct s_tree_node
{
	//void		(* to_string)(t_tree_node node);
	t_tree_node	*left;
	t_content	*content;
	t_tree_node	*right;
};

struct s_groupings
{
	size_t	quotes;
	size_t	double_qquotes;
	size_t	parenthesis;
};

struct s_parser_status
{
	t_status	status;
	t_groupings	open;
	t_token		*last_read_token;
	int			last_read_tok_pos;
};

struct	s_content
{
	//t_redirection		in_redir;
	//t_redirection		out_redir;
	int					content_type;
	t_braket_node		braket_node;
	//t_simple_cmd_node	simple_cmd;
	//t_env_decl_node		env_decl;
	//t_operator_node		operator_node;
}

struct	s_braket_node
{
	//t_redirection	in_redir;
	//t_redirection	out_redir;
	t_tree_node		*subtree;
}

#endif
