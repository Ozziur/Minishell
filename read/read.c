/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 15:29:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:08:48 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static char	*next_command(void)
{
	return (
		read_command(
			ft_strjoin("minishell test : ",
			//	get_current_working_directory(),
				ft_strjoin(RESET, "\2", e_false, e_false),
				e_false, e_true)));     // se allochiamo bisogna riportarlo a e_true, e_true
}

t_tree_node	*shell_read(void)
{
	char	*command;

	command = next_command();
	printf("\n%s\n", command);
	// if (command_is_empty())
	// {
	// 	//ft_free
	// 	return (NULL);
	// }
	// else
	// {
	// 	lunch_tokenizer(command);
	// 	free(command);
	// 	return (parse());
	// // }
}
