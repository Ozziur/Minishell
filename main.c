/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:53:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 17:16:16 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void debug(t_tree_node	*x)
{

	printf("\n///////////\n%s %s \n///////////\n ", x->content->simple_cmd.cmd_name, x->content->simple_cmd.cmd_args);
}

int	main(int argc, char const **argv, char const **envp)
{
	t_tree_node	*parse_tree;

	if (!argc && !argv && !envp)
		return (0);
	set_env(envp);
	sig_handling_set(SIG_INITIAL);
	while (e_true)
	{
		parse_tree = shell_read();
		execute(parse_tree);
										
		// debug(parse_tree);
		// debug(parse_tree);									
									//	printf("\n///////////\n%s %s \n///////////\n ", temp->content->simple_cmd.cmd_name, temp->content->simple_cmd.cmd_args);

	//	execute(parse_tree);
	}
	return (EXIT_SUCCESS);
}

static void	set_env(char const **envp)
{
	size_t	cur_shell_lvl;
	char	*new_shell_lvl_string;

	env_handler(ENV_INITIALIZE, (char **)envp);
	//set_pid_variable();
	{
		cur_shell_lvl = ft_atoi(env_handler(BINING_GET_VALUE, "SHLVL"));
		new_shell_lvl_string = ft_itoa(cur_shell_lvl + 1);
		env_handler(BINDING_UPDATE,
				get_new_binding("SHLVL", new_shell_lvl_string, e_false));
		free(new_shell_lvl_string);

	}
	if (env_handler(BINDING_GET_VALLUE, "minishell_first_call_set") == NULL)
	{
		env_handler(BINDING_UPDATE,
				get_new_binding("minishell_fiirst_call_set", "1", e_false));
		g_env.stdout_clone = dup(STDOUT_FILENO);
	}
	g_env.last_executed_cmd_exit_status = EXIT_SUCCESS;
}
		
