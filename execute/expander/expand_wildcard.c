/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:23:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/24 20:46:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_wildcard(char *path)
{
	char	*dir_content;

	dir_content = get_dir_content(get_prefix(path, e_true));
	return (match(path, dir_content));
}

char	*get_prefix(char *path, t_bool allocate)
{
	size_t	i;

	i = 0;
	while (path[i] != '*')
		++i;
	while (i >= 0 && path[i] != '/')
		--i;
	if (allocate == e_true)
		return (ft_strcpy(NULL, path, i));
	else
	{
		if (path[i] == '/') 
			++i;
		return (path + i);
	}
}

char	*get_dir_content(char *dir_path)
{
	DIR				*dir;
	struct dirent	*dir_struct;
	char			*dir_content;

	dir_content = NULL;
	dir = opendir(dir_path);
	if (dir)
	{
		dir_struct = readir(dir);
		while (dir_struct)
		{
			dir_content = ft_strjoin_a_trois(
					dir_content, " ", dir_struct->d_name,
					e_true, e_false, e_false);
			dir_struct = readdir(dir);
		}
		closedir(dir);
	}
	ft_free(dir_path);
	return (dir_content);
}

char	*match(char *path, char *dir_content)
{
	size_t	i;
	char	*to_expand;
	char	*match;
	char	*expanded;

	if (!dir_content)
		return (NULL);
	to_expand = get_prefix(path, e_false);
	match = find_match(dir_content, path);
	expanded = ft_strjoin(get_prefix(path, e_true), match, e_true, e_false);
	ft_free(dir_content);
	return (expanded);
}

char	*find_match(char *dir_content, char *path)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	while (dir_content[i])
	{
		j = i;
		k = 0;
		if (to_expand[k] == '*')
			++k;
		while (dir_content[j++] == path[k++])
		{}
		if	(path[k] == 0 || path[k] == '*')
		{
			if ((path[0] != '*' && i > 0 && dir_content[i -1] != ' ')
					|| (path[k] != '*' && dir_content[j]
					&& dir_content[j] != ' ')
				continue ;
			while (i >= 0 && dir_content[i] != '/' && dir_content[i] != ' ')
				--i;
			return (dir_content + i + 1);
		}
	}
	return (NULL);
}
