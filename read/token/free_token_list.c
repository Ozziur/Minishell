/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_token_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 15:43:46 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/03 16:02:34 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	free_token_list(t_token **list)
{
	if (*list)
	{
		free_tokens(*list);
		*list = NULL;
	}
}

void	free_tokens(t_token *token)
{
	if (token->next)
		free_tokens(token->next);
	//free_token_val(token);
	free(token);
}

/*void	free_token_val(t_token *token)
{
	if (token->token_id == e_CMD_NAME
		|| token->token_id == e_CMD_ARG
		|| token->token_id == e_OUT_FILE_APPEND
		|| token->token_id == e_OUT_FILE_TRUNC
		|| token->token_id == e_IN_FILE_TRUNC
		|| token->token_id == e_HERE_DOC)
		free(token->token_val);
	if (token->token_id == e_ENV_VAR_DECL
		|| token->token_id == e_ENV_VAR_UNSET)
		free_env(token->token_val);
}

void	free_env(t_bindings *head)
{
	if (!head)
		return ;
	fre_env(head->next);
	free(head->var_name);
	free(head->var_val);
	free(head);
}*/
