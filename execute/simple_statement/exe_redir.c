/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:18 by mruizzo           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/11/16 19:38:08 by mruizzo          ###   ########.fr       */
=======
/*   Updated: 2022/11/17 03:01:00 by mruizzo          ###   ########.fr       */
>>>>>>> d409bb90ff117b89b93fb45ec12b343467f393af
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

static t_status	external_redir_in_or_out(t_redirection redir, int *cur_in_out,
				t_bool input_redir_case)
{
	if (input_redir_case == e_true)
		*cur_in_out = open(redir.file_name, O_RDONLY);
	else
	{
		if (redir.append_mode == e_true)
			*cur_in_out = ft_open(redir.file_name,
				O_CREAT | O_APPEND | O_WRONLY, 0777, e_false);
		else
			*cur_in_out = ft_open(redir.file_name,
				O_CREAT | O_TRUNC | O_WRONLY, 0777, e_false);
	}
	if (*cur_in_out == -1)
		return (ERROR);
	else
		return (OK);
}

static void	external_close_pipe(int cur_in_out)
{
	close(cur_in_out);
}

t_status	external_handle_redirs(t_redirection redir, int cur_in_out,
				int std_in_out, t_bool input_redir_case)
{
	t_status	outcome;

	outcome = OK;
	if (redir.file_name)
	{
		if (cur_in_out != std_in_out)
			external_close_pipe(cur_in_out);
		outcome = external_redir_in_or_out(redir, &cur_in_out,
				input_redir_case);
	}
	if (outcome == OK)
		dup_std_fd(cur_in_out, std_in_out, e_true);
	return (outcome);
}

void	execute_redir_only_statement(t_tree_node *root,
				int in, int out)
{
	int	out_fd;
																
	out_fd = 0;
	if (root->content->out_redir.file_name)
	{
		if (root->content->out_redir.append_mode == e_true)
			out_fd = open(root->content->out_redir.file_name,
			O_CREAT | O_APPEND | O_WRONLY, 0777);
		else
			out_fd = open(root->content->out_redir.file_name,
			O_CREAT | O_TRUNC | O_WRONLY, 0777); 
		if (out_fd == -1)
		{
			perror("minishell at execute_redir_only_statement");
			g_env.last_executed_cmd_exit_status = EXIT_FAILURE;
		}
		else
			close(out_fd);
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
	// if (in || out)
	// 	;
}

t_status	builtin_handle_redirs(t_redirection redir, int cur_in_out,
				int std_in_out, t_bool input_redir_case)
{
	if (redir.file_name)
	{
		if (input_redir_case == e_true)
			cur_in_out = open(redir.file_name, O_RDONLY);
		else
		{
			if (redir.append_mode == e_true)
				cur_in_out = ft_open(redir.file_name,
						O_CREAT | O_APPEND | O_WRONLY, 0777, e_false);
			else
				cur_in_out = ft_open(redir.file_name,
						O_CREAT | O_TRUNC | O_WRONLY, 0777, e_false);
		}
		dup_std_fd(cur_in_out, std_in_out, e_true);
		if (-1 == cur_in_out)
			return (ERROR);
	}
	else
	{
		dup_std_fd(cur_in_out, std_in_out, e_false);
	}
	return (OK);
}
