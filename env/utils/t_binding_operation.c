/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_binding_operation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 12:49:05 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/07 14:24:43 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

t_bindings	*binding_over_write(t_bindings *head, t_bindings *binding)
{
	t_bindings	*cursor;
	char		*new_val;

	new_val =ft_strdup(binding->var_val);
	cursor = head;
	while (cursor)
	{
		if (ft_strcmp(cursor->var_val, binding->var_name) == 0)
		{
			if (binding->concat_mode ==e_true)
				cursor->var_val = ft_strjoin(cursor->var_val, new_val, e_true, e_true);
			else
				ft_str_replace(&cursor->var_val, new_val);
			break ;
		}
		cursor = cursor->next;
	}
	free(new_val);
	return (cursor);
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
