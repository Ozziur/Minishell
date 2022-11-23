/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:02:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/23 16:45:30 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTIN_H
# define BUILTIN_H

# include <limits.h>

# include "../../execute.h"
# include "../../../env/env.h"
# include "../../../read/parser/parser_struct.h"
# include "../../../utils/utils.h"

void	execute_pwd(t_simple_cmd_node cmd);
void	execute_cd(t_simple_cmd_node cmd);
void	execute_echo(t_simple_cmd_node cmd);
void	execute_exit(t_simple_cmd_node cmd);
void	execute_export(void);

#endif