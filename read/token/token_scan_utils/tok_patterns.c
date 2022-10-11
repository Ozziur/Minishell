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
