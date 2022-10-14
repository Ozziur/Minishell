/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:53:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:07:57 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char const **argv, char const **envp)
{
	t_tree_node	*parse_tree;

	if (!argc && !argv && !envp)
		return (0);
	while (e_true)
	{
		parse_tree = shell_read();
							//			printf("\n///////////\n%s  \n///////////\n ",(char *) parse_tree->to_string);
		//execute(parse_tree);
	}
	return (EXIT_SUCCESS);
}
