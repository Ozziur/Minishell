/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:30:19 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/07 16:41:26 by mruizzo          ###   ########.fr       */
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
//void	free_env(t_bindings *head);
size_t	scan_invariants(char *str, size_t offset);
size_t	scan_sapaes(char *str, size_t offset);
size_t	scan_inv_quotes(char *str, size_t offset);

#endif
