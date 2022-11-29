#include "expander.h"

void	cmd_expand(t_simple_cmd_node *cmd)
{
	int	experiment;
	char *tmp;

	experiment = 0;
	if (find_dollar(cmd->cmd_name) == e_true)
		experiment = 1;
	cmd->cmd_name = expand(cmd->cmd_name, e_true);
	cmd->cmd_args = expand(cmd->cmd_args, e_true);
	if (experiment)
	{
		tmp = ft_strdup(cmd->cmd_name);
		free(cmd->cmd_name);
		cmd->cmd_name = ft_strdup(justice(tmp, e_true));
		cmd->cmd_args = ft_strjoin(justice(tmp, e_false),
				cmd->cmd_args,e_false,e_true);
		free(tmp);
	}

}

static t_bool	not_to_expand(char *to_expand)
{
	int i = 0;
	while(to_expand[i])
	{
		if (to_expand[i]=='$' ||
		to_expand[i]== '\'' ||
		to_expand[i] =='\"')
			return (e_false);
		i++;
	}
	return (e_true);
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
	if (not_to_expand(to_expand) == e_true)
		return (to_expand);
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

	if (to_expand == NULL || *to_expand == 0)
	{	
		ft_free(to_expand);
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
		if (special == '$' && to_expand[i] == '$'
				&& (to_expand[i + 1] == ' ' || to_expand[i + 1] == '\0'))
			return (to_expand + i + 1);
		else if (special == '$' && (to_expand[i] == ' '
				|| is_char_to_expand(to_expand[i], e_NORMAL)
				|| is_char_to_expand(to_expand[i], e_STAR)))
			return (to_expand + i);
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
