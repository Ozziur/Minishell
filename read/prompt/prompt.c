/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 17:14:54 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/21 16:44:31 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prompt.h"

char *read_command(char *main_prompt)
{
	char		*command;
	t_status	p_status;

	command = my_readline(main_prompt);
	if (!command)
		exit (0); //provvissorio
	//prompt_status = complete_line(&command, command);
	return (command);
}