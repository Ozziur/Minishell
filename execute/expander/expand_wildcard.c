/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_wildcard.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 17:23:00 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/30 17:17:15 by ccantale         ###   ########.fr       */
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
		return (ft_strdup(path));
	}
	dir_content = get_dir_content(get_prefix(path, e_true));
	if (dir_content)
		return (match(path, dir_content));
	else
		return (ft_strdup(""));
}

char	*get_prefix(char *path, t_bool allocate)
{
	int	i;

	i = 0;
	while (path[i] != '*')
		++i;
	while (i > 0 && path[i] != '/')
		--i;
	if (allocate == e_true)
	{
		if (i == 0)
			return (ft_strdup("."));
		else
			return (ft_strcpy(NULL, path, i + 1));
	}
	else
	{
		if (path[i] == '/')
			++i;
		return (path + i);
	}
}

char	*match(char *path, char *dir_content)
{
	int		i;
	char	*to_expand;
	char	*match;
	char	*expanded;

	expanded = ft_strdup("");
	to_expand = get_prefix(path, e_false);
	i = 0;
	while (dir_content[i])
	{
		match = find_match(dir_content, to_expand, &i);
		if (match)
			match = join_till_space(get_prefix(path, e_true), match,
					e_true, e_false);
		expanded = ft_strjoin(ft_strjoin(expanded, " ", e_true, e_false),
				match, e_true, e_true);
	}
	ft_free(dir_content);
	if (expanded[0] == ' ' && expanded[1] == '\0')
	{
		ft_free(expanded);
		return (ft_strdup(path));
	}
	return (trim_first_last_char(expanded, path));
}

char	*find_match(char *dir_content, char *to_expand, int *i)
{
	int	j;

	j = 0;
	if (to_expand[0] == '*')
		++j;
	while (dir_content[*i])
	{
		if ((dir_content[*i] == to_expand[j]
				&& wild_strcmp(dir_content + *i, to_expand, *i) == e_true)
			|| (dir_content[*i] != ' ' && to_expand[0] == '*'
				&& to_expand[1] == 0))
		{
			j = *i;
			while (dir_content[*i] && dir_content[*i] != ' ')
				*i += 1;
			while (j >= 0 && dir_content[j] != ' ')
				--j;
			return (dir_content + j + 1);
		}
		*i += 1;
	}
	return (NULL);
}
