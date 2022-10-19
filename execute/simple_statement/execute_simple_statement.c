/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_simple_statement.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:38:35 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/19 17:12:52 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	execute_simple_statement(t_tree_node *root, int in, int out);
//* end of declarations

void	fork_and_wait(t_tree_node *root, int in, int out)
{
	t_branch	pid_and_stat;

	pid_and_stat.pid = fork();
	if (pid_and_stat.pid == 0)
	{
		//signal(SIGINT)
		//signal(SIGTERM)
		execute_simple_statement(root, in, out);
	}
	else
	{
		//signal(SIGINT)
		//signal(SIGQUIT)
		waitpid(pid_and_stat.pid, pid_and_stat.exit_status, 0);
		//signal(SIGINT)
		//signal(SIGTERM)
		//signal(SIGQUIT);
		if (WIFEXITED(pid_and_stat.exit_status))
			g_env.last_executed_exit_status
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
		just_do_it(root, in, out);
	}
}

void	execute_simple_statement(t_tree_node *root, int in, int out)
{
	//if (is_builtin(root))
	//	exec_builtin
	//	else
	execute_external(root, in, out);
}
