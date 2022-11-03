/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_ext.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 11:36:10 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/30 11:36:11 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "simple.h"

static void	launch_ext_cmd(t_tree_node *root,
				char *cmd_path, char *cmd_smpl_name,
				char **args_split)
{
	t_bindings	*env;

	env = env_handler(ENV_RETURN, NULL);
	if (!cmd_path)
		cmd_not_found(root, cmd_path, cmd_smpl_name, args_split);
	if (execve(cmd_path, args_split, bindings_list_to_array(env)) == -1)
		cmd_exe_fail(root, cmd_path, cmd_smpl_name, args_split);
}

static void	exe_ext_success_path(t_tree_node *root)
{
	char	*cmd_smpl_name;
	char	*cmd_path;
	char	**args_split;

	//cmd_expand(&root->content->simple_cmd);//da creare
	if (root->content->simple_cmd.cmd_name == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		//cmd_smpl_name = get_cmd_name(root->content->simple_cmd.cmd_name);//da creare
		cmd_path = get_pathname(root->content->simple_cmd.cmd_name);
		args_split = ft_split(
			ft_strjoin(
				ft_strjoin(root->content->simple_cmd.cmd_name, " ", e_false, e_false), //sostituito cmd_smpl_name con root->content->simple_cmd.cmd_name. dopo andrà ripristinato
				ft_strdup(root->content->simple_cmd.cmd_args),
				e_true, e_true),
				' ');
		launch_ext_cmd(root, cmd_path, root->content->simple_cmd.cmd_name, args_split); // same here
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
