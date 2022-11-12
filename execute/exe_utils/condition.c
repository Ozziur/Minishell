/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   condition.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mruizzo <mruizzo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:33:29 by mruizzo           #+#    #+#             */
/*   Updated: 2022/11/12 19:36:49 by mruizzo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../execute.h"

t_bool	is_builtin(t_tree_node *root)
{
	t_bool	is_builtin;
	char	*simple_name;

	if (root->content->content_type != SIMPL_CMD)
		return (e_true);
		//da creare o meglio da completare
}