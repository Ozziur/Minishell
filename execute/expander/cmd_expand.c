#include "expander.h"

void	cmd_expand(t_simple_cmd_node *cmd)
{
	if (!cmd->cmd_name)
	{
		// sig_handling_set(SIG_AT_EXIT);
		// exit(0);
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
	char	*phase_one;
	char	*phase_two;

	phase_one = expand_rec(to_expand, e_QUOTES_DOLLAR);
	//phase_two = expand_rec(phase_one, e_STAR);
	//free(phase_one);
	if (free_original == e_true)
		ft_free(to_expand);
	if (!*phase_one)
	{
		free(phase_one);
		return (NULL);
	}
	return (phase_one);
}

char	*expand_rec(char *to_expand, t_exp_phase phase)
{	
	char	*rest_of_str;

	if (to_expand == 0 || *to_expand == 0)
	{
		return (ft_strdup(""));
	}
	rest_of_str = 0;
	rest_of_str = isolate_first_segment(to_expand, rest_of_str, phase);
	return (ft_strjoin(
				expand_segment(to_expand),
				expand_rec(rest_of_str, phase),
				e_true, e_true
			));
}

char	*isolate_first_segment(char *to_expand, char *rest_of_str,
															t_exp_phase phase)
{
	int	i;

	i = 0;
	while (to_expand[i])
	{
		if (is_char_to_expand(to_expand[i], phase))
		{
			if (phase == e_QUOTES_DOLLAR && i > 0)
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
	int	found_space;

	found_space = -1;
	i = 0;
	while (to_expand[i])
	{
		if (to_expand[i] == ' ')
			found_space = i;
		if (special == '*' && found_space == -1 && to_expand[i] == ' ')
			return (to_expand + i);
		else if (special == '*' && found_space >= 0) 
			return (to_expand + found_space + 1);
		else if (special == '$' && to_expand[i] == ' ')
			return (to_expand + i);
		else if (to_expand[i] == special && i > 0)
			return (to_expand + i + 1);
		if (rest_of_str != 0)
			break;
		++i;
	}
	return (to_expand + i);
}

int	is_char_to_expand(char c, t_exp_phase phase)
{
	if (phase == e_QUOTES_DOLLAR)
		return (c == '"' || c == '\'' || c == '$');
	else if (phase == e_STAR)
		return (c == '*');
	return (0);
}
