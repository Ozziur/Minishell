/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_name_and_path.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:53:49 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/24 18:11:04 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_bool	is_path_name(char *cmd)
{
	return (find_substr(cmd, "/") != NULL);
}

char	*get_actual_path(char *cmd, char **pathlist)
{
	int		i;
	char	*possible_path;

	if (is_path_name(cmd) == e_true && access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	while (pathlist[i])
	{
		possible_path = ft_strjoin(
				ft_strjoin(pathlist[i], "/", e_false, e_false),
				cmd,
				e_true, e_false);
		if (access(possible_path, X_OK))
				return (possible_path);
		ft_free(possible_path);
		++i;
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
	free_split(env_paths_split);
	return (path);
}
