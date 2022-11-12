/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exe_redir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:41:18 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/12 19:02:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simple.h"

static t_status	external_redir_in_or_out(t_redirection redir, int *cur_in_out,
				t_bool input_redir_case)
{
	if (input_redir_case == e_true)
		*cur_in_out = open(redir.file_name, O_RDONLY);
	else
	{
		if (redir.append_mode == e_true)
			*cur_in_out = ft_open(redir.file_name,
				O_CREAT | O_APPEND | O_WRONLY, 0777, e_false);
		else
			*cur_in_out = ft_open(redir.file_name,
				O_CREAT | O_TRUNC | O_WRONLY, 0777, e_false);
	}
	if (*cur_in_out == -1)
		return (ERROR);
	else
		return (OK);
}

static void	external_close_pipe(int cur_in_out)
{
	close(cur_in_out);
}

t_status	external_handle_redirs(t_redirection redir, int cur_in_out,
				int std_in_out, t_bool input_redir_case)
{
	t_status	outcome;

	outcome = OK;
	if (redir.file_name)
	{
		if (cur_in_out != std_in_out)
			external_close_pipe(cur_in_out);
		outcome = external_redir_in_or_out(redir, &cur_in_out,
				input_redir_case);
	}
	if (outcome == OK)
	{
		dup_std_fd(cur_in_out, std_in_out, e_true);
	}
	return (outcome);
}