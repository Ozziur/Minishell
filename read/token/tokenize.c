/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:54:45 by mruizzo           #+#    #+#             */
/*   Updated: 2022/09/21 18:02:29 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tokenize.h"

void	lunch_tokenizer(char *command_line)
{
	if (command_line == NULL)
		return ;
	tokenizer (NULL, e_CLEAN);              // CONTROLLA TIPI 
	tokenizer (command_line, e_READ_INPUT)  // CONTROLLA TIPI 
}
