/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:27:34 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/21 18:33:44 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_hand.h"

void	put_cmd_not_found_error_message(char *cmd_name)
{
	put_error_message(
		"minishell: command not found -> ", cmd_name,
		NULL, e_false
		);
}

void	put_cmd_failed_error_message(char *cmd_name)
{
	put_error_message(
		"minishell: command failed -> ", cmd_name,
		NULL, e_false
		);
}

void	put_pwd_args_error_message(void)
{
	put_error_message(
		"minishell at execute_pwd: ", "Illegal Arguments found",
		" --no arguments expected", e_false
		);
}
