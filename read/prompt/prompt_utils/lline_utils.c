/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lline_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 18:18:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/17 18:31:10 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

static void	send_command_to_parent(char *command,
			int line_channel[2], int line_size_channel[2])
{
	size_t		final_command_len;

	if (command)
	{
		final_command_len = ft_strlen(command);
	}
	else
	{
		final_command_len = 0;
	}
	write(line_size_channel[1], &final_command_len, sizeof(final_command_len));
	write(line_channel[1], command, final_command_len * sizeof(char));
	free(command);
	close_pipe(line_channel);
	close_pipe(line_size_channel);
}

void	line_continuation_prompt(t_prompt_behav opcode, char *initial_command,
			int line_channel[2], int line_size_channel[2])
{
	static char *cmd = NULL;
	static int	line_chl[2];
	static int	line_size_chl[2];
	
	if (opcode == KILL)
	{
		send_command_to_parent(cmd, line_chl, line_size_chl);
		exit(EXIT_FAILURE);
	}
	else
	{
		cmd = NULL;
		clone_pipe(line_channel, line_chl);
		clone_pipe(line_size_channel, line_chl);
		close(line_chl);
		close(line_size_chl);
		signal(SIGINT, line_completion_prompt_sig_handler);//da creare
		read_until_complete_rec(&cmd, initial_command);// da creare
		send_command_to_parent(cmd, line_chl, line_size_chl);// da creare
		exit(EXIT_SUCCESS);
	}
}