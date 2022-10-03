/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_stuff.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:55:36 by mruizzo           #+#    #+#             */
/*   Updated: 2022/10/03 17:09:38 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_STUFF_H
# define TOKEN_STUFF_H

# include "token_struct.h"

void	tokenizer_free(void);
t_token	*next_token(void);

#endif