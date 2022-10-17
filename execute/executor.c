/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:04 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/17 16:28:59 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execute.h"

static void	execute_in_shell(t_tree_node *root, int in, int out)
{
	if (root->content->content_type == SIMPL_CMD
		/*|| root->content->content_type == ENV_STATEMENT
		|| root->content->content_type == REDIR*/)
		execute_simple_statement(root, in, out);
	//else if pipe,and e or
		else
			(EXIT_FAILURE);
}

void execute_rec(t_tree_node *root, int in, int out)
{
	if (!root)
		return ;
		// signal(SIGUSR1, shell_executor_handler);
		// signal(SIGUSR2, shell_executor_handler);
		// if (root->content->content_type == PAREN_EXP)
		// {
		// 	execute_subshell(root, in, out);
		// }
		// else
			execute_in_shell(root, in, out);
}

void	execute(t_tree_node *parse_tree)
{
	if (parse_tree)
		execute_rec(parse_tree, STDIN_FILENO, STDOUT_FILENO);
}
