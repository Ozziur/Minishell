/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_stuff.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:10:46 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/29 17:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_STUFF_H
# define EXECUTE_STUFF_H

# include "execute_struct.h"
#include "../read/parser/parser_struct.h"

void	execute(t_tree_node *parse_tree);
//*utils
char	*get_pathname(char *cmd);
char	*get_cmd_name(char *cmd);
//*errori exe
void	cmd_not_found(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split);
void	cmd_exe_fail(t_tree_node *parse_tree,
			char *cmd_path, char *cmd_smpl_name, char **args_split);

#endif