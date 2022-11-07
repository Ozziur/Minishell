/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_binding_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/07 14:12:05 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

t_bindings	*binding_over_write(t_bindings *head, t_bindings *binding)
{
	
}

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
