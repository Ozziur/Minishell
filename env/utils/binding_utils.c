/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binding_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:58:41 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/25 17:15:57 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "binding_utils.h"

t_bindings	*get_new_binding(char *var_name, char *var_val, t_bool concat)
{
	t_bindings *new_binding;

	new_binding = (t_bindings *) ft_malloc(sizeof(t_bindings));
	new_binding->var_name = ft_strdup(var_name);
	new_binding->var->val = ft_strdup(var_val);
	new_binding->concat_mode = concat;
	new_binding->prev = NULL;
	new_binding->next = NULL;
	return (new_binding);
}
