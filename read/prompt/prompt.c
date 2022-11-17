/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:14:54 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/09 17:06:53 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

static t_status read_completed_line(char **cmd,
					pid_t line_cont_prmp_pid,
					int line_channel[], int line_size_channel[])
{
	t_status	outcome;
	char		*completed;
	size_t		completion_len;
	int			line_completion_prompt_exit_status;

	close(line_channel[1]);
	close(line_size_channel[1]);
	waitpid(line_cont_prmp_pid,&line_completion_prompt_exit_status, 0);
	if (!WIFEXITED(line_completion_prompt_exit_status)
		|| WEXITSTATUS(line_completion_prompt_exit_status))
		outcome = ERROR;
	else
		outcome = OK;
	read(line_size_channel[0], &completion_len, sizeof(completion_len));
	if (completion_len)
	{
		completed = (char *) malloc((completion_len + 1) * sizeof(char));
		read(line_channel[0], completed, completion_len * sizeof(char));
		completed[completion_len] = '\0';
		ft_str_replace(cmd, completed);
		free(completed);
	}
	return (outcome);
}

static t_status complete_line(char **cmd_reference, char *cmd)
{
	t_status	outcome;
	pid_t		line_cont_prmp_pid;
	int			line_channel[2];
	int			line_size_channel[2];

	pipe(line_channel);
	pipe(line_size_channel);
	line_cont_prmp_pid = fork();
	if(!line_cont_prmp_pid)
		line_continuation_prompt(COMPLETE_LINE, cmd, line_channel, line_size_channel);//da creare
	else
	{
		signal(SIGINT, sig_ign);
		outcome = read_completed_line(cmd_reference,line_cont_prmp_pid, line_channel, line_size_channel);
		signal(SIGINT, sig_handler);
	}
	close_pipe(line_channel);
	close_pipe(line_size_channel);
	return(outcome);
}

char	*read_command(char *main_prompt)
{
	char		*cmd;
	t_status	prompt_status;

	prompt_status = OK;
	cmd = my_readline(main_prompt);
	if (!cmd)
		exit_shell(g_env.last_executed_cmd_exit_status);
	prompt_status = complete_line(&cmd, cmd);
	my_add_history(cmd);
	if (prompt_status == ERROR)
	{
		g_env.last_executed_cmd_exit_status = EXIT_FAILURE;
		free(cmd);
		cmd = NULL;
	}
	free(main_prompt);
	return (cmd);
}
