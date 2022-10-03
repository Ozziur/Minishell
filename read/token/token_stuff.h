/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:55:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:20:36 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STUFF_H
# define TOKEN_STUFF_H

# include "token_struct.h"

void	tokenizer_free(void);
t_token	*next_token(void);
void	free_token_list(t_token **list);
void	free_tokens(t_token *token);
void	free_token_val(t_token *token);
void	free_env(t_bindings *head);


# endif
