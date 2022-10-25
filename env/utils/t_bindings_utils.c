/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_bindings_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 17:02:43 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/25 18:37:06 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env_utils.h"

size_t	env_size(t_bindings *env);
//* end of static declarations

char	**bindings_list_to_array(t_bindings *env)
{
	int		i;
	char	**array;

	array = ft_malloc(sizeof(char *) * (env_size(env) + 1));
	i = 0;
	while (env)
	{
		array[i] = ft_strjoin(
				ft_strjoin(env->var_name, "=", e_false, e_false),
				env->var_val, e_true, e_false);
		++i;
		env = env->next;
	}
	array[i] = NULL;
	return (array);
}

size_t	env_size(t_bindings *env)
{
	size_t	i;

	i = 0;
	while (env)
	{
		env = env->next;
		++i;
	}
	return (i);
}
