/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:23:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/25 01:32:33 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

char	*expand_wildcard(char *path)
{
	char	*dir_content;
	size_t	i;

	i = 0;
	while (path[i] != '*')
		++i;
	if (check_star_placement(path + i) == e_false)
	{
		return (NULL);
	}
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
	{
//		printf("\nQUIprefix\n");
		if (i == 0)
			return (ft_strdup("."));
		else
			return (ft_strcpy(NULL, path, i));
	}
	else
	{
		if (path[i] == '/') 
			++i;
		return (path + i);
	}
}

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

char	*get_dir_content(char *dir_path)
{
	write(1, "\nQUI\n", 5);
	DIR				*directory;
	struct dirent	*dir_struct;
	char			*dir_content;

	dir_content = NULL;
	directory = NULL;
	directory = opendir(dir_path);
	if (directory)
	{
		dir_struct = readdir(directory);
		while (dir_struct)
		{
			dir_content = ft_strjoin_a_trois(
					dir_content, " ", dir_struct->d_name,
					e_true, e_false, e_false);
			dir_struct = readdir(directory);
		}
		closedir(directory);
	}
	ft_free(dir_path);
	printf("\n%s\n", dir_content);
	return (dir_content);
}

char	*match(char *path, char *dir_content)
{
	int		i;
	char	*to_expand;
	char	*match;
	char	*expanded;

	if (!dir_content)
		return (NULL);
	to_expand = get_prefix(path, e_false);
	i = 0;
	match = find_match(dir_content, to_expand, &i);
	match = join_till_space(get_prefix(path, e_true), match, e_true, e_false);
	++i;
	while (dir_content[i] && dir_content[i] != ' ')
		++i;
	while (dir_content[i])
	{
		expanded = ft_strjoin(expanded, match, e_true, e_true);
		match = find_match(dir_content, path, &i);
		match = ft_strjoin(get_prefix(path, e_true), match, e_true, e_false);
		while (dir_content[i] && dir_content[i] != ' ')
			++i;
	}
	ft_free(dir_content);
	return (expanded);
}

char	*find_match(char *dir_content, char *path, int *i)
{
	size_t	j;
	size_t	k;

	while (dir_content[*i])
	{
		j = *i;
		k = 0;
		if (path[k] == '*')
			++k;
		while (dir_content[j++] == path[k++])
			;
		if ((path[0] != '*' && *i > 0 && dir_content[*i - 1] != ' '
					&& dir_content[*i - 1] != '/')
				|| (path[k] != '*' && dir_content[j] && dir_content[j] != ' '))
				continue ;
		if (path[k] == 0 || path[k] == '*')
		{
			while (*i >= 0 && dir_content[*i] != '/' && dir_content[*i] != ' ')
				*i -= 1;
			return (dir_content + *i + 1);
		}
		*i += 1;
	}
	return (NULL);
}

char	*join_till_space(char *s1, char *s2, t_bool free1, t_bool free2)
{
	size_t	i;
	char	*new1;
	char	*new2;

	i = 0;
	while (s1[i] && s1[i] != ' ')
		++i;
	new1 = ft_strcpy(NULL, s1, i);
	i = 0;
	while (s2[i] && s2[i] != ' ')
		++i;
	new2 = ft_strcpy(NULL, s2, i);
	if (s1 && free1 == e_true)
		ft_free(s1);
	if (s2 && free2 == e_true)
		ft_free(s2);
	return (ft_strjoin(new1, new2, e_true, e_true));
}
