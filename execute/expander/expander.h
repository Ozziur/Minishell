#ifndef EXPANDER_H
# define EXPANDER_H

# include "../execute.h"

void	cmd_expand(t_simple_cmd_node *cmd);
char	*check_expansion(char *expanded_str);
char	*expand_rec(char *to_expand);
char	*isolate_first_segment(char *to_expand, char *rest_of_str);
char	*isolate_macro(char *to_expand, char *rest_of_str, char special);
int	is_special_char(char c);
char	*expand_segment(char *seg);
char	*expand_dollar(char *var);
char	*expand_quotes(char *quoted_str, char type_of_quotes);
char	*rm_internal_double_quotes(char *quotes_content);
char	*carefully_expand_content(char *q_cont);
char	*expand_in_chunks(char *q_cont, int *i, int after_last_quote);

#endif 

