/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:16:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/29 17:43:04 by marvin           ###   ########.fr       */
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

char	**bindings_list_to_array(t_bindings *env);
void	execute_simple_statement(t_tree_node *root, int in, int out);
void	exe_ext_smpl_cmd(t_tree_node *root, int in, int out);


#endif
