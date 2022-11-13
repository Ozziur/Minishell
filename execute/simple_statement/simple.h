/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:35:41 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/13 16:03:00 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

# include <stdlib.h>

# include "../execute.h"
# include "../execute_struct.h"
# include "../../env/env.h"
# include "../../read/parser/parser_struct.h"
# include "../../signals/signals.h"
# include "../../types.h"

char	**bindings_list_to_array(t_bindings *env);
void	execute_simple_statement(t_tree_node *root, int in, int out);
void	exe_ext_smpl_cmd(t_tree_node *root, int in, int out);
t_status	external_handle_redirs(t_redirection redir, int cur_in_out,
				int std_in_out, t_bool input_redir_case);
void	execute_redir_only_statement(t_tree_node *root,
				int in, int out);
t_status	builtin_handle_redirs(t_redirection redir, int cur_in_out,
				int std_in_out, t_bool input_redir_case);

#endif
