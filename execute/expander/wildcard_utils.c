/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:22:06 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/30 21:24:35 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

t_bool	check_star_placement(char *str)
{
	size_t	i;
	short	found_space;

	found_space = 0;
	i = 0;
	while (str[i] && str[i] != ' ')
	{
		if (str[i] == '/')
		{
			return (e_false);
		}
		++i;
	}
	return (e_true);
}

char	*remove_invisibles(char *dir_content)
{
	char	*new_content;

	new_content = dir_content;
	++new_content;
	while (*new_content == '.')
	{
		while (*new_content != ' ')
			++new_content;
		++new_content;
	}
	ft_free(dir_content);
	return (ft_strcpy(NULL, new_content, ft_strlen(new_content)));
}

char	*get_dir_content(char *dir_path)
{
	DIR				*directory;
	struct dirent	*dir_struct;
	char			*dir_content;

	dir_content = NULL;
	directory = NULL;
	directory = opendir(dir_path);
	if (!directory)
	{
		ft_free(dir_path);
		return (NULL);
	}
	dir_struct = readdir(directory);
	while (dir_struct)
	{
		dir_content = ft_strjoin(ft_strjoin(dir_content, " ", e_true, e_false),
				dir_struct->d_name, e_true, e_false);
		dir_struct = readdir(directory);
	}
	closedir(directory);
	ft_free(dir_path);
	dir_content = remove_invisibles(dir_content);
	return (dir_content);
}
