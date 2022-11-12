/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_statement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:38:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/12 20:13:50 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	execute_simple_statement(t_tree_node *root, int in, int out);
//* end of declarations

static void	execute_builtin(t_tree_node *root, int in, int out)
{
	// da creare
}

static void	exe_cmd_and_exit(t_tree_node *root, int in, int out)
{
	if (root->content->content_type == SIMPL_CMD)
		exe_ext_smpl_cmd(root, in, out);
}

static void	fork_and_wait(t_tree_node *root, int in, int out)
{
	t_branch	pid_and_stat;

	pid_and_stat.pid = fork();
	signal(SIGQUIT, sig_ign);
	if (pid_and_stat.pid == 0)
	{
		signal(SIGINT, sig_ign);
		signal(SIGTERM, sig_ign);
		execute_simple_statement(root, in, out);
	}
	else
	{
		signal(SIGINT, cmd_launcher_sig_handler);
		signal(SIGQUIT, cmd_launcher_sig_handler);
		waitpid(pid_and_stat.pid, &pid_and_stat.exit_status, 0);
		signal(SIGINT, sig_handler);
		signal(SIGTERM, sig_handler);
		signal(SIGQUIT, SIG_IGN);
		if (WIFEXITED(pid_and_stat.exit_status))
			g_env.last_executed_cmd_exit_status
				= WEXITSTATUS(pid_and_stat.exit_status);
	}
}

void	execute_external(t_tree_node *root, int in, int out)
{
	static int	parental_control;

	parental_control = (parental_control + 1) % 2;
	if (parental_control)
	{
		fork_and_wait(root, in, out);
		parental_control = 0;
	}
	else
	{
		exe_cmd_and_exit(root, in, out);
	}
}

void	execute_simple_statement(t_tree_node *root, int in, int out)
{
	if (is_builtin(root))
		exec_builtin(root, in, out);
	else
		execute_external(root, in, out);
}
