/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 15:17:04 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/28 15:51:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

static void	exe_ext_success_path(t_tree_node *root)
{
	char	*cmd_smpl_name;
	char	*cmd_path;
	char	**args_split;

	cmd_expand(&root->content->simple_cmd);
	if (root->content->simple_cmd.cmd_name == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		cmd_smpl_name = get_cmd_name(root->content->simple_cmd.cmd_name);//da creare
		cmd_path = get_pathname(root->content->simple_cmd.cmd_name);//da creare
		args_split = ft_split(
			ft_strjoin(
				ft_strjoin(cmd_smpl_name, " ", e_false, e_false),
				ft_strdup(root->content->simple_cmd.cmd_args),
				e_true, e_true),
				' ');
		launch_ext_cmd(root, cmd_path, cmd_smpl_name, args_split);//da creare
	}
}

void	exe_ext_smpl_cmd(t_tree_node *root, int in, int out)
{
	// if (ERROR == external_handle_redirs(root->content->in_redir,
	// 		in, STDIN_FILENO, e_true)
	// 	|| ERROR == external_handle_redirs(root->content->out_redir,
	// 		out, STDOUT_FILENO, e_false))
	// 	exe_ext_failure_path();
	// else
		exe_ext_success_path(root);
}