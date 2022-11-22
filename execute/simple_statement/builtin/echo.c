/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:04:55 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 18:22:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

static size_t	n_flag(char *args)
{
	size_t	i;

	i = 0;
	while (args)
	{
		if (args && args[i] == '-' && args[i + 1] == 'n')
		{
			if (e_true == ft_isspace(args[i + 2]))
				i += 3;
		}
		else
			return (i);
	}
	return (i);
}

void	execute_echo(t_simple_cmd_node cmd)
{
	t_bool	print_nl;
	size_t	offset;

	offset = 0;
	offset += n_flag(cmd.cmd_args);
	if (offset == 0)
		print_nl = e_true;
	else
		print_nl = e_false;
	if (cmd.cmd_args)
		ft_printf("%s", cmd.cmd_args + offset);
	if (print_nl)
		ft_printf("\n");
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}
