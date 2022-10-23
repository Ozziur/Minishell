/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   just_do_it.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:13:16 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/23 18:00:44 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

static void	cmon_man_its_just_a_cmd(t_tree_node *root,
				char *cmd_name, char *cmd_path, char **args_split)
{
	t_bindings	*env;

	env = env_handler(ENV_RETURN, NULL);
	//if (!cmd_path)
	//	cmd_not_founf_failure()
	//if (-1 == 
	execve(cmd_path, args_split, bindings_list_to_array(env));
	//)
	//		cmd_exec_failure();
}

void	plz_do_it(t_tree_node *root)
{
	//* qua si espandono le variabili col dollaro *//

	//char	*cmd_name;
	//char	*cmd_path;
	//char	**args_split;
	//
	//cmd_is_variable(root->content->simple_cmd);
	//if (NULL == root->content->simple_cmd.cmd_name)
	//	exit(EXIT_SUCCESS);
	//else
	//{
	//	cmd_name = get_cmd_name()
	//	cmd_path = get_cmd_path()
	//	args_split = ft_split(
	//			ft_strjoin(
	//				cmd_name, " ", e_false, e_false),
	//				ft_strdup(root->content->simple_cmd.cmd_args),
	//				e_true, e_true
	//				),
	//			' ');
	
	//* però sticazzi, intanto facciamo 'sto benedetto echo ciao
	cmon_man_its_just_a_cmd(root, root->content->simple_cmd_cmd_name, cmd_path, args_split);	//get_cmd_path() va fatta pure quella
}

void	just_do_it(t_tree_node *root, int in, int out)
{
	//ma bisogna veramente ricontrollare che sia un simple_cmd? Secondo me no.
	//if (ERROR redirs)
	//	execute_external_failure_path();
	//else
	plz_do_it(root);
}
