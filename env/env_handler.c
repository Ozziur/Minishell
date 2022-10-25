/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccantale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 18:10:47 by ccantale          #+#    #+#             */
/*   Updated: 2022/10/25 16:14:50 by ccantale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

static void	*env_return_cases(t_bindings *env, t_bindings *export,
					t_env_handl_opcode opcode);
static void	*env_management_cases(t_bindings **env_ref, t_bindings **export_ref,
					t_env_handl_opcode opcode, void *argument);
//* end of static declarations

void	*env_handler(t_env_handl_opcode opcode, void *argument)
{
	static t_bindings	*env;
	static t_bindings	*export;

	if (opcode == ENV_INITIALIZE
			|| opcode == ENV_CLEAN)
	{
		env_management_cases(&env, &export, opcode, argument);
	}
	if (opcode == ENV_RETURN
			|| opcode == EXPORT_RETURN
			|| opcode == ENV_LIST_TO_ARRAY)
	{
		return(env_return_cases(env, export, opcode));
	}
	/*if (opcode == BINDING_UPDATE
			|| opcode == BINDING_UNSET
			|| opcode == BINDING_GET_VALUE)
	{
		return (env_operations_cases(&env, &export, opcode, argument));
	}
	if (opcode == _PRINT_ENV_)
	{
		return (debug_cases(env, export, opcode, argument));
	}*/
	return (NULL);
}

static void	*env_return_cases(t_bindings *env, t_bindings *export,
					t_env_handl_opcode opcode)
{
	if (opcode == ENV_RETURN)
	{
		return (env);
	}
	else if (opcode == EXPORT_RETURN)
	{
		return (export);
	}
	else if (opcode == ENV_LIST_TO_ARRAY)
	{
		return ((void *)bindings_list_to_array(env));
	}
	return (NULL);
}

static void	*env_management_cases(t_bindings **env_ref, t_bindings **export_ref,
					t_env_handl_opcode opcode, void *argument)
{
	if (opcode == ENV_INITIALIZE)
	{
		copy_env(argument);	
	}
	else if (opcode == ENV_CLEAN)
	{
		free_env(*env_ref);
		free_env(*export_ref);
		*env_ref = NULL;
		*export_ref = NULL;
	}
}
