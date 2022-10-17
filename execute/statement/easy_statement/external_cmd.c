/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   external_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:03:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 19:32:32 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../statement.h"

static void	launch_ext_cmd(t_tree_node root,
				char cmd_full_path, char *cmd_smp_name,
				char** args_split)
{
	t_bindings	*env;//da creare
	//da finire
}

static void	execute_succes_path(t_tree_node *root)
{
	char	*cmd_smp_name;
	char	*cmd_full_path;
	char	*args_split;

	cmd_expand(&root->content->simple_cmd);//da creare
	if (root->content->simple_cmd.cmd_name == NULL)
		exit(EXIT_SUCCESS);
	else
	{
		cmd_smp_name = get_cmd_name(root->content->simple_cmd.cmd_name);//da creare
		cmd_full_path = get_path_name(root->content->simple_cmd, cmd_smp_name);//da creare
		args_split = ft_split( ft_strjoin(
						ft_strjoin(cmd_smp_name, " ",e_false, e_false),
						ft_strdup(root->content->simple_cmd.cmd_args),
						e_true, e_true),' ');
		launch_ext_cmd(root, cmd_full_path,cmd_smp_name, args_split);
	}
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