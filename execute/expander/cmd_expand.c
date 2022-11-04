#include "expander.h"

void	cmd_expand(t_simple_command_node *cmd)
{
	cmd->cmd_name = expand(cmd->cmd_name);
	cmd->cmd_args = sexpand(cmd->cmd_args);
	// si dovrebbe richiamare ricorsivamente finché non trova più
	// niente da espandere

	// qui c'è un while loop che va capito

}

char	*expand_rec(char *to_expand)
{
	char	*rest_of_str;
	char	*exp_str;

	if (to_expand == 0)
		return (NULL);
	rest_of_str = 0;
	isolate_first_segment(to_expand, rest_of_str);
	return (ft_strjoin(
				expand_segment(to_expand, rest_of_str),
				expand_rec(rest_of_str),
				e_true, e_true
			));
}

void	isolate_first_segment(char *to_expand, char *rest_of_str)
{
	int	i;

	i = 0;
	while (to_expand[i])
	{
		if (is_special_char(to_expand[i]))
		{
			if (i > 0)
				rest_of_str = to_expand + i - 1;
			else
				isolate_macro(to_expand + i, rest_of_str);
			break ;
		}
		++i;
	}
}

void	isolate_macro(char *to_expand, char *rest_of_str)
{
	int	i;
	char	special;

	special = *to_expand;
	i = 0;
	while (to_expand[i])
	{
		if ((special == '$' || special == '*') && to_expand[i] == ' ')
			rest_of_str = to_expand + i;
		else if (to_expand[i] == special)
			rest_of_str = to_expand + i + 1;
		if (rest_of_str != 0)
			break;
		++i;
	}
	if (rest_of_str == 0)
		//ERROR
}

int	is_special_char(char *c)
{
	return (c == '\"' || c == '\'' || c == '$' || c == '*')
}
