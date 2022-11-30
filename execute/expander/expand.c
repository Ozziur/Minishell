/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:14:06 by ccantale          #+#    #+#             */
/*   Updated: 2022/11/30 17:49:00 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expander.h"

/*
** This function is the one to call to expand any
** string, from wherever in the code.
*/
char	*expand(char *to_expand, t_bool free_original)
{
	char	**to_expand_split;
	char	*expanded;
	int		i;

	if (!to_expand)
		return (NULL);
	if (not_to_expand(to_expand) == e_true)
		return (to_expand);
	to_expand_split = dp_split(to_expand, ' ');
	i = -1;
	while (to_expand_split[++i])
		expanded = ft_strjoin(ft_strjoin(
					expanded, " ", e_true, e_false),
				expand_rec(to_expand_split[i], e_NORMAL), e_true, e_true);
	ft_splitclear(to_expand_split);
	if (free_original == e_true)
		ft_free(to_expand);
	if (!*expanded)
	{
		ft_free(expanded);
		return (NULL);
	}
	return (trim_first_last_char(expanded));
}

char	*expand_rec(char *to_expand, t_exp_phase phase)
{	
	char	*rest_of_str;

	if (to_expand == NULL || *to_expand == 0)
	{	
		ft_free(to_expand);
		return (ft_strdup(""));
	}
	rest_of_str = isolate_first_segment(to_expand, phase);
	return (ft_strjoin(
			expand_segment(to_expand, phase),
			expand_rec(rest_of_str, phase),
			e_true, e_true));
}

char	*isolate_first_segment(char *to_expand, t_exp_phase phase)
{
	int		i;
	char	*rest_of_str;

	rest_of_str = NULL;
	i = 0;
	while (to_expand[i])
	{
		if (is_char_to_expand(to_expand[i], e_NORMAL)
			|| is_char_to_expand(to_expand[i], e_STAR))
		{
			if (i > 0)
				rest_of_str = to_expand + i;
			else
				rest_of_str = isolate_macro(to_expand, to_expand[i]);
			break ;
		}
		++i;
	}
	if (rest_of_str != 0 && *rest_of_str == 0)
			rest_of_str = ft_strdup("");
	return (rest_of_str);
}

char	*isolate_macro(char *to_expand, char special)
{
	int	i;

	i = 1;
	while (to_expand[i])
	{
		if (special == '$' && to_expand[i] == '$'
			&& (to_expand[i + 1] == ' ' || !to_expand[i + 1]))
			return (to_expand + i + 1);
		else if (special == '$' && (to_expand[i] == ' '
				|| is_char_to_expand(to_expand[i], e_NORMAL)
				|| is_char_to_expand(to_expand[i], e_STAR)))
			return (to_expand + i);
		else if (special == '*' && (to_expand[i] == ' ' || !to_expand[i]))
			return (to_expand + i);
		else if (to_expand[i] == special)
			return (to_expand + i + 1);
		++i;
	}
	return (to_expand + i);
}
