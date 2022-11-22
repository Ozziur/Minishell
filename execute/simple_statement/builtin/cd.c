/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:21:04 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/22 16:28:59 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	execute_cd(t_simple_cmd_node cmd)
{
	char	*path;

	path = cmd.cmd_args;
	if (bash_word_is_empty(path))
		path = ft_strdup(env_handler(BINDING_GET_VALUE, "HOME"));
	else if (path[0] == '.' && path[1] == '\0')
		return ;
}