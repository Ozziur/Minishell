/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_hand.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:44:30 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/21 18:34:37 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HAND_H
# define ERROR_HAND_H

// * standard libraries //
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>

// * user defined modules
//# include "../exit/exit_module.h"

// * user defined types //
# include "../types.h"
# include "error_hand_struct.h"
# include "error_hand.h"
# include "../global.h"
# include "../utils/utils.h"
# include "../read/parser/parser_struct.h"
# include "../read/token/tok_utils/tok_utils.h"
# include "../colors.h"

void	put_error(t_err_handl_opcodes error_type, int error_status,
			void *argument);
void	put_error_message(char *preamble, char *message, char *epilogue,
			t_bool free_epilogue);
void	put_args_error_message(char *arg_found);
void	put_unbalanced_input_error_message(void);
void	put_token_not_found_error_message(char *cursor);
void	put_parser_syntax_error_message(t_parser_status *parser_status);
void	put_cmd_not_found_error_message(char *cmd_name);
void	put_cmd_failed_error_message(char *cmd_name);
void	put_pwd_args_error_message(void);

#endif