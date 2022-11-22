/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_builtin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:41:08 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 16:22:58 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

void	execute_cmd_builtin(t_simple_cmd_node *cmd)
{
	char	*simple_name;

	// cmd_expand(cmd);
	if (cmd->cmd_name == NULL)
		g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
	else
	{
		simple_name = get_cmd_name(cmd->cmd_name);
		if (ft_strcmp(simple_name, "pwd") == 0)
			execute_pwd(*cmd);
		if (ft_strcmp(simple_name, "cd") == 0)
			execute_cd(*cmd);
		// aggiungere le altre
		free(simple_name);
	}		
}