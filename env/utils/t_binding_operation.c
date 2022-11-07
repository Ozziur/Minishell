/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_binding_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/07 12:59:17 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

char	*binding_get_value(t_bindings *head, char *name)
{
	t_bindings	*cursor;

	cursor = head;
	while (cursor)
	{
		if (ft_strcmp(cursor->var_name, name))
			return (cursor->var_val);
		cursor = cursor->next;
	}
	return (NULL);
}
