/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:53:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/16 16:03:31 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

t_bool	is_path_name(char *cmd)
{
	return (find_substr(cmd, "/") != NULL);
}

char	*get_actual_path(char *cmd, char **pathlist)
{
	int		i;
	char	*possible_path;

	if (is_path_name(cmd) == e_true
		&& access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (*pathlist)
	{
		possible_path = ft_strjoin(
				ft_strjoin(*pathlist, "/", e_false, e_false),
				cmd,
				e_true, e_false);
		if (access(possible_path, X_OK) == 0)
				return (possible_path);
		ft_free(possible_path);
		pathlist++;
	}
	return (NULL);
}

char	*get_pathname(char *cmd)
{
	char	**env_paths_split;
	char	*path;

	if (!cmd)
		return (NULL);
	env_paths_split = ft_split (
			(char *)env_handler(BINDING_GET_VALUE, "PATH"), ':'
			);
	if (!env_paths_split)
		return (NULL);
	path = get_actual_path(cmd, env_paths_split);
	ft_split_clear(env_paths_split);
	return (path);
}

char	*get_cmd_name(char *cmd)
{	//da capire meglio in funzione di cmd_expander
	char		*name;
	int			slash_idx;
	size_t		i;

	if (!cmd)
		return (NULL);
	name = NULL;
	slash_idx = -1;
	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
			slash_idx = i;
		i++;
	}
	name = ft_strcpy(
			NULL,
			cmd + (slash_idx + 1),
			ft_strlen(cmd) - (slash_idx + 1)
			);
	return (name);
}
