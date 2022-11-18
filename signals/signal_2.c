/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:58 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/18 11:10:58 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sig_ign(int sig)
{
	if (sig)
		;
}

void	line_completion_prompt_sig_handler(int sig)
{
	if (sig == SIGINT)
	{
		line_continuation_prompt(KILL, NULL, NULL, NULL);
	}
}

void	cmd_launcher_sig_handler(int sig)
{
	if (sig == SIGINT)
		g_env.last_executed_cmd_exit_status = 130;
	if (sig == SIGQUIT)
		g_env.last_executed_cmd_exit_status = 131;
}
