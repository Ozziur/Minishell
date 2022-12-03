/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cc_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 16:03:45 by ccantale          #+#    #+#             */
/*   Updated: 2022/12/03 16:03:46 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

int	in_or_out(char c, int reset)
{
	static short	in_quotes;
	static short	in_single_quotes;

	if (reset == e_true)
	{
		in_quotes = 0;
		in_single_quotes = 0;
		return (e_false);
	}
	if (c == '"' && in_quotes == 0)
			in_quotes = e_true;
	else if (c == '"' && in_quotes == e_true)
		in_quotes = e_false;
	else if (c == '\'' && in_single_quotes == 0)
		in_single_quotes = e_true;
	else if (c == '\'' && in_single_quotes == e_true)
		in_single_quotes = e_false;
	if (in_quotes == e_true || in_single_quotes == e_true)
		return (e_true);
	return (e_false);
}

char	*split_strcpy(char *str, int *j)
{
	int		i;
	int		k;
	int		is_in_quotes;

	is_in_quotes = e_false;
	if (str[0] == '\'' || str[0] == '"')
		is_in_quotes = e_true;
	else if (str[0] == ' ')
	{
		*j += 1;
		return (split_strcpy(str + 1, j));
	}
	i = 0;
	while (str[i] && in_or_out(str[i], e_false) == is_in_quotes
		&& !(is_in_quotes == e_false && str[i] == ' '))
		++i;
	if (((str[i] == '\'' || str[i] == '"') && is_in_quotes == e_true)
		|| str[i] == ' ')
		++i;
	if (str[i] == ' ' && str[i - 1] != ' ')
		++i;
	*j += i;
	in_or_out(0, e_true);
	return (ft_strcpy(NULL, str, i));
}

int	count_chunks(char *str)
{
	int		i;
	int		is_in_quotes;
	int		was_in_quotes;
	int		lines;

	lines = 1;
	was_in_quotes = e_false;
	if (str[0] == '\'' || str[0] == '"')
		was_in_quotes = e_true;
	i = 0;
	while (str[i])
	{
		is_in_quotes = in_or_out(str[i], e_false);
		if (str[i + 1] && (is_in_quotes != was_in_quotes
				|| (is_in_quotes == e_false
					&& str[i] == ' ' && str[i + 1] != ' '
					&& str[i + 1] != '\'' && str[i + 1] != '"'
					&& i > 0 && str[i - 1] != '\'' && str[i - 1] != '"')))
			++lines;
		was_in_quotes = is_in_quotes;
		++i;
	}
	in_or_out(0, e_true);
	return (lines);
}

char	**cc_split(char *str)
{
	int		i;
	int		j;
	int		lines;
	char	**split;

	if (!str)
		return (NULL);
	lines = count_chunks(str);
	split = ft_malloc(sizeof(char *) * (lines + 1));
	split[lines] = 0;
	i = 0;
	j = 0;
	while (i < lines)
	{
		split[i] = split_strcpy(&str[j], &j);
		++i;
	}
	return (split);
}
