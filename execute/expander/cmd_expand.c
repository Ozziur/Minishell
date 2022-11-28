#include "expander.h"

void	cmd_expand(t_simple_cmd_node *cmd)
{
	if (!cmd->cmd_name)
	{
		return ;
	}
	cmd->cmd_name = expand(cmd->cmd_name, e_true);
	cmd->cmd_args = expand(cmd->cmd_args, e_true);
}

/*
** This function is the one to call to expand any
** string, from wherever in the code.
*/
char	*expand(char *to_expand, t_bool free_original)
{
	char	*expanded;

	if (!to_expand)
		return (NULL);
	expanded = expand_rec(to_expand, e_NORMAL);
	if (free_original == e_true)
		ft_free(to_expand);
	if (!*expanded)
	{
		ft_free(expanded);
		return (NULL);
	}
	return (expanded);
}

char	*expand_rec(char *to_expand, t_exp_phase phase)
{	
	char	*rest_of_str;

	if (to_expand == 0 || *to_expand == 0)
	{	ft_free(to_expand);
		return (ft_strdup(""));
	}
	rest_of_str = isolate_first_segment(to_expand, phase);
	return (ft_strjoin(
				expand_segment(to_expand, phase),
				expand_rec(rest_of_str, phase),
				e_true, e_true
			));
}

char	*isolate_first_segment(char *to_expand, t_exp_phase phase)
{
	int		i;
	char	*rest_of_str;

	rest_of_str = NULL;
	i = 0;
	while (to_expand[i])
	{
		if (is_char_to_expand(to_expand[i], phase))
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
		if (special == '$' && (to_expand[i] == ' ' || to_expand[0] == 0))
			return (to_expand + i);
		else if (special == '$' && to_expand[i] == '$')
			return (to_expand + i + 1);
		else if (to_expand[i] == special)
			return (to_expand + i + 1);
		++i;
	}
	return (to_expand + i);
}

int	is_char_to_expand(char c, t_exp_phase type)
{
	if (type == e_NORMAL || type == e_QUOTES)
		return (c == '"' || c == '\'' || c == '$');
	else if (type == e_STAR)
		return (c == '*');
	return (0);
}
