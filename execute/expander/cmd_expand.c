#include "expander.h"

void	cmd_expand(t_simple_cmd_node *cmd)
{
	char	*new_cmd_name;
	char	*new_cmd_args;

	if (!cmd->cmd_name)
	{
		sig_handling_set(SIG_AT_EXIT);
		exit(0);
	}
	new_cmd_name = expand_rec(cmd->cmd_name);
	new_cmd_args = expand_rec(cmd->cmd_args);

	// qui c'è un while loop che mi devo vedere
	
	free(cmd->cmd_name);
	free(cmd->cmd_args);
	cmd->cmd_name = check_expansion(new_cmd_name);
	cmd->cmd_args = check_expansion(new_cmd_args);
}

char	*check_expansion(char *expanded_str)
{
	if (!*expanded_str)
	{
		free(expanded_str);
		return (NULL);
	}
	return (expanded_str);
}

/*
** The return of expand_rec is always allocated.
*/
char	*expand_rec(char *to_expand)
{	
	char	*rest_of_str;

	if (to_expand == 0 || *to_expand == 0)
	{
		ft_free(to_expand);
		return (ft_strdup(""));
	}
	rest_of_str = 0;
	rest_of_str = isolate_first_segment(to_expand, rest_of_str);
	return (ft_strjoin(
				expand_segment(to_expand),
				expand_rec(rest_of_str),
				e_true, e_true
			));
}

char	*isolate_first_segment(char *to_expand, char *rest_of_str)
{
	int	i;

	i = 0;
	while (to_expand[i])
	{
		if (is_special_char(to_expand[i]))
		{
			if (i > 0)
				rest_of_str = to_expand + i;
			else
				rest_of_str = isolate_macro(
							to_expand,
							rest_of_str,
							to_expand[i]
							);
			break ;
		}
		++i;
	}
	if (rest_of_str != 0 && *rest_of_str == 0)
		rest_of_str = ft_strdup("");
	return (rest_of_str);
}

char	*isolate_macro(char *to_expand, char *rest_of_str, char special)
{
	int	i;

	i = 0;
	while (to_expand[i])
	{
		if ((special == '$' || special == '*') && to_expand[i] == ' ')
			return (to_expand + i);
		else if (to_expand[i] == special && i > 0)
			return (to_expand + i + 1);
		if (rest_of_str != 0)
			break;
		++i;
	}
	return (to_expand + i);
}

int	is_special_char(char c)
{
	return (c == '"' || c == '\'' || c == '$' || c == '*');
}
