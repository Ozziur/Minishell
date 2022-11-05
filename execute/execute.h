/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/09 17:54:30 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// * standard libraries //
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>

// * user defined modules //
# include "../utils/utils.h"
# include "../signals/signals.h"
# include "../read/read.h"
# include "../error_hand/error_hand.h"
// # include "../exit/exit_module.h"

// * user defined SUBmodules //
// # include "builtin/builtin.h"
// # include "expander/expander_module.h"
# include "simple_statement/simple.h"
# include "execute_stuff.h"
// # include "exec_utils/exec_utils.h"

// * user defined types //
# include "execute_struct.h"
# include "../read/parser/parser_stuff.h"
# include "../colors.h"

// * global variable module //
 # include "../global.h"

void	cmd_expand(t_simple_cmd_node *cmd);

#endif
