/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:48:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 17:04:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATEMENT_H
# define STATEMENT_H

# include "../execute_struct.h"
# include "../execute.h"

// * composed statements //
// void	execute_pipe_statement(t_tree_node *root, int in, int out);
// void	execute_and_statement(t_tree_node *root, int in, int out);
// void	execute_or_statement(t_tree_node *root, int in, int out);

// * simple statements //
void	execute_simple_statement(t_tree_node *root, int in, int out);
void	execute_ext_simple_cmd(t_tree_node *root, int in, int out);

#endif