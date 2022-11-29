#include "expander.h"

char	*expand_segment(char *seg, t_exp_phase phase)
{
	int	i;

	if (*seg == '$')
		return (expand_dollar(seg + 1));
	else if (*seg == '\'')
		return (expand_quotes(seg + 1, '\''));
	else if (*seg == '"')
		return (expand_quotes(seg + 1, '"'));
	else
	{
		i = 0;
		while (seg[i])
		{
			if (is_char_to_expand(seg[i], e_NORMAL))
				return (ft_strcpy(NULL, seg, i));
			else if (phase != e_QUOTES && is_char_to_expand(seg[i], e_STAR))
				return (expand_wildcard(seg));
			++i;
		}
		return (ft_strdup(seg));
	}
}

char	*expand_dollar(char *var)
{
	char	*env_var_name;
	char	*env_var_val;

	if (var[0] == ' ' || var[0] == '\0')
		return (ft_strdup("$"));
	else if (var[0] == '$')
		return (ft_itoa(g_env.pid));
	else if (var[0] == '?')
		return (ft_itoa(g_env.last_executed_cmd_exit_status));
	else if (var[0] == '"' || var[0] == '\'')
		return (ft_strdup(""));
	else
	{

		env_var_name = ft_strcpy(NULL, var, ft_word_len(var));
		env_var_val = ft_strdup(env_handler(BINDING_GET_VALUE, env_var_name));
		free(env_var_name);
		if (!env_var_val)
			return (ft_strdup(""));
		return (env_var_val);
	}
}

char	*expand_quotes(char *quoted_str, char type_of_quotes)
{
	char	*quotes_content;
	char	*new_content;
	
	if (type_of_quotes == '"')
	{
		quotes_content = ft_strcpy(
					NULL,
					quoted_str,
					scroll_to_char(quoted_str, '"'));
		new_content = carefully_expand_content(quotes_content);
		if (*quotes_content)
			free(quotes_content);
		return (new_content);
	}
	else
		return (ft_strcpy(NULL, quoted_str,
					scroll_to_char(quoted_str, '\'')));
}

/*
** If there's single quotes in it, the original double-quoted
** content is splitted into 3 chunks: the segment that precedes
** the single-quoted section, the single-quoted section itself
** and then the rest of the string. Each chunk is expanded indi-
** vidually. To split the chunks, the two ' characters are re-
** placed with 0s. The ' char are reattached to the sides of the
** second chunk after it's been expanded, so that the eventual
** env variables in it are regularily interpreted. Two " char
** are attached to the third chunk before it is expanded, so
** that the eventual single-quoted segments in it are correctly
** expanded.
** The +2 to chunks[2] is due to the absence of the two
** single quote characters in chunks[1]
*/
char	*carefully_expand_content(char *q_cont)
{
	int		single_quote_pos;
	char	*chunks[3];
	char	*care_fully_expanded_str;

	single_quote_pos = scroll_to_char(q_cont, '\'');
	if (single_quote_pos || q_cont[0] == '\'')
	{
		if (check_single_quotes_nbr(q_cont))
			return (ft_strcpy(NULL, q_cont, ft_strlen(q_cont)));
		chunks[0] = ft_strcpy(NULL, q_cont, single_quote_pos);
		chunks[1] = ft_strcpy(NULL, q_cont + single_quote_pos + 1,
				scroll_to_char(q_cont + single_quote_pos + 1, '\''));
		chunks[2] = q_cont + ft_strlen(chunks[0]) + ft_strlen(chunks[1]) + 2;
		printf("\nstringa = %s", q_cont);
		printf("\nsingle_quote_pos = %d\n0 = %s\n1 = %s\n2 = %s\n\n", single_quote_pos, chunks[0], chunks[1], chunks[2]);
		care_fully_expanded_str = ft_strjoin_a_trois(
				expand_rec(chunks[0], e_QUOTES),
				single_quote(expand_rec(chunks[1], e_QUOTES), e_true),
				expand_rec(quote(chunks[2], e_false), e_QUOTES),
				e_true, e_true, e_true);
		if (q_cont[0] != '\'')
			free(chunks[0]);
		free(chunks[1]);
		return (care_fully_expanded_str);
	}
	else
		return (expand_rec(q_cont, e_QUOTES));
}

int	check_single_quotes_nbr(char *q_cont)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (q_cont[i])
	{
		if (q_cont[i] == '\'')
			++count;
		++i;
	}
	if (count % 2 == 0)
		return (0);
	else
		return (1);
}
