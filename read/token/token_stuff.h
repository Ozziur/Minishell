/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:19 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/12 16:07:09 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STUFF_H
# define TOKEN_STUFF_H

# include "token_struct.h"
# include "tok_utils/tok_utils.h"

void	lunch_tokenizer(char *command_line);
void	tokenizer_free(void);
t_token	*next_token(void);
void	free_token_list(t_token **list);
void	free_tokens(t_token *token);
void	free_token_val(t_token *token);
//void	free_env(t_bindings *head);
size_t	scan_brackets(char *cmd_line, size_t cursor, t_token **token_list);
size_t	scan_next_bracket(char *cmd_line, size_t cursor, t_token **token_list);
size_t	scan_invariants(char *str, size_t offset);
size_t	scan_spaces(char *str, size_t offset);
size_t	scan_inv_quotes(char *str, size_t offset);
size_t	scan_simple_command(char *cmd_line, size_t offset,
			t_token **tok_list_ref);
size_t	scan_next_arg(char *cmd_line, size_t offset,
			char **cur_arg_str, t_token **tok_list);
size_t	scan_cmd_arg(char *cmd_line, size_t offset, t_token **tok_list_ref);
void	free_token_list(t_token **list);
void	scan(char *cmd_line, t_token **tok_list_ref);
size_t	scan_env_declaration(char *str, size_t offset, t_token **token_list);
size_t	scan_initial_keyword_set_token(char *str, size_t offset,
			t_token **token);
size_t	scan_var(char *str, size_t offset,
			t_token_id tok_type, t_bindings **next_var);
size_t	scan_var_name(char *str, size_t offset, char **name);

#endif
