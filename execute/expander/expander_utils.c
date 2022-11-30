/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:06:20 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/30 22:47:19 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	is_char_to_expand(char c, t_exp_phase type)
{
	if (type == e_NORMAL || type == e_QUOTES)
		return (c == '"' || c == '\'' || c == '$');
	else if (type == e_STAR)
		return (c == '*');
	return (0);
}

t_bool	not_to_expand(char *to_expand)
{
	int	i;

	i = 0;
	while (to_expand[i])
	{
		if (to_expand[i] == '$'
			|| to_expand[i] == '\''
			|| to_expand[i] == '\"'
			|| to_expand[i] == '*')
			return (e_false);
		i++;
	}
	return (e_true);
}

t_bool	wild_strcmp(char *dir_content, char *to_expand, int prev_cursor)
{
	int	i;
	int	j;

	j = 0;
	if (to_expand[0] == '*')
		++j;
	i = 0;
	while (dir_content[i] && to_expand[j]
		&& dir_content[i] != ' '
		&& to_expand[j] != ' '
		&& to_expand[j] != '*'
		&& dir_content[i] == to_expand[j])
	{
		++i;
		++j;
	}
	if ((to_expand[0] != '*' && prev_cursor > 0 && dir_content[-1] != ' ')
		|| (to_expand[j] != '*' && dir_content[i] && dir_content[i] != ' ')
		|| (to_expand[j] && to_expand[j] != ' ' && to_expand[j] != '*'))
		return (e_false);
	else
		return (e_true);
}

char	*join_till_space(char *s1, char *s2, t_bool free1, t_bool free2)
{
	size_t	i;
	char	*new1;
	char	*new2;

	if (s1 && s1[0] == '.' && s1[1] == 0)
	{
		if (free1 == e_true)
			ft_free(s1);
		s1 = ft_strdup("");
		free1 = e_true;
	}
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

/*trimming the last char or not actually depends on the last char itself */
char	*trim_first_last_char(char *str)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		++i;
	if (i > 0 && str[i - 1] == ' ')
		new_str = ft_strcpy(NULL, str + 1, ft_strlen(str + 1) - 1);
	else
		new_str = ft_strcpy(NULL, str + 1, ft_strlen(str + 1));
	ft_free(str);
	return (new_str);
}