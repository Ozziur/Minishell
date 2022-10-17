/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_statemant.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:46:04 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 17:04:22 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../statement.h"

static void	execute_cmd_and_exit(t_tree_node *root, int in, int out)
{
	if (root->content->content_type == SIMPL_CMD)
		execute_ext_simple_cmd(root, in, out);
}

static void	execute_external(t_tree_node *root, int in, int out)
{//da capire meglio
	// static int	parent_flag = 0;

	// parent_flag = (parent_flag + 1) % 2;
	// if (parent_flag)
	// {
	// 	spawn_and_wait_command(root, in, out);
	// 	parent_flag = 0;
	// }
	// else
	// {
		execute_cmd_and_exit(root, in, out);
	// }
}

void	execute_simple_statement(t_tree_node *root, int in, int out)
{
	// if (is_builtin_command(root))
	// 	execute_builtin(root, in, out);
	// else
		execute_external(root, in, out);
}