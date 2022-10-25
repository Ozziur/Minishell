/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 16:01:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/24 18:30:54 by mruizzo          ###   ########.fr       */
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
// # include "../error_handling/error_handling_module.h"
// # include "../exit/exit_module.h"

// * user defined SUBmodules //
// # include "builtin/builtin.h"
// # include "expander/expander_module.h"
# include "statement/statement.h"
// # include "statements/simple_statements/simple_statements.h"
// # include "exec_utils/exec_utils.h"

// * user defined types //
# include "execute_struct.h"
# include "../read/parser/parser_stuff.h"
# include "../colors.h"

// * global variable module //
// # include "../global.h"

#endif