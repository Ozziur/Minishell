#ifndef EXPANDER_H
# define EXPANDER_H

# include "../execute.h"
# include <sys/types.h>
# include <dirent.h>

typedef enum e_exp_phase
{
	e_NORMAL,
	e_QUOTES,
	e_STAR
}	t_exp_phase;

void	cmd_expand(t_simple_cmd_node *cmd);
char	*check_expansion(char *expanded_str);
char	*expand(char *to_expand, t_bool free_original);
char	*expand_rec(char *to_expand, t_exp_phase phase);
char	*isolate_first_segment(char *to_expand, t_exp_phase phase);
char	*isolate_macro(char *to_expand, char special);
int		is_char_to_expand(char c, t_exp_phase);
t_bool	check_for_stars(char *str);
char	*expand_segment(char *seg, t_exp_phase phase);
char	*expand_dollar(char *var);
char	*expand_quotes(char *quoted_str, char type_of_quotes);
char	*carefully_expand_content(char *q_cont);
char	*expand_in_chunks(char *q_cont, int *i, int after_last_quote);
char	*expand_wildcard(char *path);
char	*get_prefix(char *path, t_bool allocate);
t_bool	check_star_placement(char *str);
char	*get_dir_content(char *dir_path);
char	*match(char *path, char *dir_content);
char	*find_match(char *dir_content, char *path, int *i);
t_bool	wild_strcmp(char *dir_content, char *to_expand, int prev_cursor);
char	*join_till_space(char *s1, char *s2, t_bool free1, t_bool free2);
char	*trim_first_char(char *str);
char	*remove_invisibles(char *dir_content);
int		check_single_quotes_nbr(char *q_cont);
t_bool	not_to_expand(char *to_expand);

#endif 

