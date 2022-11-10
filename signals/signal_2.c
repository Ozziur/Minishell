/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 18:10:58 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/10 12:30:24 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	sig_ign(int sig)
{
	if (sig)
		;
}

void	cmd_launcher_sig_handler(int sig)
{
	if (sig == SIGINT)
		g_env.last_executed_cmd_exit_status = 130;
	if (sig == SIGQUIT)
		g_env.last_executed_cmd_exit_status = 131;
}
