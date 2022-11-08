/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tok_patterns.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 16:39:34 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/11 17:35:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../tokenize.h"

size_t	scan_env_declaration(char *str, size_t offset, t_token **token_list)
{
	size_t		new_offset;
	t_token		*token;
	t_bindings	*next_var;

	new_offset = scan_initial_keyword_set_token(str, offset, &token);
	new_offset = scan_invariants(str, new_offset);
	while (e_true)
	{
		next_var = NULL;
		// new_offset = scan_redirs(str, new_offset, token_list);
		new_offset = scan_var(str, new_offset, token->token_id, &next_var);//da creare
		if (!next_var)
			break ;
		else if (str[new_offset]
			&& bash_control_character(str[new_offset] == e_false))
			return (scan_env_revert(token, offset));//da creare
		else
			env_tok_add_new_binding(&token, next_var);// da creare
	}
	if (token->token_id == e_ENV_VAR_DECL && token->token_val == NULL)
		return (scan_env_revert(token, token_list));
	tok_add_back(token_list, token);//env_dec_add_token sostituito da questa funzione
	return (new_offset);	
}

size_t	scan_simple_command(char *cmd_line, size_t offset,
	t_token **tok_list_ref)
{
	t_token	*token;
	int		len_cmd_name;
	//t_bool	repeat;

	if (!cmd_line[offset])
		return (offset);
	len_cmd_name = bash_next_string_len(cmd_line, offset);
	if (len_cmd_name == 0)
		return (offset);
	token = (t_token *) malloc(sizeof(t_token));
	token->token_id = e_CMD_NAME;
	token->token_val = ft_strcpy(NULL, cmd_line + offset, len_cmd_name);
	offset += len_cmd_name;
	//offset = scan_redirs(command_line, offset, token_list);
	offset = scan_cmd_arg(cmd_line, offset, tok_list_ref);
	tok_add_back(tok_list_ref, token);
	return (offset);
}
