/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_err.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 17:13:26 by marvin            #+#    #+#             */
/*   Updated: 2022/10/29 17:13:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//header da cambiare
#include "../execute.h"

void	cmd_not_found(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split)
{
//		put_error(CMD_NOT_FOUND_ERROR, 127,   da creare
//		parse_tree->content->simple_cmd.cmd_name);
	ft_free(cmd_path);
	ft_free(cmd_smpl_name);
	ft_split_clear(args_split);
	exit(127);
}

void	cmd_exe_fail(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split)
{
//		put_error(CMD_FAILED_ERROR, EXIT_FAILURE, da creare
//		parse_tree->content->simple_cmd.cmd_name);
	ft_free(cmd_path);
	ft_free(cmd_smpl_name);
	ft_split_clear(args_split);
	exit(EXIT_FAILURE);
}
