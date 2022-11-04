#ifndef EXPANDER_H
# define EXPANDER_H

void	cmd_expand(t_simple_command_node *cmd);
char	*expand_rec(char *to_expand);
void	isolate_first_segment(char *to_expand, char *rest_of_str);
void	isolate_macro(char *to_expand, char *rest_of_str);
int	is_special_char(char *c);

#endif 

