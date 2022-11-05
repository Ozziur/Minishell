#include "expander.h"

static char	*la_vergognosa(char *q_cont, int single_quote_pos);
static char	*la_vergognosissima(
		char *first_chunk, char *second_chunk, char *third_chunk);
/////// embarassing static declaration //////////////////////

char	*expand_segment(char *seg)
{
	int	i;

	if (*seg == '$')
		return (expand_dollar(seg + 1));
	if (*seg == '*')
		return (ft_strdup("")); //wildcards da fare
	else if (*seg == '\'')
		return (expand_quotes(seg + 1, '\''));
	else if (*seg == '"')
		return (expand_quotes(seg + 1, '"'));
	else
	{
		i = 0;
		while (seg[i])
		{
			if (is_special_char(seg[i]))
				return (ft_strcpy(NULL, seg, i));
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
	else if (var[0] == '"')
		return (expand_dollar(var + 1));
	else if (var[0] == '\'')
		return (expand_quotes(var + 1, '\''));
	else if (var[0] == '*')
		return(ft_strdup("\n")); //da fare meglio
	else
	{

		env_var_name = ft_strcpy(NULL, var, ft_word_len(var));
		env_var_val = env_handler(BINDING_GET_VALUE, env_var_name);
		free(env_var_name);
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
		return (new_content);
	}
	else
		return (ft_strcpy(NULL, quoted_str,
					scroll_to_char(quoted_str, '\'')));
}

/*
** The +2 to third_chunk is due to the subsequent addition of 
** the two ' to second_chunk
*/
char	*carefully_expand_content(char *q_cont)
{
	int	single_quote_pos;
	char	*first_chunk;
	char	*second_chunk;
	char	*third_chunk;
	char	*care_fully_expanded_str;

	single_quote_pos = scroll_to_char(q_cont, '\'');
	if (single_quote_pos || q_cont[0] == '\'')
	{
		first_chunk = la_vergognosa(q_cont, single_quote_pos);
		second_chunk = ft_strcpy(NULL,
			q_cont + single_quote_pos + 1,
			scroll_to_char(q_cont + single_quote_pos + 1, '\''));
		third_chunk = q_cont
			+ ft_strlen(first_chunk) + ft_strlen(second_chunk) + 2;
		care_fully_expanded_str = la_vergognosissima(
						first_chunk,
						second_chunk,
						third_chunk);
		free(first_chunk);
		free(second_chunk);
		return (care_fully_expanded_str);
	}
	else
		return (expand_rec(q_cont));
}

static char	*la_vergognosissima(
		char *first_chunk, char *second_chunk, char *third_chunk)
{
	return (ft_strjoin_a_trois(
			expand_rec(first_chunk),
			ft_strjoin_a_trois(
				"\'", expand_rec(second_chunk), "\'",
				e_false, e_true, e_false),
			expand_rec(ft_strjoin_a_trois(
				"\"", third_chunk, "\"",
				e_false, e_false, e_false)),
			e_true, e_true, e_true)
		);
}

static char	*la_vergognosa(char *q_cont, int single_quote_pos)
{
	if (q_cont[0] == '\'')
		return (ft_strdup(""));
	else
		return (ft_strcpy(NULL, q_cont, single_quote_pos));
}
