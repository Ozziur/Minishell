/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_add_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:11:40 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/09 18:39:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../read/token/token_struct.h"
#include "../utils.h"

void	token_add_back(t_token **list, t_token *new_token)
{
	static t_token	*last = NULL;

	if (!*list)
		*list = new_token;
	else
		last->next = new_token;
	last = new_token;
	last->next = NULL;
}
