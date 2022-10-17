/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:03:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 17:16:19 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../statement.h"

static void	execute_succes_path(t_tree_node *root)
{
	char	*cmd_smp_name;
	char	*cmd_full_path;
	char	*args_split;
}

void	execute_ext_simple_cmd(t_tree_node *root, int in, int out)
{
	// if (ERROR == external_handle_redirs(root->content->in_redir,
	// 		in, STDIN_FILENO, e_true)
	// 	|| ERROR == external_handle_redirs(root->content->out_redir,
	// 		out, STDOUT_FILENO, e_false))
	// {
	// 	execute_external_failure_path();
	// }
	// else
		execute_succes_path(root);
		
}