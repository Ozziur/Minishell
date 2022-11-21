#ifndef EXPANDER_H
# define EXPANDER_H

# include "../execute.h"

typedef enum e_exp_phase
{
	e_QUOTES_DOLLAR,
	e_STAR
}	t_exp_phase;

void	cmd_expand(t_simple_cmd_node *cmd);
char	*check_expansion(char *expanded_str);
char	*expand(char *to_expand, t_bool free_original);
char	*expand_quotes_dollar(char *to_expand);
char	*isolate_first_segment(char *to_expand, char *rest_of_str);
char	*isolate_macro(char *to_expand, char *rest_of_str, char special);
int	is_char_to_expand(char c, t_exp_phase);
t_bool	check_for_stars(char *str);
char	*expand_segment(char *seg);
char	*expand_dollar(char *var);
char	*expand_quotes(char *quoted_str, char type_of_quotes);
char	*carefully_expand_content(char *q_cont);
char	*expand_in_chunks(char *q_cont, int *i, int after_last_quote);

#endif 

