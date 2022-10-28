/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:16:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/28 15:43:31 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMPLE_H
# define SIMPLE_H

# include <stdlib.h>

# include "../execute_struct.h"
# include "../../env/env.h"
# include "../../read/parser/parser_struct.h"
# include "../../signals/signals.h"

char	**bindings_list_to_array(t_bindings *env);
void	execute_simple_statement(t_tree_node *root, int in, int out);
void	exe_ext_smpl_cmd(t_tree_node *root, int in, int out);


#endif
