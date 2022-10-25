/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 16:53:50 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/25 18:33:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pid_variable(void);
static void	set_env(char const **envp);
//////////

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
	set_pid_variable();
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
		
static void	set_pid_variable(void)
{
	t_pid	pid;
	int		pid_val_pipe[2];
	int		shell_exit_valiue;

	pipe(pid_val_pipe);
	pid = fork();
	if (pid == 0)
	{
		close(pid_val_pipe[1]);
		read(pid_val_pipe[0], &g_env.pid, sizeof(t_pid));
		close(pid_val_pipie[0]);
	}
	else
	{
		close(pid_val_pipe[0]);
		write(pid_val_pipe[1], &pid, sizeof(t_pid));
		close(pid_val_pipe[1]);
		env_handler(ENV_CLEAN, NULL);
		waitpid(pid, &shell_exit_value, 0);
		exit(WEXITSTATUS(shell_exit_value));
	}
}
