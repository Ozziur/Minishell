/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 18:24:26 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:12:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt_utils.h"

char	*my_readline(char *prompt)
{
	char	*line;
	int		cur_stdout_bkp;

	// cur_stdout_bkp = dup(STDOUT_FILENO);
	// dup2(g_env.stdout_clone, STDOUT_FILENO);
	line = readline(prompt);
	// dup2(cur_stdout_backup, STDOUT_FILENO);
	// close(cur_stdout_backup);
	if (!line)/*    Ctrl+D   */
		return (NULL);
	else if (*line == '\0')/*          new line*/
	{
		free (line);
		return (my_readline(prompt));
	}
	else
		return (line);//linea letta (enrico?)
}
