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

char	*read_command(char *main_prompt)
{
	char		*cmd;
	t_status	prompt_status;

	prompt_status = OK;
	cmd = my_readline(main_prompt);
	if (!cmd)
		exit_shell(g_env.last_executed_cmd_exit_status);
	//prompt_status = complete_line(&cmd, cmd);
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
