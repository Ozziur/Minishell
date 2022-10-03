/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:55:42 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 16:00:39 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZE_H
# define TOKENIZE_H


// * standard libraries //
# include <stdlib.h>

void	free_token_list(t_token **list);
void	free_tokens(t_token *token);
void	free_token_val(t_token *token);
void	free_env(t_bindings *head);

#endif
